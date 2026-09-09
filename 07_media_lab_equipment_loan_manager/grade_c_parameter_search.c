/*
    This program manages equipment records for a university Media Lab.
    Each item stores an ID, an asset tag, and a status.

    The program allows equipment information to be passed to the addItem()
    function using parameters, prevents duplicate equipment IDs, stores valid
    records in a text file, displays all saved records, and allows the user
    to search for an equipment item by its ID.

    File handling is used so that equipment records remain stored between
    separate runs of the program.
*/

#include <stdio.h>

// Structure used to store one equipment record.
struct Item
{
    int id;
    char assetTag[50];
    char status[20];
};

// Function declarations.
void addItem(int id, char assetTag[], char status[]);
void displayItems(void);
void searchItemById(int id);

int main(void)
{
    FILE *file;

    int id;
    int searchId;

    char assetTag[50];
    char status[20];

    // Open the file in append mode to create it if it does not exist.
    file = fopen("loans.txt", "a");

    // Check that the file was opened successfully.
    if (file == NULL)
    {
        printf("Error: Could not create or open the data file.\n");
        return 1;
    }

    // Close the file because the functions will open it when needed.
    fclose(file);

    printf("--- Media Lab Equipment Loan Manager ---\n");
    printf("Grade C\n\n");

    // Add three equipment items to demonstrate the program.
    for (int i = 1; i <= 3; i++)
    {
        printf("Enter details for item %d\n", i);

        printf("Enter equipment ID: ");
        scanf("%d", &id);

        printf("Enter asset tag: ");
        scanf("%49s", assetTag);

        printf("Enter status (A = Available, L = Loaned): ");
        scanf("%19s", status);

        // Pass the entered information to addItem().
        addItem(id, assetTag, status);

        printf("\n");
    }

    // Display all records currently stored in the file.
    displayItems();

    // Ask the user for an equipment ID to search for.
    printf("Enter equipment ID to search: ");
    scanf("%d", &searchId);

    // Pass the ID to the search function.
    searchItemById(searchId);

    return 0;
}

void addItem(int id, char assetTag[], char status[])
{
    struct Item item;

    FILE *file;

    int duplicate = 0;

    // Open the file in read mode to check for an existing ID.
    file = fopen("loans.txt", "r");

    // Check all existing records if the file was opened successfully.
    if (file != NULL)
    {
        while (fscanf(file, "%d %49s %19s",
                      &item.id,
                      item.assetTag,
                      item.status) == 3)
        {
            // Check whether the entered ID already exists.
            if (item.id == id)
            {
                duplicate = 1;
                break;
            }
        }

        fclose(file);
    }

    // Do not add the item if the ID already exists.
    if (duplicate == 1)
    {
        printf("An item with ID %d already exists. Item was not added.\n", id);
        return;
    }

    // Open the file in append mode to save the new item.
    file = fopen("loans.txt", "a");

    // Check that the file was opened successfully.
    if (file == NULL)
    {
        printf("Error: Could not open the data file.\n");
        return;
    }

    // Append the new record to the file.
    fprintf(file, "%d %s %s\n",
            id,
            assetTag,
            status);

    fclose(file);

    printf("Item added successfully.\n");
}

void displayItems(void)
{
    struct Item item;

    FILE *file;

    int recordsFound = 0;

    // Open the file in read mode.
    file = fopen("loans.txt", "r");

    if (file == NULL)
    {
        printf("Error: Could not open the data file.\n");
        return;
    }

    printf("--- Stored Equipment ---\n\n");

    // Read and display every complete equipment record.
    while (fscanf(file, "%d %49s %19s",
                  &item.id,
                  item.assetTag,
                  item.status) == 3)
    {
        printf("ID: %d\n", item.id);
        printf("Asset Tag: %s\n", item.assetTag);
        printf("Status: %s\n", item.status);
        printf("\n");

        recordsFound = 1;
    }

    // Display a message if the file contains no equipment records.
    if (recordsFound == 0)
    {
        printf("No equipment records found.\n\n");
    }

    fclose(file);
}

void searchItemById(int id)
{
    struct Item item;

    FILE *file;

    int found = 0;

    // Open the file in read mode.
    file = fopen("loans.txt", "r");

    if (file == NULL)
    {
        printf("Error: Could not open the data file.\n");
        return;
    }

    // Search through each stored record.
    while (fscanf(file, "%d %49s %19s",
                  &item.id,
                  item.assetTag,
                  item.status) == 3)
    {
        // Check whether the current record has the requested ID.
        if (item.id == id)
        {
            printf("\n--- Item Found ---\n");
            printf("ID: %d\n", item.id);
            printf("Asset Tag: %s\n", item.assetTag);
            printf("Status: %s\n", item.status);

            found = 1;
            break;
        }
    }

    // Display a message if no matching record was found.
    if (found == 0)
    {
        printf("\nNo item with ID %d was found.\n", id);
    }

    fclose(file);
}
