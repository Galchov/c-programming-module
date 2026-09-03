/*
    This program allows the user to choose how many days of temperature
    readings they want to record, up to a maximum of 30 days.

    The temperatures are stored in an array.

    The user can then choose one of two menu options:
    1. Display all recorded temperature readings.
    2. Calculate and display the overall average temperature.

    The program also validates user input. Invalid values display an
    appropriate error message and the user is asked to enter the value again.
*/

#include <stdio.h>

int main(void)
{
    const int MAX_DAYS = 30;

    int number_of_days;
    int choice;

    double total_temperature = 0.0;
    double average_temperature;

    char input[100];
    char extra_character;

    // Ask for the number of days and validate the input.
    while (1)
    {
        printf("How many days do you want to record? ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading input.\n");
            return 1;
        }

        /*
            sscanf() should successfully read exactly one integer.

            The extra_character variable helps detect invalid input such as:
            5abc
            3.5
            hello
        */
        if (sscanf(input, "%d %c", &number_of_days, &extra_character) != 1)
        {
            printf("Invalid input. Please enter a whole number.\n\n");
            continue;
        }

        if (number_of_days < 1 || number_of_days > MAX_DAYS)
        {
            printf("Invalid number of days. Please enter a number between 1 and %d.\n\n", MAX_DAYS);
            continue;
        }

        break;
    }

    // Create the temperature array using the valid number of days entered by the user.

    double temperatures[number_of_days];

    printf("\n");

    // Ask for and validate a temperature for every day.
    for (int day = 0; day < number_of_days; day++)
    {
        while (1)
        {
            printf("Enter temperature for day %d: ", day + 1);

            if (fgets(input, sizeof(input), stdin) == NULL)
            {
                printf("Error reading input.\n");
                return 1;
            }

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

    // Display the Grade D menu.
    printf("\nMenu:\n");
    printf("1. Display all temperature readings\n");
    printf("2. Calculate average temperature\n");

    // Validate the menu choice.
    while (1)
    {
        printf("\nEnter choice: ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading input.\n");
            return 1;
        }

        if (sscanf(input, "%d %c", &choice, &extra_character) != 1)
        {
            printf("Invalid input. Please enter a whole number.\n");
            continue;
        }

        if (choice != 1 && choice != 2)
        {
            printf("Invalid menu choice. Please enter 1 or 2.\n");
            continue;
        }

        break;
    }

    // Menu option 1: Display all temperature readings.
    if (choice == 1)
    {
        printf("\nTemperature Readings:\n");

        for (int day = 0; day < number_of_days; day++)
        {
            printf("Day %d: %.1f degrees C\n",
                   day + 1,
                   temperatures[day]);
        }
    }

    // Menu option 2: Calculate the overall average temperature.
    else if (choice == 2)
    {
        for (int day = 0; day < number_of_days; day++)
        {
            total_temperature += temperatures[day];
        }

        average_temperature = total_temperature / number_of_days;

        printf("\nAverage Temperature: %.2f degrees C\n", average_temperature);
    }

    return 0;
}
