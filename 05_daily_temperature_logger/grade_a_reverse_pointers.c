/*
    This program allows the user to record temperature readings for up to
    30 days and stores them in a fixed-size array. A sentinel value marks
    the end of the valid temperature readings.

    The program provides a repeating menu that allows the user to:
    1. Display all recorded temperature readings.
    2. Calculate and display the overall average temperature.
    3. Find and display the highest and lowest temperatures.
    4. Count the number of days above and below a user-defined threshold.
    5. Calculate and display weekly average temperatures.
    6. Reverse the readings and display them using relative-day labels.
    7. Exit the program.

    The final recorded temperature represents the most recent day.
    Pointers are used to traverse the readings, find the highest and lowest
    temperatures, and create the reversed sequence of readings.

    All user inputs are validated. Invalid input displays an appropriate
    error message and the user is asked to enter the value again.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    const int max_days = 30;
    const int array_size = 50;
    const double sentinel_value = -999999.0;

    int number_of_days;
    int choice;
    int program_running = 1;

    double temperatures[array_size];
    double reversed_temperatures[array_size];

    double total_temperature;
    double average_temperature;
    double highest_temperature;
    double lowest_temperature;
    double threshold;
    double temperature_input;

    char input[100];
    char extra_character;

    // Fill the temperature array with the sentinel value.
    for (int index = 0; index < array_size; index++)
    {
        temperatures[index] = sentinel_value;
    }

    // Ask the user how many days they want to record.
    while (1)
    {
        printf("How many days do you want to record? ");

        // Read the complete line of input.
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading input.\n");
            return 1;
        }

        // Check that the input contains exactly one whole number.
        if (sscanf(input, "%d %c", &number_of_days, &extra_character) != 1)
        {
            printf("Invalid input. Please enter a whole number.\n\n");
            continue;
        }

        // Check that the number of days is within the allowed range.
        if (number_of_days < 1 || number_of_days > max_days)
        {
            printf("Invalid number of days. Please enter a number between 1 and %d.\n\n",
                   max_days);
            continue;
        }

        break;
    }

    printf("\n");

    // Ask the user to enter a valid temperature for each day.
    for (int day = 0; day < number_of_days; day++)
    {
        while (1)
        {
            printf("Enter temperature for day %d: ", day + 1);

            // Read the complete line of input.
            if (fgets(input, sizeof(input), stdin) == NULL)
            {
                printf("Error reading input.\n");
                return 1;
            }

            // Check that the input contains exactly one numeric value.
            if (sscanf(input, "%lf %c",
                       &temperature_input,
                       &extra_character) != 1)
            {
                printf("Invalid temperature. Please enter a numeric value.\n\n");
                continue;
            }

            // Reject NaN and infinity because they are not valid temperature readings.
            if (!isfinite(temperature_input))
            {
                printf("Invalid temperature. Please enter a finite numeric value.\n\n");
                continue;
            }

            // Prevent the internal sentinel value from being stored as a reading.
            if (temperature_input == sentinel_value)
            {
                printf("Invalid temperature. Please enter a different value.\n\n");
                continue;
            }

            temperatures[day] = temperature_input;
            break;
        }
    }

    // Mark the first unused array position as the end of valid readings.
    temperatures[number_of_days] = sentinel_value;

    // Keep displaying the menu until the user chooses to exit.
    while (program_running)
    {
        printf("\nMenu:\n");
        printf("1. Display all temperature readings\n");
        printf("2. Calculate average temperature\n");
        printf("3. Find highest and lowest temperature\n");
        printf("4. Count days above and below threshold\n");
        printf("5. Calculate weekly averages\n");
        printf("6. Reverse readings\n");
        printf("7. Exit\n");

        // Validate the menu choice.
        while (1)
        {
            printf("\nEnter choice: ");

            // Read the complete menu input.
            if (fgets(input, sizeof(input), stdin) == NULL)
            {
                printf("Error reading input.\n");
                return 1;
            }

            // Check that the menu input contains exactly one whole number.
            if (sscanf(input, "%d %c", &choice, &extra_character) != 1)
            {
                printf("Invalid input. Please enter a whole number.\n");
                continue;
            }

            // Check that the menu choice is between 1 and 7.
            if (choice < 1 || choice > 7)
            {
                printf("Invalid menu choice. Please enter a number between 1 and 7.\n");
                continue;
            }

            break;
        }

        // Perform the selected menu action.
        switch (choice)
        {
        case 1:
        {
            int day_number = 1;

            // Start a pointer at the first temperature reading.
            double *current_reading = temperatures;

            printf("\nTemperature Readings:\n");

            // Traverse the valid readings using a pointer.
            while (*current_reading != sentinel_value)
            {
                printf("Day %d: %.1f degrees C\n",
                       day_number,
                       *current_reading);

                current_reading++;
                day_number++;
            }

            break;
        }

        case 2:
        {
            int reading_count = 0;

            total_temperature = 0.0;

            // Start a pointer at the first valid reading.
            double *current_reading = temperatures;

            // Add all valid readings using pointer traversal.
            while (*current_reading != sentinel_value)
            {
                total_temperature += *current_reading;
                reading_count++;

                current_reading++;
            }

            // Calculate the overall average temperature.
            average_temperature = total_temperature / reading_count;

            printf("\nAverage Temperature: %.2f degrees C\n",
                   average_temperature);

            break;
        }

        case 3:
        {
            // Start the pointer at the first temperature reading.
            double *current_reading = temperatures;

            // Use the first real reading as the initial highest and lowest.
            highest_temperature = *current_reading;
            lowest_temperature = *current_reading;

            current_reading++;

            // Traverse the remaining readings using the pointer.
            while (*current_reading != sentinel_value)
            {
                if (*current_reading > highest_temperature)
                {
                    highest_temperature = *current_reading;
                }

                if (*current_reading < lowest_temperature)
                {
                    lowest_temperature = *current_reading;
                }

                current_reading++;
            }

            printf("\nHighest Temperature: %.1f degrees C\n",
                   highest_temperature);

            printf("Lowest Temperature: %.1f degrees C\n",
                   lowest_temperature);

            break;
        }

        case 4:
        {
            // Ask the user for a valid temperature threshold.
            while (1)
            {
                printf("\nEnter temperature threshold: ");

                if (fgets(input, sizeof(input), stdin) == NULL)
                {
                    printf("Error reading input.\n");
                    return 1;
                }

                // Check that the threshold contains exactly one numeric value.
                if (sscanf(input, "%lf %c",
                           &threshold,
                           &extra_character) != 1)
                {
                    printf("Invalid threshold. Please enter a numeric value.\n");
                    continue;
                }

                // Reject NaN and infinity.
                if (!isfinite(threshold))
                {
                    printf("Invalid threshold. Please enter a finite numeric value.\n");
                    continue;
                }

                break;
            }

            int days_above = 0;
            int days_below = 0;

            // Start at the first valid temperature.
            double *current_reading = temperatures;

            // Compare each reading with the threshold using a pointer.
            while (*current_reading != sentinel_value)
            {
                if (*current_reading > threshold)
                {
                    days_above++;
                }
                else if (*current_reading < threshold)
                {
                    days_below++;
                }

                current_reading++;
            }

            printf("\nDays above threshold: %d\n", days_above);
            printf("Days below threshold: %d\n", days_below);

            break;
        }

        case 5:
        {
            int current_index = 0;
            int week_number = 1;

            printf("\nWeekly Averages:\n");

            // Continue until every valid reading has been processed.
            while (current_index < number_of_days)
            {
                double week_total = 0.0;
                int days_in_week = 0;

                // Process up to seven readings for the current week.
                for (int day = 0;
                     day < 7 && current_index < number_of_days;
                     day++)
                {
                    week_total += temperatures[current_index];
                    days_in_week++;
                    current_index++;
                }

                // Calculate the average using only the available readings.
                double week_average = week_total / days_in_week;

                printf("Week %d Average: %.2f degrees C\n",
                       week_number,
                       week_average);

                week_number++;
            }

            break;
        }

        case 6:
        {
            // Fill the reversed array with sentinel values.
            for (int index = 0; index < array_size; index++)
            {
                reversed_temperatures[index] = sentinel_value;
            }

            // Point to the most recent valid reading.
            double *source_pointer =
                temperatures + number_of_days - 1;

            // Point to the beginning of the reversed array.
            double *destination_pointer =
                reversed_temperatures;

            // Point to the first original temperature reading.
            double *first_reading =
                temperatures;

            // Copy the readings into the new array in reverse order.
            while (source_pointer >= first_reading)
            {
                *destination_pointer = *source_pointer;

                destination_pointer++;
                source_pointer--;
            }

            // Mark the end of the reversed readings.
            *destination_pointer = sentinel_value;

            // Start at the first reversed reading.
            double *current_reading =
                reversed_temperatures;

            int days_ago = 0;

            printf("\nReversed Temperature Readings:\n");

            // Display reversed readings using relative-day labels.
            while (*current_reading != sentinel_value)
            {
                if (days_ago == 0)
                {
                    printf("Today: %.1f degrees C\n",
                           *current_reading);
                }
                else if (days_ago == 1)
                {
                    printf("Yesterday: %.1f degrees C\n",
                           *current_reading);
                }
                else
                {
                    printf("%d days ago: %.1f degrees C\n",
                           days_ago,
                           *current_reading);
                }

                current_reading++;
                days_ago++;
            }

            break;
        }

        case 7:
        {
            // Stop the repeating menu and finish the program.
            program_running = 0;

            printf("\nExiting program...\n");

            break;
        }
        }
    }

    return 0;
}
