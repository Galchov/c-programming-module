/*
• Create variables for any three expense categories, for example Food, Transport, and
Entertainment.
• Assign spending values directly in the code. No user input is required.
• Calculate and print the total weekly spending.
• Display a clear label for each category and the total amount spent
*/

#include <stdio.h>

int main(void)
{
    // Weekly expenses amounts in US dollars
    float food_expenses = 85.50;
    float transport_expenses = 30.85;
    float entertainment_expenses = 60.00;

    // Calculating the total weekly spending
    float total_expenses = food_expenses + transport_expenses + entertainment_expenses;

    // Display the results
    printf("=== Weekly Expense Tracker ===\n");
    printf("Food:           $%.2f\n", food_expenses);
    printf("Transport:      $%.2f\n", transport_expenses);
    printf("Entertainment:  $%.2f\n", entertainment_expenses);

    printf("--------------------------\n");
    printf("Total expenses: $%.2f\n", total_expenses);

    return 0;
}
