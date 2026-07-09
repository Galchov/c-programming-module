/*
Create a basic program that calculates the price of one cinema ticket using fixed values.
Your program should:
1. Create variables to store:
    o movieType
        ▪ A = Action
        ▪ C = Comedy
        ▪ H = Horror
    o ticketType
        ▪ S = Standard Seat
        ▪ P = Premium Seat
    o ticketPrice
2. Choose any fixed default values for movieType and ticketType. No user input is required.
3. Use a switch statement to set ticket prices based on the following table:
Movie Type | Standard Seat | Premium Seat
Action     |     £10.00    |    £15.00
Comedy     |     £8.00     |    £13.00
Horror     |     £9.00     |    £14.00
4. Display:
    o Movie type
    o Ticket type
    o Ticket price formatted to 2 decimal places
Example Outcome:
    Movie Type: Action
    Ticket Type: Standard Seat
    Ticket Price: £10.00
*/

#include <stdio.h>

int main(void)
{
    char movie_type = 'x';  // A - Action, C - Comedy, H - Horror
    char ticket_type = 'm'; // S - Standard, P - Premium
    float ticket_price = 0.0f;

    char error_message_movies[] = "Invalid movie type code.";
    char error_message_tickets[] = "Invalid ticket type code.";

    switch (movie_type)
    {
    case 'a':
    case 'A':
        if (ticket_type == 'S' || ticket_type == 's')
        {
            ticket_price = 10.00;
        }
        else if (ticket_type == 'P' || ticket_type == 'p')
        {
            ticket_price = 15.00;
        }
        else
        {
            printf("%s", error_message_tickets);
            return 1;
        }
        break;

    case 'c':
    case 'C':
        if (ticket_type == 'S' || ticket_type == 's')
        {
            ticket_price = 8.00;
        }
        else if (ticket_type == 'P' || ticket_type == 'p')
        {
            ticket_price = 13.00;
        }
        else
        {
            printf("%s", error_message_tickets);
            return 1;
        }
        break;

    case 'h':
    case 'H':
        if (ticket_type == 'S' || ticket_type == 's')
        {
            ticket_price = 9.00;
        }
        else if (ticket_type == 'P' || ticket_type == 'p')
        {
            ticket_price = 14.00;
        }
        else
        {
            printf("%s", error_message_tickets);
            return 1;
        }
        break;

    default:
        printf("%s", error_message_movies);
        return 1;
    }

    printf("Movie type: ");

    switch (movie_type)
    {
    case 'a':
    case 'A':
        printf("Action.");
        break;
    case 'h':
    case 'H':
        printf("Horror.");
        break;
    case 'c':
    case 'C':
        printf("Comedy.");
        break;
    default:
        printf("%s", error_message_movies);
        return 1;
    }

    printf("\nTicket type: ");

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
    default:
        printf("%s", error_message_tickets);
        return 1;
    }

    printf("\nTicket price: $%.2f", ticket_price);

    return 0;
}
