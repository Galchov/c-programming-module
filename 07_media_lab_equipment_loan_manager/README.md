# Assessment Task 7 – Media Lab Equipment Loan Manager

This folder contains four C programming solutions for **Assessment Task 7: Media Lab Equipment Loan Manager** from the **QH0305 Problem Solving** module.

The task is designed to apply and extend the programming knowledge developed throughout Weeks 1 to 11 of the module.

It combines previously learned programming concepts with the more recent topics of functions, advanced function techniques, structures, and file handling to create a progressively more complete equipment-management system.

## Task Overview

The Media Lab Equipment Loan Manager is a C program designed to manage equipment records for a university Media Lab.

The system works with equipment information such as:

- Equipment ID
- Asset tag
- Equipment status

Depending on the grade level, the program develops from a basic file-based application into a more complete equipment-management system capable of:

- Creating and using equipment records
- Adding equipment to a file
- Displaying stored equipment
- Searching for equipment by ID
- Preventing duplicate IDs
- Passing data to functions using parameters
- Returning information from functions
- Updating existing equipment records
- Rewriting file contents safely after changes
- Deleting equipment records
- Storing records temporarily in memory
- Loading previously saved data when the program starts
- Saving modified data back to a file
- Using a menu-driven interface
- Managing local and global variable scope
- Keeping equipment information available between separate program runs

Each grade solution builds upon the requirements of the previous grade.

## Files

| File | Grade Band | Description |
|---|---:|---|
| `grade_d_basic_file_functions.c` | 40–49 | Introduces an equipment structure, creates a data file, and uses basic no-parameter, no-return functions to add and display equipment records. |
| `grade_c_parameter_search.c` | 50–59 | Refactors functions to use parameters, adds equipment searching by ID, and prevents duplicate equipment IDs from being stored. |
| `grade_b_update_return_values.c` | 60–69 | Introduces function return values, updates existing records by loading them into memory and rewriting the file, and reports operation success or failure. |
| `grade_a_full_loan_manager.c` | 70–100 | Adds deletion, in-memory data management, file persistence, saving, a complete menu-driven interface, and appropriate use of local and global scope. |

## Topics Practised

### Previous Knowledge from Weeks 1 to 9

Assessment Task 7 continues to apply and combine the C programming knowledge developed throughout the earlier weeks of the module, including:

- Basic C program structure
- Variables and data types
- Constants
- Arithmetic operations
- User input
- Formatted output
- Conditional statements
- `if`, `else if`, and `else`
- Comparison operators
- Logical operators
- `switch` / `case` statements
- Input validation
- `while` loops
- `for` loops
- Nested loops
- Arrays
- Array indexing
- Iterating through arrays
- Character arrays
- Strings
- String processing
- Searching through data
- Menu-driven programs
- Functions
- Function declarations
- Function definitions
- Function calls
- Functions with and without return values
- Structured problem-solving
- Debugging and testing
- Writing readable and organised C programs

### Week 10 – Advanced Function Techniques in C

Week 10 develops the use of functions further by introducing parameters, arguments, and return values.

Instead of allowing every function to operate independently on its own internal data, information can be passed into functions so that the same function can work with different values.

The main Week 10 concepts relevant to this task include:

- Functions with parameters
- Passing arguments to functions
- Multiple function parameters
- Functions with return values
- Functions without return values
- Call by value
- Using return values to communicate results
- Separating program operations into reusable functions
- Reducing duplicated code
- Modular program design
- Debugging interactions between multiple functions
- Improving program readability and maintainability

These concepts are particularly important because the grade progression deliberately develops the functions from simple no-parameter functions into functions that accept arguments and return meaningful results.

### Week 11 – File Handling in C

Week 11 introduces **file handling**, which allows data to remain available after the program has finished running.

Without files, values stored in normal variables or arrays exist only while the program is running.

File handling allows the program to store information permanently and retrieve it again during a later execution.

The main concepts include:

- Creating files
- Opening files
- Closing files
- Reading data from files
- Writing data to files
- Appending data to files
- Rewriting existing files
- Text file handling
- File opening modes
- Checking whether file operations were successful
- Handling file errors
- Persistent data storage
- Loading saved information
- Saving modified information

File handling is central to Assessment Task 7 because equipment records must remain available between separate executions of the program.

## Structures and Equipment Records

Assessment Task 7 also requires the use of a C **structure** to represent an equipment record.

The structure should be named:

```c
Item
```

Each `Item` should contain information for:

