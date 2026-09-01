#include <stdio.h>

int main(void)
{
    int steps_per_day;
    double distance_km;
    double estimated_kcal;

    const int STEPS_PER_KM = 1250;
    const int CALORIES_PER_1000_STEPS = 40;
    const int STEP_PER_CALORIE_RATE = 1000;

    printf("Enter steps for today: ");

    if (scanf("%d", &steps_per_day) != 1)
    {
        printf("Invalid input. Please enter a whole number.\n");
        return 1;
    }

    if (steps_per_day < 0)
    {
        printf("Steps cannot be a negative number.");
        return 1;
    }

    distance_km = (double)steps_per_day / STEPS_PER_KM;
    estimated_kcal = ((double)steps_per_day / STEP_PER_CALORIE_RATE) * CALORIES_PER_1000_STEPS;

    printf("Distance: %.2f km\n", distance_km);
    printf("Calories burned: %.2f kcal\n", estimated_kcal);

    return 0;
}
