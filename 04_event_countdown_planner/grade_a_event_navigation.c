/*
    This program stores several events, each with a name, day, and month,
    and asks the user to enter the current date. It validates all dates
    using the real month lengths for 2026, when February has 28 days.

    One event is displayed at a time with its name, date, days remaining,
    weekday, and status. Weekdays are calculated with modulo 7, using
    Thursday, 1 January 2026, as the starting point. An event today shows
    *** EVENT IS TODAY ***, and an event 1-7 days away shows
    *** URGENT EVENT ***. Past events are clearly marked Already passed
    and show zero days remaining instead of a negative countdown.

    The navigation menu can show the next event, show the previous event,
    add another event, or exit. Navigation cannot move outside the stored
    list. A newly added event becomes the event currently displayed.

    Invalid numbers, dates, names, and menu choices produce an error and
    are requested again. The program runs until Exit is selected or the
    input stream ends. It stores up to 100 events in the order entered;
    each name can contain spaces and up to 100 bytes of text.

    This Grade A solution uses arrays, a structure, strings, and helper
    functions to organise the program. All data is held in memory during
    the current run.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Enumeration constants provide fixed array sizes.
enum
{
    max_events = 100,
    max_event_name_length = 100,
    input_capacity = 512
};

// Keep each event's related information together in one record.
struct event
{
    char name[max_event_name_length + 1];
    int day;
    int month;
};

// Read a complete line: 1 means success, 0 means EOF, and -1 means invalid input.
int read_line(char line[], int capacity)
{
    int length = 0;
    int too_long = 0;
    int invalid_character = 0;
    int first_character;
    int end_position;
    int input_character = getchar();

    // EOF means there is no more input; callers can then exit cleanly.
    if (input_character == EOF)
    {
        return 0;
    }

    // Consume the entire line, including any excess characters, before returning.
    while (input_character != '\n' && input_character != EOF)
    {
        // Reject embedded nulls and other control characters that could hide input.
        if ((input_character < 32 && input_character != '\t' &&
             input_character != '\r') ||
            input_character == 127)
        {
            invalid_character = 1;
        }

        // Leave one array position for the string's terminating null character.
        if (length < capacity - 1)
        {
            line[length] = (char)input_character;
            length++;
        }
        else
        {
            too_long = 1;
        }

        input_character = getchar();
    }

    line[length] = '\0';

    if (too_long == 1)
    {
        printf("Invalid input. The line is too long; use at most %d bytes.\n",
               capacity - 1);
        return -1;
    }

    if (invalid_character == 1)
    {
        printf("Invalid input. Control characters are not allowed.\n");
        return -1;
    }

    // Remove surrounding whitespace while preserving spaces inside event names.
    first_character = 0;
    end_position = length;

    while (first_character < end_position &&
           isspace((unsigned char)line[first_character]))
    {
        first_character++;
    }

    while (end_position > first_character &&
           isspace((unsigned char)line[end_position - 1]))
    {
        end_position--;
    }

    // memmove safely handles overlapping source and destination positions.
    memmove(line, line + first_character, (size_t)(end_position - first_character));
    line[end_position - first_character] = '\0';

    return 1;
}

// Request one whole number in range; repeat after errors and return 0 only on EOF.
int read_number(const char prompt[], int min_value, int max_value, int *number)
{
    char line[input_capacity];

    while (1)
    {
        int input_value = 0;
        int valid_number = 1;
        int index = 0;
        int line_result;

        printf("%s", prompt);
        fflush(stdout);
        line_result = read_line(line, input_capacity);

        if (line_result == 0)
        {
            return 0;
        }

        if (line_result == -1)
        {
            continue;
        }

        // An empty or whitespace-only line does not contain a number.
        if (line[0] == '\0')
        {
            valid_number = 0;
        }

        while (line[index] != '\0' && valid_number == 1)
        {
            int digit;

            // Accept digits only, rejecting signs, decimals, letters, and gaps.
            if (line[index] < '0' || line[index] > '9')
            {
                valid_number = 0;
                break;
            }

            digit = line[index] - '0';

            // Check before multiplying so even a very long number cannot overflow.
            if (input_value > max_value / 10 ||
                (input_value == max_value / 10 && digit > max_value % 10))
            {
                valid_number = 0;
                break;
            }

            input_value = input_value * 10 + digit;
            index++;
        }

        if (valid_number == 0 || input_value < min_value)
        {
            printf("Invalid input. Enter one whole number between %d and %d, using digits only.\n",
                   min_value, max_value);
            continue;
        }

        // Write to the caller's variable only after all checks have passed.
        *number = input_value;
        return 1;
    }
}

// Return the correct month length for the fixed assessment year, 2026.
int days_in_month(int month)
{
    switch (month)
    {
    case 2:
        return 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    default:
        return 0;
    }
}

// Read and validate a complete date, requesting it again if it is impossible.
int read_date(const char day_prompt[], const char month_prompt[], int *day, int *month)
{
    while (1)
    {
        int month_length;

        // Check each input's format and general range before the next prompt.
        if (read_number(day_prompt, 1, 31, day) == 0)
        {
            return 0;
        }

        if (read_number(month_prompt, 1, 12, month) == 0)
        {
            return 0;
        }

        month_length = days_in_month(*month);

        // The exact limit is known only after the month has been entered.
        if (*day > month_length)
        {
            printf("Invalid date. Month %d has only %d days in 2026.\n",
                   *month, month_length);
            printf("Please enter both parts of this date again.\n\n");
            continue;
        }

        return 1;
    }
}

// Convert a validated date to its position in the year, from 1 to 365.
int day_of_year(int day, int month)
{
    int day_number = day;
    int previous_month;

    for (previous_month = 1; previous_month < month; previous_month++)
    {
        day_number += days_in_month(previous_month);
    }

    return day_number;
}

// Preserve Grade B's Monday=1 to Sunday=7 weekday calculation.
int weekday_number(int event_day_number)
{
    const int first_weekday = 4; // Thursday, 1 January 2026.
    const int days_in_week = 7;

    // Subtract 1 to get Thursday's index and the days elapsed since 1 January.
    // Modulo 7 repeats the weekly cycle; adding 1 restores the range 1-7.
    return ((first_weekday - 1) + (event_day_number - 1)) % days_in_week + 1;
}

// Collect one complete event before the caller adds it to the event list.
int read_event(struct event *new_event, int event_number)
{
    char line[input_capacity];

    while (1)
    {
        int line_result;

        printf("Enter event %d name: ", event_number);
        fflush(stdout);
        line_result = read_line(line, input_capacity);

        if (line_result == 0)
        {
            return 0;
        }

        if (line_result == -1)
        {
            continue;
        }

        if (line[0] == '\0')
        {
            printf("Invalid name. The event name cannot be empty.\n");
            continue;
        }

        if (strlen(line) > (size_t)max_event_name_length)
        {
            printf("Invalid name. Use at most %d bytes of text.\n", max_event_name_length);
            continue;
        }

        // The checked length fits in the name array, including its final '\0'.
        strcpy(new_event->name, line);
        break;
    }

    return read_date("Enter event day: ", "Enter event month: ",
                     &new_event->day, &new_event->month);
}

// Display only the selected event, including its countdown, weekday, and status.
void display_event(const struct event *selected_event, int event_index,
                   int event_count, int current_day_number)
{
    int event_day_number = day_of_year(selected_event->day, selected_event->month);
    int days_until_event = event_day_number - current_day_number;
    int event_weekday = weekday_number(event_day_number);
    const int coming_soon_limit = 7;

    printf("\nCurrent Event (%d of %d):\n", event_index + 1, event_count);
    printf("Name: %s\n", selected_event->name);
    printf("Date: %d/%d/2026\n", selected_event->day, selected_event->month);

    // Keep a remaining-days field for every event without a negative countdown.
    // The original difference is still used below to distinguish past from today.
    if (days_until_event < 0)
    {
        printf("Days remaining: 0 (event already passed)\n");
        printf("Error: The event date is before the current date.\n");
    }
    else
    {
        printf("Days remaining: %d\n", days_until_event);
    }

    printf("Weekday: ");

    switch (event_weekday)
    {
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    case 4:
        printf("Thursday\n");
        break;
    case 5:
        printf("Friday\n");
        break;
    case 6:
        printf("Saturday\n");
        break;
    case 7:
        printf("Sunday\n");
        break;
    }

    // Past events must not be marked urgent, even when they passed recently.
    if (days_until_event < 0)
    {
        printf("Status: Already passed\n");
    }
    else if (days_until_event == 0)
    {
        printf("Status: Today\n");
        printf("*** EVENT IS TODAY ***\n");
    }
    else if (days_until_event <= coming_soon_limit)
    {
        printf("Status: Coming soon\n");
        printf("*** URGENT EVENT ***\n");
    }
    else
    {
        printf("Status: Later in the year\n");
    }
}

int main(void)
{
    // Only entries below event_count contain fully entered, valid events.
    struct event events[max_events];
    struct event new_event;
    int event_count = 0;
    int current_event_index = 0;
    int initial_event_count;
    int current_day;
    int current_month;
    int current_day_number;
    int menu_choice;

    printf("Event Countdown Planner 2026\n");
    printf("You can store between 1 and %d events.\n\n", max_events);

    // Validate the initial count before accessing any event-array positions.
    if (read_number("How many events do you want to enter? ",
                    1, max_events, &initial_event_count) == 0)
    {
        printf("\nInput ended. Exiting program...\n");
        return 0;
    }

    printf("\n");

    while (event_count < initial_event_count)
    {
        if (read_event(&new_event, event_count + 1) == 0)
        {
            printf("\nInput ended. Exiting program...\n");
            return 0;
        }

        // Commit the event only after its name and complete date are valid.
        events[event_count] = new_event;
        event_count++;
        printf("\n");
    }

    // The assessment's example enters the current date after the initial events.
    if (read_date("Enter current day: ", "Enter current month: ",
                  &current_day, &current_month) == 0)
    {
        printf("\nInput ended. Exiting program...\n");
        return 0;
    }

    current_day_number = day_of_year(current_day, current_month);

    // Continue displaying one event and accepting menu choices until Exit or EOF.
    while (1)
    {
        display_event(&events[current_event_index], current_event_index,
                      event_count, current_day_number);

        printf("\nNavigation:\n");
        printf("1. View next event\n");
        printf("2. View previous event\n");
        printf("3. Add another event\n");
        printf("4. Exit\n\n");

        if (read_number("Enter choice: ", 1, 4, &menu_choice) == 0)
        {
            printf("\nInput ended. Exiting program...\n");
            return 0;
        }

        switch (menu_choice)
        {
        case 1:
            // The last valid index is event_count - 1; do not move beyond it.
            if (current_event_index < event_count - 1)
            {
                current_event_index++;
            }
            else
            {
                printf("\nYou are already viewing the last event.\n");
            }
            break;

        case 2:
            // The first valid index is zero; do not move before it.
            if (current_event_index > 0)
            {
                current_event_index--;
            }
            else
            {
                printf("\nYou are already viewing the first event.\n");
            }
            break;

        case 3:
            // Check capacity before collecting or writing a new event.
            if (event_count == max_events)
            {
                printf("\nCannot add another event. The limit is %d events.\n", max_events);
                break;
            }

            printf("\n");

            if (read_event(&new_event, event_count + 1) == 0)
            {
                printf("\nInput ended. Exiting program...\n");
                return 0;
            }

            // Append the validated event and select it for the next display.
            events[event_count] = new_event;
            current_event_index = event_count;
            event_count++;
            printf("\nEvent added successfully.\n");
            break;

        case 4:
            printf("\nExiting program...\n");
            return 0;
        }
    }
}