- `id` – integer equipment identifier
- `assetTag` – string representing the equipment asset tag
- `status` – string or character representing the equipment status

Conceptually:

```text
Item
│
├── id
├── assetTag
└── status
```

For example, an equipment record could represent:

```text
ID: 104
Asset Tag: CAM-104
Status: A
```

where a status could represent values such as:

```text
A = Available
L = Loaned
```

Using a structure allows all information belonging to one piece of equipment to be grouped into a single logical record.

## Learning Scope Note

For Grades D, C, and B, the solutions are intended to use programming knowledge covered so far in the module from Weeks 1 through 11.

The solutions should demonstrate the natural progression of the material covered during the module, particularly functions, function parameters, return values, arrays, strings, structures, and file handling.

This helps ensure that each grade solution reflects the expected stage of learning and demonstrates how previously introduced concepts can be combined to solve a larger programming problem.

For Grade A, students may use more advanced C programming knowledge if they already understand it, even where those techniques have not yet been fully covered in earlier lectures or seminars.

More advanced techniques may be used where they help produce a clearer, more structured, efficient, robust, or maintainable solution, while still satisfying all assessment requirements.

## Assessment Requirements

To achieve a higher grade band, each solution must build upon and include the requirements of the previous grade bands.

The assessment contains four progressive C programming solutions:

1. **D Grade:** Basic equipment structure, file creation, adding equipment records, and displaying stored equipment using simple functions.
2. **C Grade:** Function parameters, searching by equipment ID, and duplicate-ID prevention.
3. **B Grade:** Function return values, equipment updating, temporary in-memory storage, and file rewriting.
4. **A Grade:** Equipment deletion, complete in-memory data management, persistent file storage, saving, menu navigation, and appropriate variable scope.

## Function Progression

An important part of Assessment Task 7 is the gradual development of functions across the grade bands.

| Grade | Function Concepts |
|---|---|
| D | No parameters and no return values |
| C | Functions with parameters |
| B | Functions with parameters and return values |
| A | Complete modular program using functions for equipment-management operations |

This progression demonstrates how functions can become more flexible and informative as programs become more complex.

## File Persistence

The equipment data should be stored in a plain-text file.

A suitable example filename is:

```text
loans.txt
```

The purpose of the file is to ensure that equipment data is not lost when the program closes.

Conceptually:

```text
Program starts
      ↓
Read existing records from file
      ↓
User works with equipment records
      ↓
Add / Search / Update / Delete
      ↓
Save modified records
      ↓
Program exits
      ↓
Data remains stored in file
```

The exact file-handling requirements become progressively more advanced across the grade bands.

## Program Features by Grade

### Grade D – Basic Functions and File Storage

The Grade D solution introduces structures, functions, and basic file handling.

The program should define:

```c
struct Item
```

to store:

- Equipment ID
- Asset tag
- Equipment status

The program should create the data file if it does not already exist.

A suitable example filename is:

```text
loans.txt
```

The Grade D solution should implement two functions:

```c
addItem()
displayItems()
```

Both functions should:

- Take no parameters
- Return no values
- Handle their required input and output internally

### `addItem()`

The `addItem()` function should:

- Ask the user for an equipment ID
- Ask the user for an asset tag
- Ask the user for the equipment status
- Append the new equipment record to the file

Conceptually:

```text
Enter equipment ID: 104
Enter asset tag: CAM-104
Enter status: A
```

### `displayItems()`

The `displayItems()` function should:

- Open the equipment file
- Read all stored equipment records
- Display the records clearly
- Close the file correctly after reading

A tidy output could follow the general structure:

```text
ID: 104
Asset Tag: CAM-104
Status: A
```

The Grade D solution should demonstrate adding at least **three equipment items** and then displaying the stored list.

This grade primarily demonstrates:

- Structures
- Basic functions
- File creation
- File opening and closing
- File appending
- File reading
- User input
- Formatted output

### Grade C – Parameters, Search, and Duplicate-ID Checking

The Grade C solution builds upon all Grade D requirements.

The `addItem()` function should be refactored so that information is passed into the function using parameters.

The required function structure is based on:

```c
addItem(int id, char assetTag[], char status[])
```

The `displayItems()` function should remain a no-parameter function.

The Grade C solution should also introduce:

```c
searchItemById(int id)
```

### Searching by ID

The search function should:

- Accept an equipment ID
- Open and read the equipment data
- Search through the available records
- Display the matching record if found
- Display an appropriate message if the ID does not exist

For example:

