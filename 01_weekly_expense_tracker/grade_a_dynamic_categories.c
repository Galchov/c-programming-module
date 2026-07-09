/*
Complete all previous steps, then:
• Ask the user how many spending categories they want to track.
• Allow the user to enter the name of each category, for example Food, Transport, Entertainment, Bills, or Shopping.
• For two weeks, collect the spending amount for each category.
• Print a detailed breakdown for each week, including:
• Category names
• Spending amount for each category
• Weekly total
• Daily average
• Budget status
    o For each category, compare Week 1 spending with Week 2 spending.
    o Identify whether each category has increased, decreased, or stayed the same.
    o Clearly summarise:
        ▪ Week 1 total
        ▪ Week 2 total
        ▪ Overall spending trend should indicate whether total spending increased, decreased, or remain unchanged between Week 1 and Week 2
        ▪ Daily averages
        ▪ Per-category spending trends
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 10
#define MAX_LENGTH 50

int main(void)
{
    int number_of_categories;

    char categories[MAX_ITEMS][MAX_LENGTH];

    float week1_categories_spendings[MAX_ITEMS];
    float week2_categories_spendings[MAX_ITEMS];

    float week1_total = 0.0f;
    float week2_total = 0.0f;

    float week1_daily_average = 0.0f;
    float week2_daily_average = 0.0f;

    printf("How many categories you want to enter? ");
    scanf("%d", &number_of_categories);

    // Clear leftover newline after scanf
    getchar();

    if (number_of_categories < 1 || number_of_categories > MAX_ITEMS)
    {
        printf("Please enter a number between 1 and %d\n", MAX_ITEMS);
        return 1;
    }

    for (int i = 0; i < number_of_categories; i++)
    {
        printf("Enter for item %d: ", i + 1);
        fgets(categories[i], MAX_LENGTH, stdin);

        categories[i][strcspn(categories[i], "\n")] = '\0';
    }

    printf("=== These are the current categories===\n");
    for (int i = 0; i < number_of_categories; i++)
    {
        printf("%d. %s\n", i + 1, categories[i]);
        // printf("Current index: %d\n", i);
    }

    // Input spendings for each week
    for (int i = 0; i < 2; i++)
    {
        // Input for week 1
        if (i == 0)
        {
            printf("=== Week 1 spending ===\n");
            for (int i = 0; i < number_of_categories; i++)
            {
                printf("Input %s spending for week 1: ", categories[i]);
                scanf("%f", &week1_categories_spendings[i]);
            }
        }
        // Input for week 2
        else if (i == 1)
        {
            printf("=== Week 2 spending ===\n");
            for (int i = 0; i < number_of_categories; i++)
            {
                printf("Input %s spending for week 2: ", categories[i]);
                scanf("%f", &week2_categories_spendings[i]);
            }
        }
    }

    // Week 1 summary
    printf("\n=== Week 1 summary ===\n");

    for (int i = 0; i < number_of_categories; i++)
    {
        char *current_cat = categories[i];
        float current_spending = week1_categories_spendings[i];
        printf("%s: $%.2f\n", current_cat, current_spending);
    }

    for (int i = 0; i < number_of_categories; i++)
    {
        float current_spending = week1_categories_spendings[i];
        week1_total += current_spending;
    }

    week1_daily_average = week1_total / 7;

    printf("Week 1 total spending: $%.2f\n", week1_total);
    printf("Week 1 daily average spending: $%.2f\n", week1_daily_average);

    // Week 2 summary
    printf("\n=== Week 2 summary ===\n");

    for (int i = 0; i < number_of_categories; i++)
    {
        char *current_cat = categories[i];
        float current_spending = week2_categories_spendings[i];
        printf("%s: $%.2f\n", current_cat, current_spending);
    }

    for (int i = 0; i < number_of_categories; i++)
    {
        float current_spending = week2_categories_spendings[i];
        week2_total += current_spending;
    }

    week2_daily_average = week2_total / 7;

    printf("Week 2 total spending: $%.2f\n", week2_total);
    printf("Week 2 daily average spending: $%.2f\n", week2_daily_average);

    // Budget status
    printf("\n=== Budget status ===\n");

    float difference = fabsf(week2_total - week1_total);

    if (week1_total == week2_total)
    {
        printf("Spending remains unchanged.\n");
    }
    else if (week1_total < week2_total)
    {
        printf("Spending increased with $%.2f", difference);
    }
    else
    {
        printf("Spending decreased with $%.2f", difference);
    }

    return 0;
}
