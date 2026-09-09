/*
    This program stores eight book titles in deliberately mixed alphabetical order.
    It uses a loop to display each current title together with the title stored
    at index 0. The catalogue is only displayed and is not sorted or modified.
*/

#include <stdio.h>

int main(void)
{
    // Store eight book titles in deliberately mixed alphabetical order
    const char *books[8] = {
        "Jane Eyre",
        "East of Eden",
        "The Hobbit, or There and Back Again",
        "Earthlings",
        "To Kill a Mockingbird",
        "Emma",
        "From a Buick 8",
        "Animal Farm"};

    // Calculate the number of books stored in the array
    int count = sizeof(books) / sizeof(books[0]);

    // Loop through every book in the catalogue
    for (int i = 0; i < count; i++)
    {
        // Display the current title and the title stored at index 0
        printf("Current Title: \"%s\"\n", books[i]);
        printf("First Title: \"%s\"\n\n", books[0]);
    }

    return 0;
}