```text
Enter equipment ID to search: 104

ID: 104
Asset Tag: CAM-104
Status: A
```

If the record does not exist:

```text
Item not found.
```

### Duplicate-ID Validation

The Grade C solution should prevent two equipment records from using the same ID.

Before adding a new item, the program should determine whether the ID is already stored.

If the ID already exists:

- Display a friendly message
- Do not add the duplicate record
- Do not append duplicate information to the file

This introduces more advanced interaction between functions, file handling, searching, and validation.

### Grade B – Return Values and Equipment Updates

The Grade B solution builds upon all Grade C requirements.

Functions should now return useful information to the part of the program that called them.

The `addItem()` function should return:

```text
1 = Item successfully added
0 = Duplicate ID
```

Conceptually:

```c
int addItem(...)
```

The search function should return:

```text
Record position/index = Item found
-1 = Item not found
```

Conceptually:

```c
int searchItemById(int id)
```

This allows the calling code to make decisions based on the result of the function.

### Updating Equipment Records

The Grade B solution should implement:

```c
int updateItem(int id, const char newAssetTag[], const char newStatus[])
```

The update process should:

1. Read all equipment records from the file.
2. Store them temporarily in an array of `Item` structures.
3. Search for the requested equipment ID.
4. Modify the matching asset tag and status.
5. Rewrite the file using the updated records.
6. Ensure that the old values have been replaced.
7. Return whether the update was successful.

The function should return:

```text
1 = Record successfully updated
0 = Record not found
```

Conceptually:

```text
File
 ↓
Load records into Item array
 ↓
Find matching ID
 ↓
Modify record in memory
 ↓
Rewrite complete file
 ↓
Updated data saved
```

The important requirement is that the file should reflect the **new version of the record**, rather than retaining outdated information.

This grade develops understanding of:

- Function return values
- Arrays of structures
- Searching
- Updating structured data
- File rewriting
- Temporary in-memory storage
- Communicating operation results between functions

### Grade A – Full Equipment Loan Manager

The Grade A solution builds upon all Grade B requirements and develops the program into a complete equipment-management application.

The final system should support:

- Adding equipment
- Viewing equipment
- Searching for equipment
- Updating equipment
- Deleting equipment
- Saving equipment data
- Exiting the program

## Equipment Deletion

The Grade A solution should implement:

```c
int deleteItem(int id)
```

The deletion process should:

1. Load the existing records.
2. Search for the requested ID.
3. Remove the matching record.
4. Keep the remaining records.
5. Rewrite the file without the deleted record.
6. Return whether deletion was successful.

The function should return:

```text
1 = Item successfully deleted
0 = Item not found
```

Conceptually:

```text
Before deletion:

Item 1
Item 2
Item 3
Item 4

Delete Item 2

After deletion:

Item 1
Item 3
Item 4
```

The deleted record should no longer exist in the saved file.

## In-Memory Data Management

The Grade A solution should maintain equipment records in memory while the program is running.

When the program starts:

```text
Read file
   ↓
Load records into Item array
```

The user can then perform operations on the in-memory data.

For example:

```text
Add
Search
Update
Delete
```

When the user saves the data or exits the program:

```text
Item array
    ↓
Write records to file
    ↓
Permanent storage
```

This approach separates the temporary working data from permanent file storage.

## Grade A Menu

The final Grade A solution should provide a simple menu containing operations such as:

```text
--- Media Lab Equipment Loan Manager ---

1. Add Item
2. View Items
3. Search Item
4. Update Item
5. Delete Item
6. Save
7. Exit
```

The program should continue running until the user chooses to exit.

Each menu option should call the appropriate function rather than placing all program logic directly inside `main()`.

This produces a more modular and maintainable program.

## Variable Scope

The Grade A solution should demonstrate appropriate use of both **global** and **local** variables.

### Global Scope

A small number of values that are required throughout the program may be global.

Examples include:

```text
Filename
Maximum array capacity
Shared equipment array where appropriate
```

Global variables should be kept to a minimum.

### Local Scope

Variables required only inside a particular function should normally be local variables.

Examples include:

- Loop counters
- Temporary equipment records
- Search values
- User choices
- Temporary file-handling variables

Local variables exist only inside the function or block where they are declared.

The assessment portfolio should contain a concise explanation of the difference between local and global scope and explain how both are used within the Grade A implementation.

## File Operation Principles

When working with files, the program should follow a clear process:

```text
Open file
    ↓
Check that file opened successfully
    ↓
Read / Write / Append data
    ↓
Close file
```

