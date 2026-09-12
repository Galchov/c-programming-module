/*
    This program asks for the current day and month, then the event day
    and month. It validates both dates using the real month lengths for
    2026, including 28 days in February, and calculates their day numbers.

    The difference between the day numbers gives the days until the event.
    The program reports Today for 0 days, Coming soon for 1-7 days, Later
    in the year for more than 7 days, or Already passed for a past event.
    A past event also produces an error message without a negative count.

    The event weekday is calculated automatically using modulo 7 and
    the fact that 1 January 2026 is Thursday. Weekdays are numbered from
    1 for Monday to 7 for Sunday, and the weekday name is displayed.

    Input must be one positive whole number per line, using digits only.
    Spaces or tabs around a number are allowed. Invalid input ends the
    program immediately, and impossible dates are rejected as soon as
    both the day and month are known.
*/

#include <stdio.h>

int main(void)
{
    // The first completed date fills the current value; the second fills the event.
    int current_day_number = 0;
    int event_day_number = 0;
    int days_until_event;

    // These variables are reused while entering each of the two dates.
    int date_number;
    int date_part;
    int day;
    int month;
    int day_number;

    // Calendar values used for validation and adding earlier months.
    int days_in_month;
    int month_number;

    int event_weekday;

    // Scalar variables allow complete input validation without an input array.
    int input_value;
    int input_limit;
    int input_character;
    int has_digits;
    int number_finished;

    // Constants use snake_case, just like the other identifiers.
    const int number_of_dates = 2;
    const int parts_per_date = 2;
    const int min_value = 1;
    const int max_month = 12;
    const int max_day = 31;
    const int coming_soon_limit = 7;
    const int first_weekday = 4; // 1 January 2026 is Thursday.
    const int days_in_week = 7;

    // Enter the current date first and the event date second.
    for (date_number = 1; date_number <= number_of_dates; date_number++)
    {
        day = 0;
        month = 0;

        // Each date contains two inputs: day followed by month.
        for (date_part = 1; date_part <= parts_per_date; date_part++)
        {
            if (date_number == 1)
            {
                printf("Enter current ");
            }
            else
            {
                printf("Enter event ");
            }

            // Choose the prompt and valid range for this part of the date.
            if (date_part == 1)
            {
                printf("day: ");
                input_limit = max_day;
            }
            else
            {
                printf("month: ");
                input_limit = max_month;
            }

            // Reset the number and input flags before reading this line.
            input_value = 0;
            has_digits = 0;
            number_finished = 0;

            // getchar returns a character or EOF, so store its result in an int.
            input_character = getchar();

            // Check characters until Enter is pressed or input ends.
            while (input_character != '\n' && input_character != EOF)
            {
                if (input_character >= '0' && input_character <= '9')
                {
                    // Spaces inside a number or between two numbers are invalid.
                    if (number_finished == 1)
                    {
                        printf("Invalid input. Enter one whole number per line.\n");
                        return 1;
                    }

                    // Convert the character to a digit and append it to the value.
                    // The previous value is at most 31, so this cannot overflow.
                    input_value = input_value * 10 + (input_character - '0');
                    has_digits = 1;

                    // Reject an excessive value before another digit can enlarge it.
                    if (input_value > input_limit)
                    {
                        printf("Invalid input. Enter a number between %d and %d.\n",
                               min_value, input_limit);
                        return 1;
                    }
                }
                else if (input_character == ' ' || input_character == '\t' ||
                         input_character == '\r')
                {
                    // Allow spaces and tabs before or after the digits.
                    if (has_digits == 1)
                    {
                        number_finished = 1;
                    }
                }
                else
                {
                    // Reject letters, decimal points, signs, and other symbols.
                    printf("Invalid input. Use digits only for the whole number.\n");
                    return 1;
                }

                input_character = getchar();
            }

            // A blank line or EOF before any digits is not a valid entry.
            if (has_digits == 0)
            {
                printf("Invalid input. No number was entered.\n");
                return 1;
            }

            // Day and month values start at 1; zero is not a calendar date.
            if (input_value < min_value)
            {
                printf("Invalid input. Enter a number between %d and %d.\n",
                       min_value, input_limit);
                return 1;
            }

            // Store this value only after its format and range have been checked.
            if (date_part == 1)
            {
                day = input_value;
            }
            else
            {
                month = input_value;
            }
        }

        // Find the actual day limit for the selected month in 2026.
        switch (month)
        {
        case 2:
            days_in_month = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days_in_month = 30;
            break;
        default:
            days_in_month = 31;
            break;
        }

        // Reject an impossible date before asking for any further input.
        if (day > days_in_month)
        {
            if (date_number == 1)
            {
                printf("Invalid current date. ");
            }
            else
            {
                printf("Invalid event date. ");
            }

            printf("Month %d has only %d days in 2026.\n", month, days_in_month);
            return 1;
        }

        // Start with the day, then add every complete month before this one.
        day_number = day;

        for (month_number = 1; month_number < month; month_number++)
        {
            switch (month_number)
            {
            case 2:
                day_number += 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                day_number += 30;
                break;
            default:
                day_number += 31;
                break;
            }
        }

        // Keep the calculated day number for the appropriate date.
        if (date_number == 1)
        {
            current_day_number = day_number;
        }
        else
        {
            event_day_number = day_number;
        }

        // Separate the two prompt groups and leave space before the results.
        printf("\n");
    }

    // Positive means a future event, zero means today, and negative means past.
    days_until_event = event_day_number - current_day_number;

    // Retain the past-event error and avoid displaying a negative countdown.
    if (days_until_event < 0)
    {
        printf("Error: The event date is before the current date.\n");
    }
    else
    {
        printf("Days until event: %d days\n", days_until_event);
    }

    // Thursday is 4 in the assessment's Monday=1 to Sunday=7 numbering.
    // Subtract 1 to turn that weekday into index 3, within the range 0-6.
    // event_day_number - 1 is the number of days elapsed since 1 January.
    // Modulo 7 repeats the weekly cycle; adding 1 restores the range 1-7.
    event_weekday = ((first_weekday - 1) + (event_day_number - 1)) % days_in_week + 1;

    printf("Event weekday: ");

    // Display the calculated weekday name using the required numbering.
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
    // Use the exact status thresholds from Assessment Sheet 4.
    if (days_until_event < 0)
    {
        printf("Status: Already passed\n");
    }
    else if (days_until_event == 0)
    {
        printf("Status: Today\n");
    }
    else if (days_until_event <= coming_soon_limit)
    {
        printf("Status: Coming soon\n");
    }
    else
    {
        printf("Status: Later in the year\n");
    }

    return 0;
}
