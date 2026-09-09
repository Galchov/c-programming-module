/*
    This program stores eight book titles in deliberately mixed alphabetical order.
    It displays the catalogue before and after one comparison pass.
    During the pass, each title is compared case-insensitively with the title
    at index 0, and an earlier alphabetical title is swapped into that position.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BOOK_COUNT 8
#define TITLE_LENGTH 100

// Compare two book titles alphabetically while ignoring uppercase and lowercase
int compare_ignore_case(const char first[], const char second[])
{
    int i = 0;

    // Compare matching characters until one of the strings ends
    while (first[i] != '\0' && second[i] != '\0')
    {
        char first_char = (char)tolower((unsigned char)first[i]);
        char second_char = (char)tolower((unsigned char)second[i]);

        // The first title comes earlier alphabetically
        if (first_char < second_char)
        {
            return -1;
        }

        // The first title comes later alphabetically
        if (first_char > second_char)
        {
            return 1;
        }

        i++;
    }

    // Both titles are identical
    if (first[i] == '\0' && second[i] == '\0')
    {
        return 0;
    }

    // If the first title ends first, it comes earlier alphabetically
    if (first[i] == '\0')
    {
        return -1;
    }

    return 1;
}

int main(void)
{
    // Store eight book titles in deliberately mixed alphabetical order
    char books[BOOK_COUNT][TITLE_LENGTH] = {
        "Jane Eyre",
        "East of Eden",
        "The Hobbit, or There and Back Again",
        "Earthlings",
        "To Kill a Mockingbird",
        "Emma",
        "From a Buick 8",
        "Animal Farm"};

    // Temporary string used when swapping two titles
    char temp[TITLE_LENGTH];

    // Display the catalogue before the comparison pass
    printf("Before:\n");

    for (int i = 0; i < BOOK_COUNT; i++)
    {
        printf("\"%s\"\n", books[i]);
    }

    // Compare each title with the title currently stored at index 0
    for (int i = 1; i < BOOK_COUNT; i++)
    {
        // Swap if the current title comes earlier alphabetically
        if (compare_ignore_case(books[i], books[0]) < 0)
        {
            strcpy(temp, books[0]);
            strcpy(books[0], books[i]);
            strcpy(books[i], temp);
        }
    }

    // Display the catalogue after the comparison pass
    printf("\nAfter:\n");

    for (int i = 0; i < BOOK_COUNT; i++)
    {
        printf("\"%s\"\n", books[i]);
    }

    return 0;
}