File operations should be checked so that the program does not attempt to work with a file that failed to open.

Different operations may require different file modes depending on whether the program needs to:

- Read existing data
- Append a new record
- Rewrite all existing records
- Create a new file

## How to Compile and Run

From this folder, compile a program using GCC:

```bash
gcc grade_c_parameter_search.c -o grade_c_parameter_search
```

Run the compiled program:

```bash
./grade_c_parameter_search
```

Replace the filename with the program you want to compile and run.

For example, to compile and run the Grade A solution:

```bash
gcc grade_a_full_loan_manager.c -o grade_a_full_loan_manager
./grade_a_full_loan_manager
```

The program may create or use an additional data file such as:

```text
loans.txt
```

This file should normally remain in the same working directory as the compiled program unless another location is deliberately specified in the source code.

## Suggested Folder Structure

```text
task-7-media-lab-equipment-loan-manager/
│
├── README.md
├── grade_d_basic_file_functions.c
├── grade_c_parameter_search.c
├── grade_b_update_return_values.c
├── grade_a_full_loan_manager.c
└── loans.txt
```

The `loans.txt` file may be created automatically by the program when it first runs rather than being included manually in the repository.

## Testing Suggestions

Each solution should be tested using different equipment records and program operations to demonstrate that it behaves correctly.

Useful test cases include:

- Creating the data file when it does not already exist
- Adding one equipment record
- Adding three or more equipment records
- Displaying all saved records
- Restarting the program and confirming that saved data still exists
- Searching for an existing ID
- Searching for a non-existing ID
- Searching for the first stored record
- Searching for the final stored record
- Attempting to add a duplicate ID
- Confirming that duplicate data is not written to the file
- Adding different asset tags
- Testing different equipment statuses
- Updating an existing asset tag
- Updating an existing status
- Updating both asset tag and status
- Attempting to update an ID that does not exist
- Confirming that old data is replaced after an update
- Confirming that only the intended record is updated
- Deleting the first record
- Deleting a record from the middle
- Deleting the final record
- Attempting to delete an ID that does not exist
- Confirming that a deleted item no longer appears
- Confirming that remaining records are preserved after deletion
- Adding an item through the Grade A menu
- Viewing items through the Grade A menu
- Searching through the Grade A menu
- Updating through the Grade A menu
- Deleting through the Grade A menu
- Saving data
- Exiting the program
- Restarting the program after saving
- Confirming that saved modifications persist between runs
- Invalid menu selections
- Invalid equipment data where appropriate
- File-opening failure handling where practical

For Grade C and above, particular attention should be given to **duplicate-ID prevention**.

For Grade B, updates should be tested carefully to confirm that the original record is replaced correctly when the file is rewritten.

For Grade A, add, update, and delete operations should be tested before and after saving to confirm that both the in-memory records and persistent file data remain consistent.

## Notes

- All programs are written in the C programming language.
- Each file is a separate runnable solution for a different assessment grade band.
- Each higher grade solution builds upon the requirements of the previous grade.
- Assessment Task 7 focuses particularly on functions and file handling.
- The task uses an `Item` structure to group related equipment information.
- Earlier module knowledge including conditions, loops, arrays, strings, validation, and menu logic continues to be applied.
- Week 9 introduced the foundations of functions and modular programming.
- Week 10 develops functions through parameters, arguments, return values, and more reusable program design.
- Week 11 introduces file handling and persistent data storage.
- Grades D, C, and B are intended to demonstrate programming knowledge covered throughout the module up to this stage.
- Grade A may use more advanced C programming techniques where the student already understands them and where they are appropriate for the solution.
- Grade D uses basic functions without parameters or return values.
- Grade C introduces function parameters and searching.
- Grade B introduces informative return values and file-based record updating.
- Grade A introduces deletion, persistent in-memory data management, saving, a complete menu, and variable-scope considerations.
- Grade A should use functions to keep the program modular rather than placing all functionality inside `main()`.
- Grade A requires a concise portfolio explanation of local and global variable scope.
- File operations should be checked for errors and files should be closed correctly after use.
- Updates should replace outdated record data when the file is rewritten.
- Deleted records should no longer appear in the persistent data.
- The source code files should be included in the ZIP submission together with the completed assessment portfolio.
- Screenshots of both the source code and program output should be included in the Word portfolio report.
- Multiple output screenshots should be used where different inputs or operations produce different program behaviour.
- Testing should demonstrate both successful operations and appropriate handling of unsuccessful searches, duplicate IDs, missing records, and invalid choices.
