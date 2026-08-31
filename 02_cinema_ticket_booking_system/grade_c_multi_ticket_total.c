/*
Grade C - User Input and Multi-Ticket Total

Build on Grade D and keep using switch/case.

The program:
1. Asks the user to enter:
    - Movie type: A, C, or H
    - Ticket type: S or P
    - Number of tickets
2. Validates each input immediately.
3. Uses switch/case to determine the ticket price.
4. Calculates the total cost.
5. Displays:
    - Movie type
    - Ticket type
    - Number of tickets
    - Total cost
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

    int number_of_tickets;

    float ticket_price = 0.0f;
    float total_cost = 0.0f;

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

    total_cost = ticket_price * number_of_tickets;

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

    printf("\nTickets: %d", number_of_tickets);
    printf("\nTotal Cost: £%.2f\n", total_cost);

    return 0;
}
