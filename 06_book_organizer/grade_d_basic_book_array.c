/*
    This program stores eight book titles in an array of strings.
    It loops through the array and displays the current title together
    with the title at index 0, leaving the catalogue unchanged.
 */

#include <stdio.h>

int main(void)
{
    // Array containing eight book titles in mixed alphabetical order
    const char *books[8] = {
        "Jane Eyre",
        "East of Eden",
        "The Hobbit, or There and Back Again",
        "Earthlings",
        "To Kill a Mockingbird",
        "Emma",
        "From a Buick 8",
        "Animal Farm"};

    // Get the length of the array (number of books)
    int count = sizeof(books) / sizeof(books[0]);

    // The first title remains unchanged
    const char *first_item = books[0];

    for (int i = 0; i < count; i++)
    {
        const char *current_item = books[i];

        printf("Current Title: %s\n", current_item);
        printf("First Title: %s\n", first_item);
    }

    return 0;
}
