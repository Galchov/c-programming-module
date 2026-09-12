/*
    This program asks for the current day and month, then the event day
    and month. It uses a fixed length of 30 days for every month, as this
    grade requires, and accepts month numbers from 1 to 12.

    Each date is converted into an approximate day number. The program
    subtracts the current day number from the event day number and
    displays the approximate days remaining. An event before the current
    date produces an error message without a negative countdown.

    Input must be one positive whole number per line, using digits only.
    Spaces or tabs around a number are allowed. Empty entries, invalid
    characters, and out-of-range values produce an immediate error.
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
    const int days_per_month = 30;

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
                input_limit = days_per_month;
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

        // The fixed 30-day model gives an approximate day number from 1 to 360.
        day_number = (month - 1) * days_per_month + day;

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

    // Report a past event as an error without displaying a negative count.
    if (days_until_event < 0)
    {
        printf("Error: The event date is before the current date.\n");
        return 1;
    }

    // A zero difference means that the event date is the current date.
    printf("Approximate days until event: %d days\n", days_until_event);

    return 0;
}
