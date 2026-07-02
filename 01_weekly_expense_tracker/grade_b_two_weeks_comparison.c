/*
Complete all previous steps, then:
• Allow the user to input spending for the same three categories for Week 1 and Week 2.
• Calculate and print the total spending for each week.
• Calculate and print the daily average spending for each week.
• For each week, compare the total spending with the weekly budget and state whether it is within budget or over budget.
• Compare the total spending between Week 1 and Week 2.
• Print whether spending increased, decreased, or stayed the same.
*/

#include <stdio.h>

int main(void)
{
    float week1_budget;
    float week2_budget;

    float food_week1, transport_week1, entertainment_week1;
    float food_week2, transport_week2, entertainment_week2;

    float week1_total_spending;
    float week2_total_spending;

    float week1_daily_average;
    float week2_daily_average;

    printf("=== Weekly Expense Tracker ===\n");

    printf("\nEnter the weekly budget limit for week 1: ");
    scanf("%f", &week1_budget);

    printf("Enter the weekly budget limit for week 2: ");
    scanf("%f", &week2_budget);

    // Validate input for the two weekly budgets
    if (week1_budget < 0 || week2_budget < 0)
    {
        printf("Invalid input. Budget cannot be negative.\n");
        return 1;
    }

    printf("Enter week 1 expenses. \n");
    printf("Food: ");
    scanf("%f", &food_week1);
    printf("Transport: ");
    scanf("%f", &transport_week1);
    printf("Entertainment: ");
    scanf("%f", &entertainment_week1);

    // Validate input for week 1 spending
    if (food_week1 < 0 || transport_week1 < 0 || entertainment_week1 < 0)
    {
        printf("Invalid input. Spending cannot be negative.\n");
        return 1;
    }

    printf("Week 1 expenses recorded successfully.\n");

    printf("Enter week 2 expenses. \n");
    printf("Food: ");
    scanf("%f", &food_week2);
    printf("Transport: ");
    scanf("%f", &transport_week2);
    printf("Entertainment: ");
    scanf("%f", &entertainment_week2);

    // Validate input for week 2 spending
    if (food_week2 < 0 || transport_week2 < 0 || entertainment_week2 < 0)
    {
        printf("Invalid input. Spending cannot be negative.\n");
        return 1;
    }

    printf("Week 2 expenses recorded successfully.\n");

    week1_total_spending = food_week1 + transport_week1 + entertainment_week1;
    week2_total_spending = food_week2 + transport_week2 + entertainment_week2;

    week1_daily_average = week1_total_spending / 7.0f;
    week2_daily_average = week2_total_spending / 7.0f;

    printf("\n=== Week 1 Summary ===\n");
    printf("Food: $%.2f\n", food_week1);
    printf("Transport: $%.2f\n", transport_week1);
    printf("Entertainment: $%.2f\n", entertainment_week1);
    printf("Total spending: $%.2f\n", week1_total_spending);
    printf("Daily average spending: $%.2f\n", week1_daily_average);

    // Compare week 1 budget to spendings
    if (week1_total_spending <= week1_budget)
    {
        printf("User is within the budget for week 1.\n");
    }
    else
    {
        float difference = week1_total_spending - week1_budget;
        printf("User is over the budget for week 1 with: $%.2f\n", difference);
    }

    printf("\n=== Week 2 Summary ===\n");
    printf("Food: $%.2f\n", food_week2);
    printf("Transport: $%.2f\n", transport_week2);
    printf("Entertainment: $%.2f\n", entertainment_week2);
    printf("Total spending: $%.2f\n", week2_total_spending);
    printf("Daily average spending: $%.2f\n", week2_daily_average);

    // Compare week 2 budget to spendings
    if (week2_total_spending <= week2_budget)
    {
        printf("User is within the budget for week 2.\n");
    }
    else
    {
        float difference = week2_total_spending - week2_budget;
        printf("User is over the budget for week 2 with: $%.2f\n", difference);
    }

    printf("\n=== Weekly Spending Comparison ===\n");

    // Compare total spendings between week 1 and week 2
    if (week2_total_spending > week1_total_spending)
    {
        float difference = week2_total_spending - week1_total_spending;
        printf("The spending has increased by: $%.2f\n", difference);
    }
    else if (week2_total_spending < week1_total_spending)
    {
        float difference = week1_total_spending - week2_total_spending;
        printf("The spending has decreased by: $%.2f\n", difference);
    }
    else
    {
        printf("The spending stays the same.\n");
    }

    return 0;
}
