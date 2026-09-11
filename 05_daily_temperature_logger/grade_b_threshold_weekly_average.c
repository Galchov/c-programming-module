/*
    This program allows the user to record temperature readings for up to
    30 days and stores the readings in a fixed-size array.

    A sentinel value is used to mark the end of the valid temperature
    readings stored in the array.

    The program provides a repeating menu that allows the user to:
    1. Display all recorded temperature readings.
    2. Calculate and display the overall average temperature.
    3. Find and display the highest and lowest temperatures.
    4. Count the number of days above and below a user-defined threshold.
    5. Calculate and display weekly average temperatures.
    7. Exit the program.

    Each week contains up to seven temperature readings, starting from
    day 1. If the final week contains fewer than seven days, its average
    is calculated using only the available readings.

    All user inputs are validated. Invalid input displays an appropriate
    error message and the user is asked to enter the value again.
*/

#include <stdio.h>

int main(void)
{
    const int max_days = 30;
    const int array_size = 50;
    const double sentinel_value = -999999.0;

    int number_of_days;
    int choice;
    int program_running = 1;

    double temperatures[array_size];

    double total_temperature;
    double average_temperature;
    double highest_temperature;
    double lowest_temperature;
    double threshold;

    char input[100];
    char extra_character;

    // Fill the fixed-size array with the sentinel value.
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

        // Check that the number of days is between 1 and 30.
        if (number_of_days < 1 || number_of_days > max_days)
        {
            printf("Invalid number of days. Please enter a number between 1 and %d.\n\n",
                   max_days);
            continue;
        }

        break;
    }

    printf("\n");

    // Ask the user to enter one valid temperature for each day.
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

            // Check that the temperature contains exactly one numeric value.
            if (sscanf(input, "%lf %c",
                       &temperatures[day],
                       &extra_character) != 1)
            {
                printf("Invalid temperature. Please enter a numeric value.\n\n");
                continue;
            }

            // Prevent the reserved sentinel value from being entered as a temperature.
            if (temperatures[day] == sentinel_value)
            {
                printf("Invalid temperature. Please enter a different value.\n\n");
                continue;
            }

            break;
        }
    }

    // The next unused position remains the sentinel marking the end of valid entries.
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

            // Check that the entered number is an available menu option.
            if (choice != 1 &&
                choice != 2 &&
                choice != 3 &&
                choice != 4 &&
                choice != 5 &&
                choice != 7)
            {
                printf("Invalid menu choice. Please enter 1, 2, 3, 4, 5, or 7.\n");
                continue;
            }

            break;
        }

        // Perform the selected menu action.
        switch (choice)
        {
        case 1:
        {
            printf("\nTemperature Readings:\n");

            // Display readings until the sentinel value is reached.
            for (int day = 0;
                 day < array_size && temperatures[day] != sentinel_value;
                 day++)
            {
                printf("Day %d: %.1f degrees C\n",
                       day + 1,
                       temperatures[day]);
            }

            break;
        }

        case 2:
        {
            total_temperature = 0.0;
            int reading_count = 0;

            // Add all valid readings until the sentinel is reached.
            for (int index = 0;
                 index < array_size && temperatures[index] != sentinel_value;
                 index++)
            {
                total_temperature += temperatures[index];
                reading_count++;
            }

            // Calculate the overall average temperature.
            average_temperature = total_temperature / reading_count;

            printf("\nAverage Temperature: %.2f degrees C\n",
                   average_temperature);

            break;
        }

        case 3:
        {
            // Use the first valid reading as the starting highest and lowest.
            highest_temperature = temperatures[0];
            lowest_temperature = temperatures[0];

            // Compare all remaining valid readings.
            for (int index = 1;
                 index < array_size && temperatures[index] != sentinel_value;
                 index++)
            {
                if (temperatures[index] > highest_temperature)
                {
                    highest_temperature = temperatures[index];
                }

                if (temperatures[index] < lowest_temperature)
                {
                    lowest_temperature = temperatures[index];
                }
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

                // Prevent the reserved sentinel value from being used as a threshold.
                if (threshold == sentinel_value)
                {
                    printf("Invalid threshold. Please enter a different value.\n");
                    continue;
                }

                break;
            }

            int days_above = 0;
            int days_below = 0;

            // Compare each valid reading with the chosen threshold.
            for (int index = 0;
                 index < array_size && temperatures[index] != sentinel_value;
                 index++)
            {
                if (temperatures[index] > threshold)
                {
                    days_above++;
                }
                else if (temperatures[index] < threshold)
                {
                    days_below++;
                }
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

            // Process the valid readings one week at a time.
            while (current_index < array_size &&
                   temperatures[current_index] != sentinel_value)
            {
                double week_total = 0.0;
                int days_in_week = 0;

                // Add up to seven readings for the current week.
                for (int day = 0;
                     day < 7 &&
                     current_index < array_size &&
                     temperatures[current_index] != sentinel_value;
                     day++)
                {
                    week_total += temperatures[current_index];
                    days_in_week++;
                    current_index++;
                }

                // Calculate the average using only the available days.
                double week_average = week_total / days_in_week;

                printf("Week %d Average: %.2f degrees C\n",
                       week_number,
                       week_average);

                week_number++;
            }

            break;
        }

        case 7:
        {
            // Stop the menu loop and finish the program.
            program_running = 0;

            printf("\nExiting program...\n");

            break;
        }
        }
    }

    return 0;
}
