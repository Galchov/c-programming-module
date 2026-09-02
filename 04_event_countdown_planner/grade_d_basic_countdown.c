/*
Create a basic program that calculates the approximate number of days until an event.
Requirements
The program should:
    1. Ask the user to enter:
        o Current day
        o Current month
        o Event day
        o Event month
    2. Use a fixed month length of 30 days for every month.
    3. Convert both dates into approximate day numbers.
    4. Calculate the approximate number of days between the current date and the event date.
    5. Display the number of days until the event.
    6. If the event date is before the current date, display an error message.

Example Interaction:

Enter current day: 10
Enter current month: 3

Enter event day: 25
Enter event month: 4

Approximate days until event: 45 days
*/

#include <stdio.h>

int main(void)
{
    int current_day;
    int current_month;
    int event_day;
    int event_month;

    int current_day_number;
    int event_day_number;
    int days_until_event;

    const int MONTH_DAYS = 30;
    const int MONTHS = 12;

    const char days_error_message[] =
        "Invalid day. Please enter a day between 1 and 30.";

    const char months_error_message[] =
        "Invalid month. Please enter a number between 1 and 12.";

    printf("Enter current day: ");
    scanf("%d", &current_day);

    if (current_day < 1 || current_day > MONTH_DAYS)
    {
        printf("%s\n", days_error_message);
        return 1;
    }

    printf("Enter current month: ");
    scanf("%d", &current_month);

    if (current_month < 1 || current_month > MONTHS)
    {
        printf("%s\n", months_error_message);
        return 1;
    }

    printf("Enter event day: ");
    scanf("%d", &event_day);

    if (event_day < 1 || event_day > MONTH_DAYS)
    {
        printf("%s\n", days_error_message);
        return 1;
    }

    printf("Enter event month: ");
    scanf("%d", &event_month);

    if (event_month < 1 || event_month > MONTHS)
    {
        printf("%s\n", months_error_message);
        return 1;
    }

    current_day_number = (current_month - 1) * MONTH_DAYS + current_day;
    event_day_number = (event_month - 1) * MONTH_DAYS + event_day;

    days_until_event = event_day_number - current_day_number;

    if (days_until_event < 0)
    {
        printf("Error: The event date is before the current date.\n");
        return 1;
    }

    printf("Approximate days until event: %d days\n", days_until_event);

    return 0;
}
