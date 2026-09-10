/*
    This program manages equipment records for a university Media Lab.
    Records are loaded from a plain-text file into dynamically allocated
    memory when the program starts. The user can add, view, search, update,
    delete, save, and exit through a menu-driven interface.

    The solution keeps the required Grade D-C-B progression: Item records,
    file persistence, parameterised functions, duplicate-ID prevention,
    informative return values, searching, updating by file rewrite, and
    Grade A deletion, in-memory storage, saving, and variable-scope usage.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define INITIAL_CAPACITY 4
#define ASSET_TAG_SIZE 50
#define STATUS_SIZE 20
#define INPUT_SIZE 128

// Global filename is shared by the file-handling functions.
const char FILE_NAME[] = "loans.txt";

// A named structure stores one equipment record.
typedef struct Item
{
    int id;
    char assetTag[ASSET_TAG_SIZE];
    char status[STATUS_SIZE];
} Item;

// Dynamic in-memory collection used by the Grade A program flow.
typedef struct
{
    Item *items;
    size_t count;
    size_t capacity;
} Catalog;

// One small global catalogue keeps the shared program state.
Catalog catalog = {NULL, 0, 0};

// Required assessment functions.
int addItem(int id, char assetTag[], char status[]);
void displayItems(void);
int searchItemById(int id);
int updateItem(int id, const char newAssetTag[], const char newStatus[]);
int deleteItem(int id);

// Supporting functions for the advanced Grade A implementation.
int loadItemsFromFile(void);
int saveItemsToFile(void);
int ensureCapacity(size_t required);
int appendItemToFile(const Item *item);
int parseRecord(const char line[], Item *item);
int findItemIndexInMemory(int id);
void freeCatalog(void);

int readLine(const char prompt[], char buffer[], size_t size);
int readPositiveInt(const char prompt[]);
void readTextField(const char prompt[], char buffer[], size_t size);
int readMenuChoice(void);

int main(void)
{
    int running = 1;

    // Load persistent records into memory when the program starts.
    if (!loadItemsFromFile())
    {
        printf("Unable to initialise the equipment data.\n");
        return 1;
    }

    printf("--- Media Lab Equipment Loan Manager ---\n");
    printf("Grade A - Advanced Implementation\n\n");

    while (running)
    {
        int choice;

        printf("Menu:\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Save\n");
        printf("7. Exit\n");

        choice = readMenuChoice();
        printf("\n");

        switch (choice)
        {
        case 1:
        {
            int id = readPositiveInt("Enter equipment ID: ");
            char assetTag[ASSET_TAG_SIZE];
            char status[STATUS_SIZE];
            int result;

            readTextField("Enter asset tag: ", assetTag, sizeof(assetTag));
            readTextField("Enter status (e.g. A or L): ", status, sizeof(status));

            result = addItem(id, assetTag, status);

            if (result == 1)
            {
                printf("Item added successfully.\n\n");
            }
            else if (result == 0)
            {
                printf("An item with ID %d already exists. Item was not added.\n\n", id);
            }
            else
            {
                printf("The item could not be added because of a file or memory error.\n\n");
            }

            break;
        }

        case 2:
            displayItems();
            break;

        case 3:
        {
            int id = readPositiveInt("Enter equipment ID to search: ");
            int position = searchItemById(id);

            if (position == -1)
            {
                printf("No item with ID %d was found.\n", id);
            }
            else
            {
                printf("Record index: %d\n", position);
            }

            printf("\n");
            break;
        }

        case 4:
        {
            int id = readPositiveInt("Enter equipment ID to update: ");
            char newAssetTag[ASSET_TAG_SIZE];
            char newStatus[STATUS_SIZE];

            readTextField("Enter new asset tag: ",
                          newAssetTag,
                          sizeof(newAssetTag));

            readTextField("Enter new status: ",
                          newStatus,
                          sizeof(newStatus));

            if (updateItem(id, newAssetTag, newStatus))
            {
                printf("Item updated successfully.\n\n");
            }
            else
            {
                printf("No item with ID %d was updated.\n\n", id);
            }

            break;
        }

        case 5:
        {
            int id = readPositiveInt("Enter equipment ID to delete: ");

            if (deleteItem(id))
            {
                printf("Item deleted successfully.\n\n");
            }
            else
            {
                printf("No item with ID %d was deleted.\n\n", id);
            }

            break;
        }

        case 6:
            if (saveItemsToFile())
            {
                printf("Equipment data saved successfully.\n\n");
            }
            else
            {
                printf("Error: Equipment data could not be saved.\n\n");
            }

            break;

        case 7:
            // Grade A requires current in-memory data to be written on exit.
            if (!saveItemsToFile())
            {
                printf("Warning: The latest data could not be saved.\n");
            }

            printf("Exiting program...\n");
            running = 0;

            break;
        }
    }

    // Release dynamically allocated memory before the program finishes.
    freeCatalog();

    return 0;
}

int addItem(int id, char assetTag[], char status[])
{
    Item newItem;

    // Grade C requirement: refuse duplicate IDs.
    if (findItemIndexInMemory(id) != -1)
    {
        return 0;
    }

    if (!ensureCapacity(catalog.count + 1))
    {
        return -1;
    }

    newItem.id = id;

    snprintf(newItem.assetTag,
             sizeof(newItem.assetTag),
             "%s",
             assetTag);

    snprintf(newItem.status,
             sizeof(newItem.status),
             "%s",
             status);

    // Append the valid new record to the file.
    if (!appendItemToFile(&newItem))
    {
        return -1;
    }

    // Add the same record to the in-memory collection.
    catalog.items[catalog.count] = newItem;
    catalog.count++;

    // Grade B requirement: 1 means successfully added.
    return 1;
}

void displayItems(void)
{
    FILE *file = fopen(FILE_NAME, "r");

    char line[INPUT_SIZE + ASSET_TAG_SIZE + STATUS_SIZE];

    int recordsFound = 0;

    if (file == NULL)
    {
        printf("Error: Could not open the data file.\n\n");
        return;
    }

    printf("--- Stored Equipment ---\n\n");

    // Preserve the Grade D requirement by reading records from the file.
    while (fgets(line, sizeof(line), file) != NULL)
    {
        Item item;

        if (parseRecord(line, &item))
        {
            printf("ID: %d\n", item.id);
            printf("Asset Tag: %s\n", item.assetTag);
            printf("Status: %s\n\n", item.status);

            recordsFound = 1;
        }
    }

    if (!recordsFound)
    {
        printf("No equipment records found.\n\n");
    }

    fclose(file);
}

int searchItemById(int id)
{
    FILE *file = fopen(FILE_NAME, "r");

    char line[INPUT_SIZE + ASSET_TAG_SIZE + STATUS_SIZE];

    int index = 0;

    if (file == NULL)
    {
        printf("Error: Could not open the data file.\n");
        return -1;
    }

    // Read the file, display a matching record, and return its index.
    while (fgets(line, sizeof(line), file) != NULL)
    {
        Item item;

        if (!parseRecord(line, &item))
        {
            continue;
        }

        if (item.id == id)
        {
            printf("--- Item Found ---\n");
            printf("ID: %d\n", item.id);
            printf("Asset Tag: %s\n", item.assetTag);
            printf("Status: %s\n", item.status);

            fclose(file);

            return index;
        }

        index++;
    }

    fclose(file);

    // -1 represents a record that was not found.
    return -1;
}

int updateItem(int id,
               const char newAssetTag[],
               const char newStatus[])
{
    int index;

    // Reload all file records into the Item array before the update.
    if (!loadItemsFromFile())
    {
        return 0;
    }

    index = findItemIndexInMemory(id);

    if (index == -1)
    {
        return 0;
    }

    // Replace the old asset tag in memory.
    snprintf(catalog.items[index].assetTag,
             sizeof(catalog.items[index].assetTag),
             "%s",
             newAssetTag);

    // Replace the old status in memory.
    snprintf(catalog.items[index].status,
             sizeof(catalog.items[index].status),
             "%s",
             newStatus);

    // Rewrite the file so the old record is replaced by the new one.
    if (!saveItemsToFile())
    {
        return 0;
    }

    return 1;
}

int deleteItem(int id)
{
    int index;

    // Load the current file records before performing the deletion.
    if (!loadItemsFromFile())
    {
        return 0;
    }

    index = findItemIndexInMemory(id);

    if (index == -1)
    {
        return 0;
    }

    // Shift later records left so no gap remains after deletion.
    if ((size_t)index < catalog.count - 1)
    {
        memmove(&catalog.items[index],
                &catalog.items[index + 1],
                (catalog.count - (size_t)index - 1) * sizeof(Item));
    }

    catalog.count--;

    // Rewrite the file without the deleted record.
    if (!saveItemsToFile())
    {
        return 0;
    }

    return 1;
}

int loadItemsFromFile(void)
{
    FILE *file;

    char line[INPUT_SIZE + ASSET_TAG_SIZE + STATUS_SIZE];

    // Create the plain-text file if it does not already exist.
    file = fopen(FILE_NAME, "a");

    if (file == NULL)
    {
        printf("Error: Could not create or open %s.\n", FILE_NAME);
        return 0;
    }

    fclose(file);

    // Reopen the file for reading.
    file = fopen(FILE_NAME, "r");

    if (file == NULL)
    {
        printf("Error: Could not read %s.\n", FILE_NAME);
        return 0;
    }

    catalog.count = 0;

    // Load every valid record into dynamically allocated memory.
    while (fgets(line, sizeof(line), file) != NULL)
    {
        Item item;

        if (!parseRecord(line, &item))
        {
            continue;
        }

        if (!ensureCapacity(catalog.count + 1))
        {
            fclose(file);
            return 0;
        }

        catalog.items[catalog.count] = item;
        catalog.count++;
    }

    fclose(file);

    return 1;
}

int saveItemsToFile(void)
{
    FILE *file = fopen(FILE_NAME, "w");

    if (file == NULL)
    {
        return 0;
    }

    // Rewrite the file from the current in-memory catalogue.
    for (size_t i = 0; i < catalog.count; i++)
    {
        if (fprintf(file,
                    "%d|%s|%s\n",
                    catalog.items[i].id,
                    catalog.items[i].assetTag,
                    catalog.items[i].status) < 0)
        {
            fclose(file);
            return 0;
        }
    }

    if (fclose(file) != 0)
    {
        return 0;
    }

    return 1;
}

int ensureCapacity(size_t required)
{
    Item *resizedItems;
    size_t newCapacity;

    // No resizing is required if enough memory is already available.
    if (required <= catalog.capacity)
    {
        return 1;
    }

    if (catalog.capacity == 0)
    {
        newCapacity = INITIAL_CAPACITY;
    }
    else
    {
        newCapacity = catalog.capacity;
    }

    // Double the capacity until enough space is available.
    while (newCapacity < required)
    {
        newCapacity *= 2;
    }

    resizedItems = realloc(catalog.items,
                           newCapacity * sizeof(Item));

    if (resizedItems == NULL)
    {
        printf("Error: Not enough memory to store more equipment records.\n");
        return 0;
    }

    catalog.items = resizedItems;
    catalog.capacity = newCapacity;

    return 1;
}

int appendItemToFile(const Item *item)
{
    FILE *file = fopen(FILE_NAME, "a");

    int success;

    if (file == NULL)
    {
        return 0;
    }

    success = fprintf(file,
                      "%d|%s|%s\n",
                      item->id,
                      item->assetTag,
                      item->status) >= 0;

    if (fclose(file) != 0)
    {
        return 0;
    }

    return success;
}

int parseRecord(const char line[], Item *item)
{
    // The plain-text file uses | as a field separator.
    return sscanf(line,
                  "%d|%49[^|]|%19[^\n]",
                  &item->id,
                  item->assetTag,
                  item->status) == 3;
}

int findItemIndexInMemory(int id)
{
    for (size_t i = 0; i < catalog.count; i++)
    {
        if (catalog.items[i].id == id)
        {
            return (int)i;
        }
    }

    return -1;
}

void freeCatalog(void)
{
    free(catalog.items);

    catalog.items = NULL;
    catalog.count = 0;
    catalog.capacity = 0;
}

int readLine(const char prompt[],
             char buffer[],
             size_t size)
{
    size_t length;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(buffer, (int)size, stdin) == NULL)
        {
            return 0;
        }

        length = strlen(buffer);

        // Remove the newline when the complete input fits in the buffer.
        if (length > 0 && buffer[length - 1] == '\n')
        {
            buffer[length - 1] = '\0';
            return 1;
        }

        // Discard the rest if the user entered more than the buffer can hold.
        if (!feof(stdin))
        {
            int ch;

            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }

            printf("Input is too long. Please try again.\n");
            continue;
        }

        return 1;
    }
}

int readPositiveInt(const char prompt[])
{
    char input[INPUT_SIZE];

    while (1)
    {
        char *end;
        long value;

        if (!readLine(prompt, input, sizeof(input)))
        {
            printf("Input ended unexpectedly.\n");
            exit(EXIT_FAILURE);
        }

        errno = 0;

        value = strtol(input, &end, 10);

        // Accept the value only if the complete input is a valid positive int.
        if (errno == 0 &&
            end != input &&
            *end == '\0' &&
            value > 0 &&
            value <= INT_MAX)
        {
            return (int)value;
        }

        printf("Invalid input. Please enter a positive whole number.\n");
    }
}

void readTextField(const char prompt[],
                   char buffer[],
                   size_t size)
{
    while (1)
    {
        if (!readLine(prompt, buffer, size))
        {
            printf("Input ended unexpectedly.\n");
            exit(EXIT_FAILURE);
        }

        if (buffer[0] == '\0')
        {
            printf("Input cannot be empty. Please try again.\n");
            continue;
        }

        // The separator is reserved for the plain-text file format.
        if (strchr(buffer, '|') != NULL)
        {
            printf("The '|' character cannot be used in this field.\n");
            continue;
        }

        return;
    }
}

int readMenuChoice(void)
{
    while (1)
    {
        int choice = readPositiveInt("Enter choice: ");

        if (choice >= 1 && choice <= 7)
        {
            return choice;
        }

        printf("Invalid choice. Please enter a number from 1 to 7.\n");
    }
}
