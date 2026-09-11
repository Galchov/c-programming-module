/*
Grade B - Group Discount and Optional Snack Add-On

Build on Grade C and keep using switch/case with the same cinema ticket prices.

The program:
1. Asks the user to enter:
    - Movie type: A, C, or H
    - Ticket type: S or P
    - Number of tickets
    - Snack combo choice: y or n
2. Validates each input immediately.
3. Uses switch/case to determine the ticket price.
4. Applies a 10% group discount when more than 6 tickets are booked.
5. Adds an optional snack combo costing £5.50 per ticket.
6. Displays the booking details, total before discount, discount amount,
   snack combo cost, and final total cost.
*/

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    char movie_type;
    char ticket_type;
    char snack_combo_choice;

    int number_of_tickets;

    float ticket_price = 0.0f;
    float total_before_discount = 0.0f;
    float discount_amount = 0.0f;
    float snack_combo_cost = 0.0f;
    float final_total = 0.0f;

    const float group_discount_rate = 0.10f;
    const float snack_combo_price = 5.50f;

    // Get and validate the movie type.
    printf("Enter movie type (A - Action, C - Comedy, H - Horror): ");
    scanf(" %c", &movie_type);

    switch (movie_type)
    {
    case 'a':
    case 'A':
    case 'c':
    case 'C':
    case 'h':
    case 'H':
        break;

    default:
        printf("Invalid movie type.\n");
        return 1;
    }

    // Get and validate the ticket type.
    printf("Enter ticket type (S - Standard, P - Premium): ");
    scanf(" %c", &ticket_type);

    switch (ticket_type)
    {
    case 's':
    case 'S':
    case 'p':
    case 'P':
        break;

    default:
        printf("Invalid ticket type.\n");
        return 1;
    }

    // Get and validate the number of tickets.
    printf("Enter number of tickets: ");

    if (scanf("%d", &number_of_tickets) != 1)
    {
        printf("Invalid number of tickets.\n");
        return 1;
    }

    if (number_of_tickets <= 0)
    {
        printf("Invalid number of tickets.\n");
        return 1;
    }

    // Get and validate the snack combo choice.
    printf("Would you like a snack combo for each ticket? (y/n): ");
    scanf(" %c", &snack_combo_choice);

    switch (snack_combo_choice)
    {
    case 'y':
    case 'Y':
    case 'n':
    case 'N':
        break;

    default:
        printf("Invalid snack combo choice.\n");
        return 1;
    }

    // Determine the ticket price.
    switch (movie_type)
    {
    case 'a':
    case 'A':

        switch (ticket_type)
        {
        case 's':
        case 'S':
            ticket_price = 10.00f;
            break;

        case 'p':
        case 'P':
            ticket_price = 15.00f;
            break;
        }

        break;

    case 'c':
    case 'C':

        switch (ticket_type)
        {
        case 's':
        case 'S':
            ticket_price = 8.00f;
            break;

        case 'p':
        case 'P':
            ticket_price = 13.00f;
            break;
        }

        break;

    case 'h':
    case 'H':

        switch (ticket_type)
        {
        case 's':
        case 'S':
            ticket_price = 9.00f;
            break;

        case 'p':
        case 'P':
            ticket_price = 14.00f;
            break;
        }

        break;
    }

    // Calculate the ticket total before discount.
    total_before_discount = ticket_price * number_of_tickets;

    // Apply a 10% discount when more than 6 tickets are booked.
    if (number_of_tickets > 6)
    {
        discount_amount = total_before_discount * group_discount_rate;
    }

    // Add one snack combo per ticket if selected.
    if (snack_combo_choice == 'y' || snack_combo_choice == 'Y')
    {
        snack_combo_cost = snack_combo_price * number_of_tickets;
    }

    // Calculate the final cost.
    final_total = total_before_discount - discount_amount + snack_combo_cost;

    // Display the movie type.
    printf("\nMovie Type: ");

    switch (movie_type)
    {
    case 'a':
    case 'A':
        printf("Action");
        break;

    case 'c':
    case 'C':
        printf("Comedy");
        break;

    case 'h':
    case 'H':
        printf("Horror");
        break;
    }

    // Display the ticket type.
    printf("\nTicket Type: ");

    switch (ticket_type)
    {
    case 's':
    case 'S':
        printf("Standard Seat");
        break;

    case 'p':
    case 'P':
        printf("Premium Seat");
        break;
    }

    // Display the final booking summary.
    printf("\nTickets: %d", number_of_tickets);
    printf("\nSnack Combo: %c", snack_combo_choice);
    printf("\nTotal Before Discount: £%.2f", total_before_discount);
    printf("\nGroup Discount 10%%: -£%.2f", discount_amount);
    printf("\nSnack Combo Cost: £%.2f", snack_combo_cost);
    printf("\nFinal Total: £%.2f\n", final_total);

    return 0;
}
