/*
This program records one day's activity per entry. The user selects steps,
kilometres, or walking minutes from a menu. Steps must be whole numbers;
kilometres and walking minutes may contain decimal places. Zero is allowed.

Each entry is converted into steps using 1,250 steps per kilometre or
100 steps per walking minute. Distance and estimated calories are then
calculated using 1,250 steps per kilometre and 40 calories per 1,000 steps.
Converted step equivalents keep any fractional part.

After displaying each day's results, the program lets the user return to
the menu for another day or stop. The final summary displays the number
of days tracked, total steps, total distance, total estimated calories,
and the number of entries recorded for each input type. All calculated
activity values are displayed to two decimal places.

Invalid input or a value that exceeds the supported numeric range produces
an error message and ends the program. Only valid entries update the totals.
*/

#include <stdio.h>
#include <ctype.h>
#include <float.h>
#include <limits.h>

int main(void)
{
    char activity_choice;
    char add_another_entry;
    int input_character;
    int has_extra_input;

    int days_tracked = 0;
    int step_entries = 0;
    int kilometre_entries = 0;
    int walking_minute_entries = 0;

    double activity_value;
    double steps_per_day;
    double distance_km;
    double estimated_calories;
    double total_steps = 0.0;
    double total_distance = 0.0;
    double total_calories = 0.0;

    // Fixed conversion rates from the assessment requirements.
    const double steps_per_km = 1250.0;
    const double steps_per_walking_minute = 100.0;
    const double steps_per_calorie_rate = 1000.0;
    const double calories_per_1000_steps = 40.0;

    printf("Step Count Fitness Tracker\n");
    printf("Record one day's activity per entry, using one input type.\n");

    do
    {
        printf("\nWhat would you like to add?\n");
        printf("1: Steps\n");
        printf("2: Kilometres\n");
        printf("3: Walking minutes\n\n");
        printf("Enter your choice: ");

        if (scanf(" %c", &activity_choice) != 1)
        {
            printf("No menu choice was read. Program ended.\n");
            return 1;
        }

        // Check the rest of the line so entries such as '12' are rejected.
        has_extra_input = 0;

        while ((input_character = getchar()) != '\n' && input_character != EOF)
        {
            if (!isspace(input_character))
            {
                has_extra_input = 1;
            }
        }

        if (has_extra_input ||
            (activity_choice != '1' && activity_choice != '2' && activity_choice != '3'))
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            return 1;
        }

        // Display the input prompt for the selected activity type.
        if (activity_choice == '1')
        {
            printf("How many steps? ");
        }
        else if (activity_choice == '2')
        {
            printf("How many kilometres? ");
        }
        else
        {
            printf("How many walking minutes? ");
        }

        if (scanf("%lf", &activity_value) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        // Reject trailing text or a second value, while allowing trailing spaces.
        has_extra_input = 0;

        while ((input_character = getchar()) != '\n' && input_character != EOF)
        {
            if (!isspace(input_character))
            {
                has_extra_input = 1;
            }
        }

        if (has_extra_input)
        {
            printf("Invalid input. Please enter one number without extra text.\n");
            return 1;
        }

        // This range check also rejects infinity and NaN (not-a-number).
        if (!(activity_value >= 0.0 && activity_value <= DBL_MAX))
        {
            printf("Invalid activity value. Please enter a finite, non-negative number.\n");
            return 1;
        }

        // Convert the chosen input type into a common unit: steps.
        if (activity_choice == '1')
        {
            // Check the range before casting, then reject fractional step counts.
            if (activity_value > INT_MAX || activity_value != (int)activity_value)
            {
                printf("Invalid steps. Please enter a whole number from 0 to %d.\n", INT_MAX);
                return 1;
            }

            steps_per_day = activity_value;
        }
        else if (activity_choice == '2')
        {
            if (activity_value > DBL_MAX / steps_per_km)
            {
                printf("The distance is too large to convert into steps.\n");
                return 1;
            }

            steps_per_day = activity_value * steps_per_km;
        }
        else
        {
            if (activity_value > DBL_MAX / steps_per_walking_minute)
            {
                printf("The walking time is too large to convert into steps.\n");
                return 1;
            }

            steps_per_day = activity_value * steps_per_walking_minute;
        }

        // Check the running total and counters before updating them.
        if (!(steps_per_day <= DBL_MAX - total_steps) || days_tracked == INT_MAX)
        {
            printf("This entry would exceed the supported totals. Program ended.\n");
            return 1;
        }

        distance_km = steps_per_day / steps_per_km;
        estimated_calories =
            (steps_per_day / steps_per_calorie_rate) * calories_per_1000_steps;

        // Each valid entry represents one day, retaining Grade C's day count.
        days_tracked++;
        total_steps += steps_per_day;
        total_distance = total_steps / steps_per_km;
        total_calories =
            (total_steps / steps_per_calorie_rate) * calories_per_1000_steps;

        // Count the original input type, even though every entry becomes steps.
        if (activity_choice == '1')
        {
            step_entries++;
        }
        else if (activity_choice == '2')
        {
            kilometre_entries++;
        }
        else
        {
            walking_minute_entries++;
        }

        printf("Added %.2f steps.\n", steps_per_day);
        printf("Distance: %.2f km | Calories: %.2f kcal\n",
               distance_km, estimated_calories);

        printf("\nAdd another entry? (y/n): ");

        if (scanf(" %c", &add_another_entry) != 1)
        {
            printf("No yes/no answer was read. Program ended.\n");
            return 1;
        }

        // Accept exactly one letter, with optional surrounding whitespace.
        has_extra_input = 0;

        while ((input_character = getchar()) != '\n' && input_character != EOF)
        {
            if (!isspace(input_character))
            {
                has_extra_input = 1;
            }
        }

        if (has_extra_input ||
            (add_another_entry != 'y' && add_another_entry != 'Y' &&
             add_another_entry != 'n' && add_another_entry != 'N'))
        {
            printf("Invalid answer. Please enter y or n.\n");
            return 1;
        }

    } while (add_another_entry == 'y' || add_another_entry == 'Y');

    // Display the combined totals and the number of entries for each input type.
    printf("\nSummary:\n");
    printf("Days tracked: %d\n", days_tracked);
    printf("Total Steps: %.2f\n", total_steps);
    printf("Total Distance: %.2f km\n", total_distance);
    printf("Total Calories: %.2f kcal\n", total_calories);
    printf("Entries - Steps: %d, Kilometres: %d, Walking Minutes: %d\n",
           step_entries, kilometre_entries, walking_minute_entries);

    return 0;
}
