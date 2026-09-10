/*
    This program stores eight book titles in deliberately mixed alphabetical order.
    It uses nested loops and case-insensitive string comparison to sort the entire
    catalogue alphabetically. The catalogue is displayed before and after sorting.
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

    // Temporary storage used when swapping two book titles
    char temporary_title[100];

    // Display the catalogue before sorting
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

    // Move through each position that still needs to be sorted
    for (int unsorted_index = 0; unsorted_index < book_count - 1; unsorted_index++)
    {
        // Compare the first unsorted title with every title after it
        for (int current_index = unsorted_index + 1;
             current_index < book_count;
             current_index++)
        {
            int character_index = 0;
            int comparison_result = 0;

            // Compare both titles character by character while ignoring letter case
            while (books[current_index][character_index] != '\0' &&
                   books[unsorted_index][character_index] != '\0')
            {
                int current_character =
                    tolower((unsigned char)books[current_index][character_index]);

                int unsorted_character =
                    tolower((unsigned char)books[unsorted_index][character_index]);

                if (current_character < unsorted_character)
                {
                    comparison_result = -1;
                    break;
                }
                else if (current_character > unsorted_character)
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
                    books[unsorted_index][character_index] != '\0')
                {
                    comparison_result = -1;
                }
                else if (books[current_index][character_index] != '\0' &&
                         books[unsorted_index][character_index] == '\0')
                {
                    comparison_result = 1;
                }
            }

            // Swap if the current title comes before the first unsorted title
            if (comparison_result < 0)
            {
                strcpy(temporary_title, books[unsorted_index]);
                strcpy(books[unsorted_index], books[current_index]);
                strcpy(books[current_index], temporary_title);
            }
        }
    }

    // Display the catalogue after sorting
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
