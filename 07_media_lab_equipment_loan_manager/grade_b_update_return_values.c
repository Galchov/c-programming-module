/*
    This program manages equipment records for a university Media Lab.
    Each item contains an ID, an asset tag, and a status.

    The program allows equipment records to be added to a text file,
    prevents duplicate IDs, displays all stored records, searches for
    equipment by ID, and updates an existing record.

    The functions now return values to indicate whether operations were
    successful. When updating an item, the records are loaded into an
    array, the matching record is changed, and the file is rewritten so
    that the old record is replaced by the updated one.
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
int addItem(int id, char assetTag[], char status[]);
void displayItems(void);
int searchItemById(int id);
int updateItem(int id, const char newAssetTag[], const char newStatus[]);

int main(void)
{
    FILE *file;

    int id;
    int searchId;
    int updateId;

    int addResult;
    int searchResult;
    int updateResult;

    char assetTag[50];
    char status[20];

    char newAssetTag[50];
    char newStatus[20];

    // Open the file in append mode to create it if it does not exist.
    file = fopen("loans.txt", "a");

    // Check that the file was opened successfully.
    if (file == NULL)
    {
        printf("Error: Could not create or open the data file.\n");
        return 1;
    }

    fclose(file);

    printf("--- Media Lab Equipment Loan Manager ---\n");
    printf("Grade B\n\n");

    // Add three equipment records to demonstrate the program.
    for (int i = 1; i <= 3; i++)
    {
        printf("Enter details for item %d\n", i);

        printf("Enter equipment ID: ");
        scanf("%d", &id);

        printf("Enter asset tag: ");
        scanf("%49s", assetTag);

        printf("Enter status (A = Available, L = Loaned): ");
        scanf("%19s", status);

        // addItem() returns 1 if added and 0 if the ID is a duplicate.
        addResult = addItem(id, assetTag, status);

        if (addResult == 1)
        {
            printf("Item added successfully.\n");
        }
        else
        {
            printf("An item with ID %d already exists. Item was not added.\n", id);
        }

        printf("\n");
    }

    // Display all currently stored equipment records.
    displayItems();

    // Ask the user for an ID to search for.
    printf("Enter equipment ID to search: ");
    scanf("%d", &searchId);

    // searchItemById() returns the record index or -1 if not found.
    searchResult = searchItemById(searchId);

    if (searchResult == -1)
    {
        printf("No item with ID %d was found.\n", searchId);
    }
    else
    {
        printf("Record index: %d\n", searchResult);
    }

    printf("\n");

    // Ask the user which equipment record should be updated.
    printf("Enter equipment ID to update: ");
    scanf("%d", &updateId);

    printf("Enter new asset tag: ");
    scanf("%49s", newAssetTag);

    printf("Enter new status (A = Available, L = Loaned): ");
    scanf("%19s", newStatus);

    // updateItem() returns 1 if updated and 0 if the ID was not found.
    updateResult = updateItem(updateId, newAssetTag, newStatus);

    if (updateResult == 1)
    {
        printf("Item updated successfully.\n\n");
    }
    else
    {
        printf("No item with ID %d was found. Nothing was updated.\n\n",
               updateId);
    }

    // Display the records again to demonstrate the update.
    displayItems();

    return 0;
}

int addItem(int id, char assetTag[], char status[])
{
    struct Item item;

    FILE *file;

    // Open the file to check whether the entered ID already exists.
    file = fopen("loans.txt", "r");

    if (file != NULL)
    {
        while (fscanf(file, "%d %49s %19s",
                      &item.id,
                      item.assetTag,
                      item.status) == 3)
        {
            // Return 0 immediately if a duplicate ID is found.
            if (item.id == id)
            {
                fclose(file);
                return 0;
            }
        }

        fclose(file);
    }

    // Open the file in append mode after confirming the ID is unique.
    file = fopen("loans.txt", "a");

    if (file == NULL)
    {
        printf("Error: Could not open the data file.\n");
        return 0;
    }

    // Append the new equipment record.
    fprintf(file, "%d %s %s\n",
            id,
            assetTag,
            status);

    fclose(file);

    // Return 1 to indicate that the item was added successfully.
    return 1;
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

    // Read and display every equipment record.
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

    if (recordsFound == 0)
    {
        printf("No equipment records found.\n\n");
    }

    fclose(file);
}

int searchItemById(int id)
{
    struct Item item;

    FILE *file;

    int index = 0;

    // Open the file in read mode.
    file = fopen("loans.txt", "r");

    if (file == NULL)
    {
        printf("Error: Could not open the data file.\n");
        return -1;
    }

    // Search through every record in the file.
    while (fscanf(file, "%d %49s %19s",
                  &item.id,
                  item.assetTag,
                  item.status) == 3)
    {
        // Display and return the index when the requested ID is found.
        if (item.id == id)
        {
            printf("\n--- Item Found ---\n");
            printf("ID: %d\n", item.id);
            printf("Asset Tag: %s\n", item.assetTag);
            printf("Status: %s\n", item.status);

            fclose(file);

            return index;
        }

        index++;
    }

    fclose(file);

    // Return -1 when no matching record exists.
    return -1;
}

int updateItem(int id, const char newAssetTag[], const char newStatus[])
{
    struct Item items[100];

    FILE *file;

    int itemCount = 0;
    int found = 0;

    // Open the file and load the existing records into the array.
    file = fopen("loans.txt", "r");

    if (file == NULL)
    {
        printf("Error: Could not open the data file.\n");
        return 0;
    }

    // Read each record into the Item array.
    while (itemCount < 100 &&
           fscanf(file, "%d %49s %19s",
                  &items[itemCount].id,
                  items[itemCount].assetTag,
                  items[itemCount].status) == 3)
    {
        itemCount++;
    }

    fclose(file);

    // Search the in-memory array for the requested ID.
    for (int i = 0; i < itemCount; i++)
    {
        if (items[i].id == id)
        {
            // Replace the asset tag manually.
            int j = 0;

            while (newAssetTag[j] != '\0' && j < 49)
            {
                items[i].assetTag[j] = newAssetTag[j];
                j++;
            }

            items[i].assetTag[j] = '\0';

            // Replace the status manually.
            j = 0;

            while (newStatus[j] != '\0' && j < 19)
            {
                items[i].status[j] = newStatus[j];
                j++;
            }

            items[i].status[j] = '\0';

            found = 1;
            break;
        }
    }

    // Return 0 without rewriting the file if the ID was not found.
    if (found == 0)
    {
        return 0;
    }

    // Open the file in write mode to replace its existing contents.
    file = fopen("loans.txt", "w");

    if (file == NULL)
    {
        printf("Error: Could not rewrite the data file.\n");
        return 0;
    }

    // Write every record back to the file, including the updated record.
    for (int i = 0; i < itemCount; i++)
    {
        fprintf(file, "%d %s %s\n",
                items[i].id,
                items[i].assetTag,
                items[i].status);
    }

    fclose(file);

    // Return 1 to indicate that the update was successful.
    return 1;
}
