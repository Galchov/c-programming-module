/*
    This program asks the user to enter the current date and an event date
    in 2026. It uses the correct number of days for each month and validates
    that each month and day entered is valid.

    The program converts both dates into their accurate day numbers within
    the year, calculates the number of days between them, and displays
    whether the event is today, coming soon, later in the year, or has
    already passed.
*/

#include <stdio.h>

int main(void)
{
    int current_day;
    int current_month;
    int event_day;
    int event_month;

    int current_month_days;
    int event_month_days;

    int current_day_number;
    int event_day_number;
    int days_until_event;

    int month;

    const int MIN_DAY = 1;
    const int MAX_DAY = 31;
    const int MIN_MONTH = 1;
    const int MAX_MONTH = 12;

    const char day_error_message[] =
        "Invalid day. Please enter a day between 1 and 31.";

    const char month_day_error_message[] =
        "Invalid day for the selected month.";

    const char month_error_message[] =
        "Invalid month. Please enter a month between 1 and 12.";

    const char input_error_message[] =
        "Invalid input. Please enter a whole number.";

    // Get and validate the current day.
    printf("Enter current day: ");

    if (scanf("%d", &current_day) != 1)
    {
        printf("%s\n", input_error_message);
        return 1;
    }

    if (current_day < MIN_DAY || current_day > MAX_DAY)
    {
        printf("%s\n", day_error_message);
        return 1;
    }

    // Get and validate the current month.
    printf("Enter current month: ");

    if (scanf("%d", &current_month) != 1)
    {
        printf("%s\n", input_error_message);
        return 1;
    }

    if (current_month < MIN_MONTH || current_month > MAX_MONTH)
    {
        printf("%s\n", month_error_message);
        return 1;
    }

    // Determine the correct number of days in the current month.
    switch (current_month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        current_month_days = 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        current_month_days = 30;
        break;

    case 2:
        current_month_days = 28;
        break;
    }

    // Validate the current day against the selected month.
    if (current_day > current_month_days)
    {
        printf("%s\n", month_day_error_message);
        return 1;
    }

    // Separate the current date inputs from the event date inputs.
    printf("\n");

    // Get and validate the event day.
    printf("Enter event day: ");

    if (scanf("%d", &event_day) != 1)
    {
        printf("%s\n", input_error_message);
        return 1;
    }

    if (event_day < MIN_DAY || event_day > MAX_DAY)
    {
        printf("%s\n", day_error_message);
        return 1;
    }

    // Get and validate the event month.
    printf("Enter event month: ");

    if (scanf("%d", &event_month) != 1)
    {
        printf("%s\n", input_error_message);
        return 1;
    }

    if (event_month < MIN_MONTH || event_month > MAX_MONTH)
    {
        printf("%s\n", month_error_message);
        return 1;
    }

    // Determine the correct number of days in the event month.
    switch (event_month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        event_month_days = 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        event_month_days = 30;
        break;

    case 2:
        event_month_days = 28;
        break;
    }

    // Validate the event day against the selected month.
    if (event_day > event_month_days)
    {
        printf("%s\n", month_day_error_message);
        return 1;
    }

    // Start the current date calculation with the current day.
    current_day_number = current_day;

    // Add all complete months before the current month.
    for (month = 1; month < current_month; month++)
    {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            current_day_number += 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            current_day_number += 30;
            break;

        case 2:
            current_day_number += 28;
            break;
        }
    }

    // Start the event date calculation with the event day.
    event_day_number = event_day;

    // Add all complete months before the event month.
    for (month = 1; month < event_month; month++)
    {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            event_day_number += 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            event_day_number += 30;
            break;

        case 2:
            event_day_number += 28;
            break;
        }
    }

    // Calculate the accurate number of days between the dates.
    days_until_event = event_day_number - current_day_number;

    // Separate the input section from the program output.
    printf("\n");

    // Display the appropriate event status.
    if (days_until_event < 0)
    {
        printf("Status: Already passed\n");
    }
    else if (days_until_event == 0)
    {
        printf("Days until event: 0 days\n");
        printf("Status: Today\n");
    }
    else if (days_until_event <= 7)
    {
        printf("Days until event: %d days\n", days_until_event);
        printf("Status: Coming soon\n");
    }
    else
    {
        printf("Days until event: %d days\n", days_until_event);
        printf("Status: Later in the year\n");
    }

    return 0;
}
