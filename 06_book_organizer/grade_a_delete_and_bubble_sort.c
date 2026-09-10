/*
    This program stores eight book titles in deliberately mixed alphabetical order.
    It sorts the complete catalogue using Bubble Sort with case-insensitive comparison.
    The user can then enter a book title to delete, and the remaining titles are
    shifted so that no gap is left in the array.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BOOK_COUNT 8
#define TITLE_LENGTH 100

int compare_ignore_case(const char first_title[], const char second_title[])
{
    int character_index = 0;

    // Compare matching characters while both strings still contain characters
    while (first_title[character_index] != '\0' &&
           second_title[character_index] != '\0')
    {
        int first_character =
            tolower((unsigned char)first_title[character_index]);

        int second_character =
            tolower((unsigned char)second_title[character_index]);

        if (first_character < second_character)
        {
            return -1;
        }

        if (first_character > second_character)
        {
            return 1;
        }

        character_index++;
    }

    // If both titles end at the same point, they are equal
    if (first_title[character_index] == '\0' &&
        second_title[character_index] == '\0')
    {
        return 0;
    }

    // If only the first title ends, it comes earlier alphabetically
    if (first_title[character_index] == '\0')
    {
        return -1;
    }

    return 1;
}

void print_books(char books[][TITLE_LENGTH], int book_count)
{
    // Display all valid book titles
    for (int book_index = 0; book_index < book_count; book_index++)
    {
        printf("\"%s\"", books[book_index]);

        if (book_index < book_count - 1)
        {
            printf(", ");
        }
    }

    printf("\n");
}

void swap_titles(char first_title[], char second_title[])
{
    char temporary_title[TITLE_LENGTH];

    // Swap the contents of two book-title strings
    strcpy(temporary_title, first_title);
    strcpy(first_title, second_title);
    strcpy(second_title, temporary_title);
}

void bubble_sort_books(char books[][TITLE_LENGTH], int book_count)
{
    // Each pass moves the alphabetically latest unsorted title towards the end
    for (int pass = 0; pass < book_count - 1; pass++)
    {
        int swapped = 0;

        // Compare neighbouring titles in the unsorted part of the catalogue
        for (int book_index = 0;
             book_index < book_count - 1 - pass;
             book_index++)
        {
            if (compare_ignore_case(
                    books[book_index],
                    books[book_index + 1]) > 0)
            {
                swap_titles(
                    books[book_index],
                    books[book_index + 1]);

                swapped = 1;
            }
        }

        // Stop early if the catalogue is already fully sorted
        if (!swapped)
        {
            break;
        }
    }
}

int delete_book(
    char books[][TITLE_LENGTH],
    int *book_count,
    const char title_to_delete[])
{
    int delete_index = -1;

    // Search for the exact book title entered by the user
    for (int book_index = 0; book_index < *book_count; book_index++)
    {
        if (strcmp(books[book_index], title_to_delete) == 0)
        {
            delete_index = book_index;
            break;
        }
    }

    // Return failure if the requested title was not found
    if (delete_index == -1)
    {
        return 0;
    }

    // Shift every following title one position to the left
    for (int book_index = delete_index;
         book_index < *book_count - 1;
         book_index++)
    {
        strcpy(
            books[book_index],
            books[book_index + 1]);
    }

    // Reduce the valid number of books
    (*book_count)--;

    // Clear the now-unused final array position
    books[*book_count][0] = '\0';

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

    int book_count = BOOK_COUNT;
    char title_to_delete[TITLE_LENGTH];

    // Display the catalogue before sorting
    printf("Before sorting:\n");
    print_books(books, book_count);

    // Sort the complete catalogue using Bubble Sort
    bubble_sort_books(books, book_count);

    // Display the catalogue after sorting
    printf("\nAfter sorting:\n");
    print_books(books, book_count);

    // Ask the user which book should be deleted
    printf("\nEnter a book title to delete: ");

    if (fgets(title_to_delete, sizeof(title_to_delete), stdin) != NULL)
    {
        // Remove the newline stored by fgets
        title_to_delete[strcspn(title_to_delete, "\n")] = '\0';

        if (delete_book(books, &book_count, title_to_delete))
        {
            printf("Book deleted successfully.\n");

            // Display the catalogue to demonstrate that no gap remains
            printf("\nAfter deletion:\n");
            print_books(books, book_count);
        }
        else
        {
            printf("Book title not found.\n");
        }
    }

    return 0;
}
