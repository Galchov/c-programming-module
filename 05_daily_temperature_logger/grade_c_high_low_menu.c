/*
    This program allows the user to record temperature readings for up to
    30 days and stores the readings in an array.

    After the temperatures are entered, the program displays a menu that
    allows the user to:
    1. Display all recorded temperature readings.
    2. Calculate and display the overall average temperature.
    3. Find and display the highest and lowest temperatures.
    7. Exit the program.

    The menu repeats until the user chooses to exit. All user inputs are
    validated, and invalid input displays an appropriate error message
    before asking the user to enter the value again.
*/

#include <stdio.h>

int main(void)
{
    const int MAX_DAYS = 30;

    int number_of_days;
    int choice;
    int program_running = 1;

    double total_temperature;
    double average_temperature;
    double highest_temperature;
    double lowest_temperature;

    char input[100];
    char extra_character;

    // Ask the user how many days they want to record.
    while (1)
    {
        printf("How many days do you want to record? ");

        // Read the complete line of user input.
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
        if (number_of_days < 1 || number_of_days > MAX_DAYS)
        {
            printf("Invalid number of days. Please enter a number between 1 and %d.\n\n",
                   MAX_DAYS);
            continue;
        }

        break;
    }

    // Create an array using the valid number of days entered by the user.
    double temperatures[number_of_days];

    printf("\n");

    // Ask the user to enter a temperature for each day.
    for (int day = 0; day < number_of_days; day++)
    {
        while (1)
        {
            printf("Enter temperature for day %d: ", day + 1);

            // Read the complete temperature input.
            if (fgets(input, sizeof(input), stdin) == NULL)
            {
                printf("Error reading input.\n");
                return 1;
            }

            // Check that the temperature is a valid numeric value.
            if (sscanf(input, "%lf %c",
                       &temperatures[day],
                       &extra_character) != 1)
            {
                printf("Invalid temperature. Please enter a numeric value.\n\n");
                continue;
            }

            break;
        }
    }

    // Keep displaying the menu until the user chooses to exit.
    while (program_running)
    {
        printf("\nMenu:\n");
        printf("1. Display all temperature readings\n");
        printf("2. Calculate average temperature\n");
        printf("3. Find highest and lowest temperature\n");
        printf("7. Exit\n");

        // Validate the menu input before processing the choice.
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

            // Check that the entered number is one of the available menu choices.
            if (choice != 1 &&
                choice != 2 &&
                choice != 3 &&
                choice != 7)
            {
                printf("Invalid menu choice. Please enter 1, 2, 3, or 7.\n");
                continue;
            }

            break;
        }

        // Perform the selected menu action.
        switch (choice)
        {
        case 1:
            printf("\nTemperature Readings:\n");

            // Display every temperature stored in the array.
            for (int day = 0; day < number_of_days; day++)
            {
                printf("Day %d: %.1f degrees C\n",
                       day + 1,
                       temperatures[day]);
            }

            break;

        case 2:
            // Reset the total before calculating the average.
            total_temperature = 0.0;

            // Add all recorded temperatures together.
            for (int day = 0; day < number_of_days; day++)
            {
                total_temperature += temperatures[day];
            }

            // Calculate the overall average temperature.
            average_temperature = total_temperature / number_of_days;

            printf("\nAverage Temperature: %.2f degrees C\n",
                   average_temperature);

            break;

        case 3:
            // Start both values with the first recorded temperature.
            highest_temperature = temperatures[0];
            lowest_temperature = temperatures[0];

            // Compare the remaining readings with the current highest and lowest.
            for (int day = 1; day < number_of_days; day++)
            {
                if (temperatures[day] > highest_temperature)
                {
                    highest_temperature = temperatures[day];
                }

                if (temperatures[day] < lowest_temperature)
                {
                    lowest_temperature = temperatures[day];
                }
            }

            printf("\nHighest Temperature: %.1f degrees C\n",
                   highest_temperature);
            printf("Lowest Temperature: %.1f degrees C\n",
                   lowest_temperature);

            break;

        case 7:
            // Change the loop-control variable so the program can finish.
            program_running = 0;

            printf("\nExiting program...\n");

            break;
        }
    }

    return 0;
}
