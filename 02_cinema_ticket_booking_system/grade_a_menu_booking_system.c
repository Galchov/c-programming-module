/*
    This Grade A program extends the cinema ticket booking system into a repeating
    menu-driven application. It allows the user to book tickets, view ticket prices,
    validates all inputs, applies discounts and snack costs, and displays a full
    booking summary.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define INPUT_SIZE 100

int read_int(const char *prompt);
int read_positive_int(const char *prompt);
char read_choice(const char *prompt, const char *valid_choices);

double get_ticket_price(char movie_type, char ticket_type);

const char *get_movie_name(char movie_type);
const char *get_ticket_name(char ticket_type);

void view_ticket_prices(void);
void book_tickets(void);

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    int menu_choice;
    int running = 1;

    // Keep displaying the menu until the user chooses to exit.
    while (running)
    {
        printf("\n--- Cinema Ticket Booking System ---\n");
        printf("1. Book Tickets\n");
        printf("2. View Ticket Prices\n");
        printf("3. Exit\n");

        menu_choice = read_int("Enter choice: ");

        // Control the main menu using switch/case.
        switch (menu_choice)
        {
        case 1:
            book_tickets();
            break;

        case 2:
            view_ticket_prices();
            break;

        case 3:
            printf("Exiting program...\n");
            running = 0;
            break;

        default:
            printf("Invalid menu choice. Please enter 1, 2, or 3.\n");
            break;
        }
    }

    return 0;
}

int read_int(const char *prompt)
{
    char input[INPUT_SIZE];
    char *end_pointer;
    long value;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Input error. Please try again.\n");
            continue;
        }

        value = strtol(input, &end_pointer, 10);

        // Ignore whitespace after the entered number.
        while (isspace((unsigned char)*end_pointer))
        {
            end_pointer++;
        }

        // Reject input that is not a valid whole number.
        if (end_pointer == input ||
            *end_pointer != '\0' ||
            value < INT_MIN ||
            value > INT_MAX)
        {
            printf("Invalid input. Please enter a whole number.\n");
            continue;
        }

        return (int)value;
    }
}

int read_positive_int(const char *prompt)
{
    int value;

    while (1)
    {
        value = read_int(prompt);

        // Ticket quantity must always be greater than zero.
        if (value > 0)
        {
            return value;
        }

        printf("Invalid ticket count. Please enter a number greater than 0.\n");
    }
}

char read_choice(const char *prompt, const char *valid_choices)
{
    char input[INPUT_SIZE];
    char choice;
    int index;
    int valid_choice;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Input error. Please try again.\n");
            continue;
        }

        index = 0;

        // Ignore whitespace before the entered character.
        while (isspace((unsigned char)input[index]))
        {
            index++;
        }

        choice = (char)toupper((unsigned char)input[index]);

        if (choice == '\0')
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        index++;

        // Ignore whitespace after the entered character.
        while (isspace((unsigned char)input[index]))
        {
            index++;
        }

        // Reject input containing more than one non-whitespace character.
        if (input[index] != '\0')
        {
            printf("Invalid choice. Please enter one valid character.\n");
            continue;
        }

        valid_choice = 0;

        // Check whether the entered character is one of the allowed choices.
        for (index = 0; valid_choices[index] != '\0'; index++)
        {
            if (choice == valid_choices[index])
            {
                valid_choice = 1;
                break;
            }
        }

        if (valid_choice)
        {
            return choice;
        }

        printf("Invalid choice. Please try again.\n");
    }
}

double get_ticket_price(char movie_type, char ticket_type)
{
    double ticket_price = 0.0;

    // Determine the correct ticket price using switch/case.
    switch (movie_type)
    {
    case 'A':
        switch (ticket_type)
        {
        case 'S':
            ticket_price = 10.00;
            break;

        case 'P':
            ticket_price = 15.00;
            break;
        }
        break;

    case 'C':
        switch (ticket_type)
        {
        case 'S':
            ticket_price = 8.00;
            break;

        case 'P':
            ticket_price = 13.00;
            break;
        }
        break;

    case 'H':
        switch (ticket_type)
        {
        case 'S':
            ticket_price = 9.00;
            break;

        case 'P':
            ticket_price = 14.00;
            break;
        }
        break;
    }

    return ticket_price;
}

const char *get_movie_name(char movie_type)
{
    switch (movie_type)
    {
    case 'A':
        return "Action";

    case 'C':
        return "Comedy";

    case 'H':
        return "Horror";

    default:
        return "Unknown";
    }
}

const char *get_ticket_name(char ticket_type)
{
    switch (ticket_type)
    {
    case 'S':
        return "Standard Seat";

    case 'P':
        return "Premium Seat";

    default:
        return "Unknown";
    }
}

void view_ticket_prices(void)
{
    printf("\n--- Ticket Prices ---\n");
    printf("%-12s %-16s %-16s\n",
           "Movie Type",
           "Standard Seat",
           "Premium Seat");

    printf("%-12s £%-15.2f £%-15.2f\n",
           "Action",
           10.00,
           15.00);

    printf("%-12s £%-15.2f £%-15.2f\n",
           "Comedy",
           8.00,
           13.00);

    printf("%-12s £%-15.2f £%-15.2f\n",
           "Horror",
           9.00,
           14.00);
}

void book_tickets(void)
{
    const double group_discount_rate = 0.10;
    const double snack_combo_price = 5.50;

    char movie_type;
    char ticket_type;
    char snack_combo_choice;

    int number_of_tickets;

    double ticket_price;
    double total_before_discount;
    double discount_amount = 0.0;
    double snack_combo_cost = 0.0;
    double final_total;

    // Collect and validate the movie type.
    movie_type = read_choice(
        "Enter movie type (A - Action, C - Comedy, H - Horror): ",
        "ACH");

    // Collect and validate the ticket type.
    ticket_type = read_choice(
        "Enter ticket type (S - Standard, P - Premium): ",
        "SP");

    // Collect and validate the ticket quantity.
    number_of_tickets = read_positive_int(
        "Enter number of tickets: ");

    // Collect and validate the optional snack choice.
    snack_combo_choice = read_choice(
        "Would you like a snack combo for each ticket? (y/n): ",
        "YN");

    ticket_price = get_ticket_price(movie_type, ticket_type);

    // Calculate the original ticket cost.
    total_before_discount = ticket_price * number_of_tickets;

    // Apply the 10% group discount when more than six tickets are booked.
    if (number_of_tickets > 6)
    {
        discount_amount =
            total_before_discount * group_discount_rate;
    }

    // Add one snack combo for every ticket when selected.
    if (snack_combo_choice == 'Y')
    {
        snack_combo_cost =
            snack_combo_price * number_of_tickets;
    }

    // The ticket discount does not reduce the snack combo cost.
    final_total =
        total_before_discount -
        discount_amount +
        snack_combo_cost;

    // Display the complete booking summary.
    printf("\n--- Booking Summary ---\n");

    printf("Movie Type: %s\n",
           get_movie_name(movie_type));

    printf("Ticket Type: %s\n",
           get_ticket_name(ticket_type));

    printf("Quantity: %d\n",
           number_of_tickets);

    printf("Snack Combo: %s\n",
           snack_combo_choice == 'Y' ? "Yes" : "No");

    printf("Total Before Discount: £%.2f\n",
           total_before_discount);

    printf("Discount Amount: £%.2f\n",
           discount_amount);

    printf("Snack Combo Cost: £%.2f\n",
           snack_combo_cost);

    printf("Final Total: £%.2f\n",
           final_total);
}
