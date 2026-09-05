/*
    This program stores eight book titles in deliberately mixed alphabetical order.
    It displays the catalogue before and after performing one comparison pass.
    During the pass, each title is compared case-insensitively with the title at
    index 0, and an earlier alphabetical title is swapped into the first position.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BOOK_COUNT 8
#define TITLE_LENGTH 100

// Compare two strings alphabetically while ignoring uppercase and lowercase differences
int compare_ignore_case(const char first[], const char second[])
{
    int i = 0;

    // Compare corresponding characters until one of the strings ends
    while (first[i] != '\0' && second[i] != '\0')
    {
        // Convert both characters to lowercase before comparing them
        char first_char = (char)tolower((unsigned char)first[i]);
        char second_char = (char)tolower((unsigned char)second[i]);

        // The first string comes earlier alphabetically
        if (first_char < second_char)
        {
            return -1;
        }

        // The first string comes later alphabetically
        if (first_char > second_char)
        {
            return 1;
        }

        // Move to the next character
        i++;
    }

    // Both strings are identical
    if (first[i] == '\0' && second[i] == '\0')
    {
        return 0;
    }

    // The shorter string comes first alphabetically
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

    // Temporary string used when swapping two book titles
    char temp[TITLE_LENGTH];

    // Display the catalogue before the comparison pass
    printf("Before:\n");

    for (int i = 0; i < BOOK_COUNT; i++)
    {
        printf("\"%s\"\n", books[i]);
    }

    // Compare every remaining title with the title currently at index 0
    for (int i = 1; i < BOOK_COUNT; i++)
    {
        // If the current title comes earlier alphabetically, swap the two titles
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
