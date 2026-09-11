/*
This program tracks activity across consecutive days. The user sets a
positive whole-number daily step goal at the start, then chooses light,
moderate or fast walking for each day. A day can contain multiple entries,
entered as steps, kilometres or walking minutes.

The fixed conversion rates are 1,250 steps per kilometre, 100 steps per
walking minute and 40 calories per 1,000 steps. Moderate walking increases
estimated calories by 10%; fast walking increases them by 20%. The selected
intensity applies to every entry for that day. Converted step equivalents
retain fractional parts, while directly entered steps must be whole numbers.

After every valid entry, the program displays its conversions and the day's
cumulative progress towards the goal. Progress can exceed 100%. The user
can add another entry for today, start the next day or finish tracking.

The final summary shows steps, kilometres, adjusted calories and goal
progress for each recorded day. It also shows overall totals, the number
of days tracked, entry counts for all three input types, the number of days
meeting the goal and the longest consecutive streak of successful days.
Distances, calories, converted steps and percentages use two decimal places.

All numeric inputs must be positive. Invalid numbers, menu choices and
yes/no answers are rejected and re-prompted without changing recorded data.
Input is read as complete lines to reject extra text and oversized inputs.
Functions, structures and a dynamically growing array organise the program.
If input ends or memory cannot be expanded, recorded activity is summarised
and allocated memory is released. No empty day is added to the summary.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>

enum
{
    input_buffer_size = 256,
    activity_type_count = 3
};
enum
{
    input_closed = 0,
    input_valid = 1,
    input_too_long = 2
};
enum
{
    entry_limit_reached = -1,
    entry_invalid = 0,
    entry_recorded = 1
};

// These constants are shared by the conversion and reporting functions.
static const double steps_per_km = 1250.0;
static const double steps_per_walking_minute = 100.0;
static const double steps_per_calorie_rate = 1000.0;
static const double calories_per_1000_steps = 40.0;

typedef struct
{
    double steps;
    double calories;
    int intensity_choice;
    size_t entry_counts[activity_type_count];
} day_record;

typedef struct
{
    day_record *days;
    size_t day_count;
    size_t day_capacity;
    double total_steps;
    double total_calories;
    size_t entry_counts[activity_type_count];
} activity_tracker;

// Read a complete line and discard an oversized line before the next prompt.
static int read_line(const char *prompt, char buffer[input_buffer_size])
{
    printf("%s", prompt);
    fflush(stdout);

    if (fgets(buffer, input_buffer_size, stdin) == NULL)
    {
        return input_closed;
    }

    char *newline = strchr(buffer, '\n');

    if (newline != NULL)
    {
        *newline = '\0';
    }
    else if (!feof(stdin))
    {
        int input_character;

        while ((input_character = getchar()) != '\n' && input_character != EOF)
        {
            // Discard the remainder so it cannot become the next answer.
        }

        printf("Input is too long. Please enter a shorter value.\n");
        return input_too_long;
    }

    return input_valid;
}

// Validate either a decimal number or a base-10 integer, including its range.
static int read_number(const char *prompt, double minimum, double maximum,
                       int whole_number_only, double *result)
{
    char buffer[input_buffer_size];

    for (;;)
    {
        int input_status = read_line(prompt, buffer);

        if (input_status == input_closed)
        {
            return 0;
        }

        if (input_status == input_too_long)
        {
            continue;
        }

        char *end;
        double value;
        errno = 0;

        if (whole_number_only)
        {
            // strtol checks integer overflow before any conversion to int.
            long integer_value = strtol(buffer, &end, 10);
            value = (double)integer_value;
        }
        else
        {
            value = strtod(buffer, &end);
        }

        int number_was_read = end != buffer;

        while (isspace((unsigned char)*end))
        {
            end++;
        }

        if (number_was_read && *end == '\0' && errno != ERANGE &&
            isfinite(value) && value > 0.0 && value >= minimum && value <= maximum)
        {
            *result = value;
            return 1;
        }

        if (whole_number_only)
        {
            printf("Invalid input. Enter a whole number from %.0f to %.0f.\n",
                   minimum, maximum);
        }
        else
        {
            printf("Invalid input. Enter one positive, finite number within the supported range.\n");
        }
    }
}

// Accept one y/Y or n/N, with optional surrounding whitespace.
static int read_yes_no(const char *prompt, int *answer)
{
    char buffer[input_buffer_size];

    for (;;)
    {
        int input_status = read_line(prompt, buffer);

        if (input_status == input_closed)
        {
            return 0;
        }

        if (input_status == input_too_long)
        {
            continue;
        }

        char *text = buffer;

        while (isspace((unsigned char)*text))
        {
            text++;
        }

        int choice = tolower((unsigned char)*text);

        if (*text != '\0')
        {
            text++;
        }

        while (isspace((unsigned char)*text))
        {
            text++;
        }

        if ((choice == 'y' || choice == 'n') && *text == '\0')
        {
            *answer = choice == 'y';
            return 1;
        }

        printf("Invalid answer. Please enter y or n.\n");
    }
}

// Allocate space before starting a day, retaining the old array on failure.
static int reserve_next_day(activity_tracker *tracker)
{
    if (tracker->day_count < tracker->day_capacity)
    {
        return 1;
    }

    size_t maximum_capacity = SIZE_MAX / sizeof(day_record);

    if (tracker->day_capacity >= maximum_capacity)
    {
        return 0;
    }

    size_t new_capacity;

    if (tracker->day_capacity == 0)
    {
        new_capacity = 8;
    }
    else if (tracker->day_capacity > maximum_capacity / 2)
    {
        new_capacity = maximum_capacity;
    }
    else
    {
        new_capacity = tracker->day_capacity * 2;
    }

    day_record *new_days = realloc(tracker->days, new_capacity * sizeof(day_record));

    if (new_days == NULL)
    {
        return 0;
    }

    tracker->days = new_days;
    tracker->day_capacity = new_capacity;
    return 1;
}

static double get_intensity_factor(int intensity_choice)
{
    if (intensity_choice == 2)
    {
        return 1.10;
    }

    if (intensity_choice == 3)
    {
        return 1.20;
    }

    return 1.00;
}

// Normalise the selected unit to steps without rounding its fractional part.
static int read_activity_steps(int activity_choice, double *steps)
{
    double value;
    double conversion_rate;
    const char *prompt;

    if (activity_choice == 1)
    {
        return read_number("How many steps? ", 1.0, INT_MAX, 1, steps);
    }

    if (activity_choice == 2)
    {
        prompt = "How many kilometres? ";
        conversion_rate = steps_per_km;
    }
    else
    {
        prompt = "How many walking minutes? ";
        conversion_rate = steps_per_walking_minute;
    }

    if (!read_number(prompt, 0.0, DBL_MAX / conversion_rate, 0, &value))
    {
        return 0;
    }

    *steps = value * conversion_rate;
    return 1;
}

// Validate all calculated values before changing any totals or counters.
static int record_entry(activity_tracker *tracker, day_record *day,
                        int activity_choice, double entry_steps, int daily_goal)
{
    size_t type_index = (size_t)(activity_choice - 1);

    if (day->entry_counts[type_index] == SIZE_MAX ||
        tracker->entry_counts[type_index] == SIZE_MAX)
    {
        printf("The entry counter limit has been reached. Tracking will finish.\n");
        return entry_limit_reached;
    }

    double next_day_steps = day->steps + entry_steps;
    double next_total_steps = tracker->total_steps + entry_steps;
    double next_day_calories = (next_day_steps / steps_per_calorie_rate) *
                               calories_per_1000_steps * get_intensity_factor(day->intensity_choice);
    double next_total_calories = tracker->total_calories + (next_day_calories - day->calories);
    double progress = (next_day_steps / daily_goal) * 100.0;

    // Reject overflow and amounts too small to change the stored totals.
    if (!isfinite(next_day_steps) || !isfinite(next_total_steps) ||
        !isfinite(next_day_calories) || !isfinite(next_total_calories) ||
        !isfinite(progress) || next_day_steps <= day->steps ||
        next_total_steps <= tracker->total_steps || next_day_calories <= day->calories ||
        next_total_calories <= tracker->total_calories)
    {
        printf("This amount is too large or too small for the recorded totals. Enter another amount.\n");
        return entry_invalid;
    }

    day->steps = next_day_steps;
    day->calories = next_day_calories;
    day->entry_counts[type_index]++;
    tracker->total_steps = next_total_steps;
    tracker->total_calories = next_total_calories;
    tracker->entry_counts[type_index]++;

    double entry_calories = (entry_steps / steps_per_calorie_rate) *
                            calories_per_1000_steps * get_intensity_factor(day->intensity_choice);

    printf("Added %.2f steps.\n", entry_steps);
    printf("Distance: %.2f km | Calories: %.2f kcal\n",
           entry_steps / steps_per_km, entry_calories);
    printf("Today's steps: %.2f | Progress: %.2f%% of daily goal\n", day->steps, progress);
    return entry_recorded;
}

// Allow only a tiny tolerance for floating-point rounding at the goal boundary.
static int goal_was_reached(double steps, int daily_goal)
{
    double tolerance = 16.0 * DBL_EPSILON * daily_goal;
    return steps >= daily_goal || daily_goal - steps <= tolerance;
}

static void print_summary(const activity_tracker *tracker, int daily_goal)
{
    size_t days_meeting_goal = 0;
    size_t current_streak = 0;
    size_t longest_streak = 0;

    printf("\nFinal Summary:\n");
    printf("Daily step goal: %d\n", daily_goal);

    if (tracker->day_count == 0)
    {
        printf("No activity entries were recorded.\n");
    }

    for (size_t day_index = 0; day_index < tracker->day_count; day_index++)
    {
        const day_record *day = &tracker->days[day_index];

        printf("Day %zu: %.2f steps, %.2f km, %.2f kcal, %.2f%% of goal\n",
               day_index + 1, day->steps, day->steps / steps_per_km,
               day->calories, (day->steps / daily_goal) * 100.0);

        if (goal_was_reached(day->steps, daily_goal))
        {
            days_meeting_goal++;
            current_streak++;

            if (current_streak > longest_streak)
            {
                longest_streak = current_streak;
            }
        }
        else
        {
            // A day below the goal breaks the consecutive-day streak.
            current_streak = 0;
        }
    }

    printf("\nDays tracked: %zu\n", tracker->day_count);
    printf("Overall Steps: %.2f\n", tracker->total_steps);
    printf("Overall Distance: %.2f km\n", tracker->total_steps / steps_per_km);
    printf("Overall Calories: %.2f kcal\n", tracker->total_calories);
    printf("Entries - Steps: %zu, Kilometres: %zu, Walking Minutes: %zu\n",
           tracker->entry_counts[0], tracker->entry_counts[1], tracker->entry_counts[2]);
    printf("Days Meeting Goal: %zu\n", days_meeting_goal);
    printf("Longest Goal Streak: %zu %s\n", longest_streak,
           longest_streak == 1 ? "day" : "days");
}

int main(void)
{
    activity_tracker tracker = {0};
    double numeric_choice;
    int input_ended = 0;
    int program_status = EXIT_SUCCESS;
    int start_new_day = 1;

    printf("Step Count Fitness Tracker - Goals and Streaks\n");
    printf("Each new day represents the next consecutive day.\n\n");

    if (!read_number("Enter your daily step goal: ", 1.0, INT_MAX, 1, &numeric_choice))
    {
        printf("\nInput ended before a goal was entered. No activity was recorded.\n");
        return ferror(stdin) ? EXIT_FAILURE : EXIT_SUCCESS;
    }

    int daily_goal = (int)numeric_choice;

    // The outer loop starts a new day; the inner loop records entries for it.
    while (start_new_day)
    {
        if (!reserve_next_day(&tracker))
        {
            printf("\nUnable to allocate space for another day. Recorded activity is retained.\n");
            program_status = EXIT_FAILURE;
            break;
        }

        day_record current_day = {0};
        printf("\nDay %zu\n", tracker.day_count + 1);
        printf("Select activity intensity for this day:\n");
        printf("1: Light walking (no calorie adjustment)\n");
        printf("2: Moderate walking (+10%% calories)\n");
        printf("3: Fast walking (+20%% calories)\n");

        if (!read_number("Enter choice: ", 1.0, 3.0, 1, &numeric_choice))
        {
            input_ended = 1;
            break;
        }

        current_day.intensity_choice = (int)numeric_choice;
        int add_another_entry = 1;

        while (add_another_entry)
        {
            printf("\nWhat would you like to add?\n");
            printf("1: Steps\n");
            printf("2: Kilometres\n");
            printf("3: Walking minutes\n");

            if (!read_number("Enter your choice: ", 1.0, 3.0, 1, &numeric_choice))
            {
                input_ended = 1;
                break;
            }

            int activity_choice = (int)numeric_choice;
            int entry_status = entry_invalid;

            // Invalid amounts are re-entered without asking for the type again.
            while (entry_status == entry_invalid)
            {
                double entry_steps;

                if (!read_activity_steps(activity_choice, &entry_steps))
                {
                    input_ended = 1;
                    break;
                }

                entry_status = record_entry(&tracker, &current_day,
                                            activity_choice, entry_steps, daily_goal);
            }

            if (input_ended || entry_status == entry_limit_reached)
            {
                if (entry_status == entry_limit_reached)
                {
                    program_status = EXIT_FAILURE;
                }

                break;
            }

            if (!read_yes_no("\nAdd another entry for today? (y/n): ", &add_another_entry))
            {
                input_ended = 1;
                break;
            }
        }

        // Include a partially entered day on EOF if it has valid activity.
        if (current_day.steps > 0.0)
        {
            tracker.days[tracker.day_count] = current_day;
            tracker.day_count++;
        }

        if (input_ended || program_status != EXIT_SUCCESS)
        {
            break;
        }

        if (!read_yes_no("Start a new day? (y/n): ", &start_new_day))
        {
            input_ended = 1;
            break;
        }
    }

    if (input_ended)
    {
        printf("\nInput ended. Showing all activity recorded so far.\n");
    }

    print_summary(&tracker, daily_goal);
    free(tracker.days);
    return ferror(stdin) ? EXIT_FAILURE : program_status;
}
