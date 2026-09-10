/*
    This program stores eight book titles in deliberately mixed alphabetical order.
    It displays the catalogue before and after one case-insensitive comparison pass.
    During the pass, each title is compared with the title at index 0, and any
    alphabetically earlier title is swapped into the first position.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Store eight book titles in deliberately mixed alphabetical order
    char books[8][100] = {
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

    // Temporary storage used when two book titles are swapped
    char temporary_title[100];

    // Display the catalogue before the comparison pass
    printf("Before: ");

    for (int current_index = 0; current_index < book_count; current_index++)
    {
        printf("\"%s\"", books[current_index]);

        if (current_index < book_count - 1)
        {
            printf(", ");
        }
    }

    printf("\n");

    // Perform one pass and compare every title with the title at index 0
    for (int current_index = 1; current_index < book_count; current_index++)
    {
        int character_index = 0;
        int comparison_result = 0;

        // Compare both titles one character at a time while ignoring letter case
        while (books[current_index][character_index] != '\0' &&
               books[0][character_index] != '\0')
        {
            int current_character =
                tolower((unsigned char)books[current_index][character_index]);

            int first_character =
                tolower((unsigned char)books[0][character_index]);

            if (current_character < first_character)
            {
                comparison_result = -1;
                break;
            }
            else if (current_character > first_character)
            {
                comparison_result = 1;
                break;
            }

            character_index++;
        }

        // If matching text ends at different points, the shorter title comes first
        if (comparison_result == 0)
        {
            if (books[current_index][character_index] == '\0' &&
                books[0][character_index] != '\0')
            {
                comparison_result = -1;
            }
            else if (books[current_index][character_index] != '\0' &&
                     books[0][character_index] == '\0')
            {
                comparison_result = 1;
            }
        }

        // Swap with index 0 if the current title comes earlier alphabetically
        if (comparison_result < 0)
        {
            strcpy(temporary_title, books[0]);
            strcpy(books[0], books[current_index]);
            strcpy(books[current_index], temporary_title);
        }
    }

    // Display the catalogue after the comparison pass
    printf("After:  ");

    for (int current_index = 0; current_index < book_count; current_index++)
    {
        printf("\"%s\"", books[current_index]);

        if (current_index < book_count - 1)
        {
            printf(", ");
        }
    }

    printf("\n");

    return 0;
}
