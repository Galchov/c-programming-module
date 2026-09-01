#include <stdio.h>

int main(void)
{
    int steps_per_day;
    int days_tracked = 0;
    int total_steps = 0;

    double distance_km;
    double estimated_cal;
    double total_distance = 0.0;
    double total_calories = 0.0;

    char add_another_day;

    const int STEPS_PER_KM = 1250;
    const int STEPS_PER_CALORIE_RATE = 1000;
    const int CALORIES_PER_1000_STEPS = 40;

    do
    {
        printf("Enter steps for today: ");

        if (scanf("%d", &steps_per_day) != 1)
        {
            printf("Invalid input. Please enter a whole number.\n");
            return 1;
        }

        if (steps_per_day < 0)
        {
            printf("Steps cannot be a negative number.\n");
            return 1;
        }

        distance_km = (double)steps_per_day / STEPS_PER_KM;

        estimated_cal =
            ((double)steps_per_day / STEPS_PER_CALORIE_RATE) * CALORIES_PER_1000_STEPS;

        printf("Distance: %.2f km | Calories: %.2f kcal\n",
               distance_km, estimated_cal);

        days_tracked++;
        total_steps += steps_per_day;
        total_distance += distance_km;
        total_calories += estimated_cal;

        printf("Add another day? (y/n): ");
        scanf(" %c", &add_another_day);

    } while (add_another_day == 'y' || add_another_day == 'Y');

    printf("\nYou tracked %d days.\n", days_tracked);
    printf("Total Steps: %d\n", total_steps);
    printf("Total Distance: %.2f km\n", total_distance);
    printf("Total Calories: %.2f kcal\n", total_calories);

    return 0;
}
