/*
    This program stores equipment records for a university Media Lab.
    Each item contains an ID, an asset tag, and a status.

    The program creates a text file if necessary, allows the user to
    add at least three equipment records, saves them to the file,
    and then reads and displays all stored records.

    The addItem() and displayItems() functions use no parameters
    and return no values, as required for the Grade D solution.
*/

#include <stdio.h>

// Structure used to store the details of one equipment item.
struct Item
{
    int id;
    char assetTag[50];
    char status;
};

// Function declarations.
void addItem(void);
void displayItems(void);

int main(void)
{
    FILE *file;

    // Open the file in append mode to create it if it does not exist.
    file = fopen("loans.txt", "a");

    // Check that the file was opened successfully.
    if (file == NULL)
    {
        printf("Error: Could not create or open the data file.\n");
        return 1;
    }

    // Close the file because the functions will open it when required.
    fclose(file);

    printf("--- Media Lab Equipment Loan Manager ---\n\n");

    // Add three equipment records as required for the demonstration.
    for (int i = 1; i <= 3; i++)
    {
        printf("Enter details for item %d\n", i);
        addItem();
        printf("\n");
    }

    // Display all equipment records stored in the file.
    displayItems();

    return 0;
}

void addItem(void)
{
    struct Item item;
    FILE *file;

    // Get the equipment details from the user.
    printf("Enter equipment ID: ");
    scanf("%d", &item.id);

    printf("Enter asset tag: ");
    scanf("%49s", item.assetTag);

    printf("Enter status (A = Available, L = Loaned): ");
    scanf(" %c", &item.status);

    // Open the file in append mode to add the new record.
    file = fopen("loans.txt", "a");

    // Check that the file was opened successfully.
    if (file == NULL)
    {
        printf("Error: Could not open the data file.\n");
        return;
    }

    // Save the equipment record to the file.
    fprintf(file, "%d %s %c\n",
            item.id,
            item.assetTag,
            item.status);

    // Close the file after writing.
    fclose(file);

    printf("Item added successfully.\n");
}

void displayItems(void)
{
    struct Item item;
    FILE *file;

    // Open the file in read mode.
    file = fopen("loans.txt", "r");

    // Check that the file was opened successfully.
    if (file == NULL)
    {
        printf("Error: Could not open the data file.\n");
        return;
    }

    printf("--- Stored Equipment ---\n\n");

    // Read and display each complete equipment record.
    while (fscanf(file, "%d %49s %c",
                  &item.id,
                  item.assetTag,
                  &item.status) == 3)
    {
        printf("ID: %d\n", item.id);
        printf("Asset Tag: %s\n", item.assetTag);
        printf("Status: %c\n", item.status);
        printf("\n");
    }

    // Close the file after reading.
    fclose(file);
}
