/*
    This program stores eight book titles in deliberately mixed alphabetical order.
    It loops through the catalogue and displays the current book title together
    with the title stored at index 0. The catalogue is not sorted or modified.
*/

#include <stdio.h>

int main(void)
{
    // Store eight book titles in deliberately mixed alphabetical order
    const char books[8][50] = {
        "Jane Eyre",
        "East of Eden",
        "The Hobbit, or There and Back Again",
        "Earthlings",
        "To Kill a Mockingbird",
        "Emma",
        "From a Buick 8",
        "Animal Farm"};

    // Calculate the number of books stored in the array
    int book_count = sizeof(books) / sizeof(books[0]);

    // Loop through every book in the catalogue
    for (int current_index = 0; current_index < book_count; current_index++)
    {
        printf("Current Title: \"%s\"\n", books[current_index]);
        printf("First Title: \"%s\"\n", books[0]);
    }

    return 0;
}
