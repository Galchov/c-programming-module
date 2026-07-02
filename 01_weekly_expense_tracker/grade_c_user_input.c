/*
• Ask the user to enter weekly spending for the three categories.
• Calculate the total weekly spending.
• Calculate the daily average spending.
• Compare the total weekly spending with a weekly budget limit chosen by you.
• Print whether the user is “Within budget” or “Over budget.”
• Include basic validation: If any value is negative, print 'Invalid input. Spending cannot be negative.' and terminate the program.
*/

#include <stdio.h>

int main(void)
{
    // Array to store all the three expenses
    float expenses[3];
    // Array of strings to store the specific categories names
    const char *categories[3] = {"food", "transport", "entertainment"};
    // Set variable to determine the total weekly spending limit
    float weekly_spend_limit;

    for (int i = 0; i < 3; i++)
    {
        printf("Please enter the amount for %s: ", categories[i]);

        // Check if the input is a valid number
        if (scanf("%f", &expenses[i]) != 1)
        {
            printf("Invalid input. Please enter numbers only.\n");
            return 1;
        }

        // Chech for negative values
        if (expenses[i] < 0.0f)
        {
            printf("Invalid input. Spending cannot be negative.");
            return 1;
        }
    }

    float food = expenses[0];
    float transport = expenses[1];
    float entertainment = expenses[2];

    // Prompt the user to input the limit for weekly spendings
    printf("Enter the weekly spedning limit: ");
    scanf("%f", &weekly_spend_limit);

    // Calculate total weekly spending
    float total = food + transport + entertainment;
    printf("Total: $%.2f\n", total);

    // Calculate the daily average spending
    float daily_average = total / 7;
    printf("Daily average: $%.2f\n", daily_average);

    if (total <= weekly_spend_limit)
    {
        printf("User is within the budget.");
    }
    else
    {
        float difference = total - weekly_spend_limit;
        printf("User is over the budget with $%.2f", difference);
    }

    return 0;
}
