# Assessment Task 6 – Book Organizer

This folder contains four C programming solutions for **Assessment Task 6: Book Organizer** from the **QH0305 Problem Solving** module.

The task is designed to apply and extend the programming knowledge developed throughout the module so far. It builds on the knowledge gained during Weeks 1 to 8, including variables, conditional logic, loops, arrays, and strings.

Week 9 introduces functions and modular programming. Although functions are not explicitly required by every grade band in this assessment, they form part of the current learning context and can be used where appropriate to make programs clearer, more organised, and easier to maintain.

## Task Overview

The Book Organizer is a C program that stores and manages a catalogue of book titles using an array of strings.

Depending on the grade level, the program develops from simply displaying book titles into a more complete catalogue-management program capable of:

- Storing multiple book titles
- Traversing an array of strings
- Accessing individual titles using array indexes
- Comparing book titles alphabetically
- Performing case-insensitive comparisons
- Swapping string values
- Moving the alphabetically earliest title to the beginning
- Sorting an entire catalogue
- Using nested loops to implement a sorting algorithm
- Searching for a book title
- Deleting a book from the catalogue
- Shifting remaining titles to remove gaps
- Implementing more than one sorting algorithm
- Comparing sorting algorithms in terms of logic and performance

Each grade solution builds upon the requirements of the previous grade.

## Files

| File | Grade Band | Description |
|---|---:|---|
| `grade_d_basic_book_array.c` | 40–49 | Creates an array containing eight book titles and uses a loop to display the current title together with the title stored at index 0. |
| `grade_c_first_title_sort.c` | 50–59 | Performs a single comparison pass to move the alphabetically earliest title to index 0 using case-insensitive comparison and string swapping. |
| `grade_b_full_catalogue_sort.c` | 60–69 | Uses nested loops to sort the complete book catalogue alphabetically and displays the list before and after sorting. |
| `grade_a_delete_and_bubble_sort.c` | 70–100 | Adds book deletion and array shifting, implements a different sorting algorithm such as Bubble Sort, and compares the sorting algorithms. |

## Topics Practised

### Previous Knowledge from Weeks 1 to 8

This task continues to apply and combine C programming knowledge developed throughout the previous weeks of the module, including:

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
- Incrementing and decrementing values
- Arrays
- Array indexing
- Iterating through arrays
- Character arrays
- Strings in C
- Null-terminated strings
- String processing
- Repeated data processing
- Menu and control-flow logic
- Structured problem-solving
- Debugging and testing

### Week 7 – Arrays

Week 7 introduced **arrays**, which allow multiple values of the same data type to be stored and managed together.

Arrays are especially important for Assessment Task 6 because multiple book titles need to be stored inside a single collection.

Important array concepts used in this task include:

- Declaring arrays
- Initialising arrays
- Accessing elements using indexes
- Iterating through arrays using loops
- Modifying stored values
- Swapping values
- Understanding array size
- Shifting array elements
- Combining arrays with nested loops
- Processing multiple related values efficiently

### Week 8 – Strings in C

Week 8 introduced **strings**, which in C are represented using character arrays terminated by the null character:

```text
\0
```

Strings are central to this assessment because every book title is stored and processed as text.

The relevant concepts include:

- Character arrays
- String declaration and initialisation
- Null-terminated strings
- Storing multiple strings
- Accessing individual characters
- Comparing strings
- Copying or swapping string values
- Processing strings using loops
- Handling text-based user input

The Book Organizer combines arrays and strings by storing multiple book titles in a collection that can then be displayed, compared, sorted, searched, and modified.

### Week 9 – Functions

Week 9 introduces **functions**, allowing larger programs to be divided into smaller, reusable, and manageable sections.

Functions improve program structure by allowing individual operations to be separated into logical units.

The main concepts introduced include:

- Library functions
- User-defined functions
- Function declarations
- Function definitions
- Function calls
- Function parameters
- Functions with return values
- Functions without return values
- Reusing program logic
- Improving readability
- Reducing duplicated code
- Making programs easier to debug and maintain

Functions are not explicitly required by every grade band in Assessment Task 6. However, they may be used where appropriate to organise operations such as displaying books, comparing titles, sorting the catalogue, searching for books, or deleting entries.

## Learning Scope Note

For Grades D, C, and B, the solutions are intended to use programming knowledge covered so far in the module. The main concepts required by this assessment are based on the knowledge developed through Weeks 1 to 8, particularly loops, nested loops, arrays, and strings.

Where appropriate, the Week 9 introduction to functions may also be applied to improve code organisation without unnecessarily introducing techniques beyond the current stage of study.

This approach helps demonstrate progression through the module and ensures that each solution reflects the programming knowledge expected at this stage.

For Grade A, students may use more advanced C programming knowledge if they already understand it, even where those techniques have not yet been covered in later lectures or seminars.

More advanced techniques may be used where they help produce a clearer, more structured, efficient, or effective solution, while still satisfying all assessment requirements.

## Assessment Requirements

To achieve a higher grade band, each solution must build upon and include the requirements of the previous grade bands.

The assessment contains four progressive C programming solutions:

1. **D Grade:** Basic storage and traversal of an array containing eight book titles.
2. **C Grade:** A single comparison pass that moves the alphabetically earliest title to index 0.
3. **B Grade:** Complete alphabetical sorting using nested loops and repeated string swapping.
4. **A Grade:** Book deletion, array shifting, implementation of a different sorting algorithm, and comparison between sorting approaches.

## Book Catalogue Structure

The program should work with a single collection containing **eight book titles**.

The titles should initially be placed in deliberately mixed alphabetical order.

Conceptually, the catalogue may look like:

```text
Index 0 -> First book title
Index 1 -> Second book title
Index 2 -> Third book title
...
Index 7 -> Eighth book title
```

Because each book title is itself a string, the program is effectively working with multiple character arrays stored together.

The exact implementation may depend on the techniques used in each grade solution.

## Alphabetical Sorting

From Grade C onwards, the program begins comparing book titles alphabetically.

The comparison should be:

```text
Case-insensitive
```

This means that differences between uppercase and lowercase letters should not change the intended alphabetical ordering.

For example:

```text
"Archive"
"echo"
"Lantern"
"north"
```

should still be interpreted according to alphabetical order rather than simply treating uppercase and lowercase characters as unrelated values.

## Program Features by Grade

### Grade D – Basic String Array Display

The Grade D solution introduces the book catalogue as an array containing eight strings.

The program should:

- Create an array containing 8 book titles
- Store the titles in deliberately mixed alphabetical order
- Use a loop to traverse the catalogue
- Display the current title during each iteration
- Display the title stored at index 0 during each iteration
- Leave the catalogue unchanged
- Perform no sorting or other manipulation

The output structure should follow the principle:

```text
Current Title: "<current book>"
First Title: "<book at index 0>"
```

For example:

```text
Current Title: "North Passage"
First Title: "North Passage"

Current Title: "Echoes of the Atrium"
First Title: "North Passage"

Current Title: "Archive Key"
First Title: "North Passage"
```

The value displayed as `First Title` remains the same because no sorting or manipulation occurs at Grade D.

This grade mainly demonstrates:

- String arrays
- Array indexing
- Loops
- Accessing stored values
- Formatted output

### Grade C – Move the Earliest Title to Index 0

The Grade C solution builds upon all Grade D requirements.

The loop should now perform a **single comparison pass** through the catalogue.

The aim is to find the alphabetically earliest book title and move it to:

```text
Index 0
```

The program should:

- Complete all Grade D requirements
- Compare each title with the title currently stored at index 0
- Use case-insensitive alphabetical comparison
- Determine whether the current title comes before the title at index 0
- Swap the titles when an earlier title is found
- Continue checking the remaining titles
- Print the catalogue before the loop
- Print the catalogue after the loop
- Avoid printing intermediate results while the comparison loop is running

For example:

```text
Before:
"North Passage", "Echoes of the Atrium", "Archive Key", "Lantern Works"

After:
"Archive Key", "Echoes of the Atrium", "North Passage", "Lantern Works"
```

Only the alphabetically earliest title should be guaranteed to move to the front.

The remaining catalogue is **not yet fully sorted** at Grade C.

This grade develops understanding of:

- String comparison
- Case-insensitive comparison
- Array traversal
- Conditional logic
- Swapping values
- Controlled modification of an array

### Grade B – Full Alphabetical Sorting

The Grade B solution builds upon all Grade C requirements.

Instead of moving only the earliest title to index 0, the program should sort the **entire catalogue** alphabetically.

The program should:

- Complete all Grade C requirements
- Use nested loops
- Divide the array conceptually into sorted and unsorted sections
- Find the earliest title in the remaining unsorted section
- Swap it with the first unsorted title
- Repeat the process until the entire array is sorted
- Display the catalogue before sorting
- Display the catalogue after sorting

The sorting logic follows the same principle introduced at Grade C, but repeats the process for each remaining position.

Conceptually:

```text
Pass 1 -> Find earliest title -> Move to index 0
Pass 2 -> Find earliest remaining title -> Move to index 1
Pass 3 -> Find earliest remaining title -> Move to index 2
...
```

Example:

```text
Before:
"North Passage", "Echoes of the Atrium", "Archive Key", "Lantern Works"

After:
"Archive Key", "Echoes of the Atrium", "Lantern Works", "North Passage"
```

The program should also include comments or portfolio discussion explaining how the sorting process works.

Important concepts demonstrated include:

- Nested loops
- Sorted and unsorted sections
- Repeated comparison
- String swapping
- Complete array sorting
- Algorithmic problem-solving

## Grade B Sorting Logic

The Grade B algorithm follows a selection-style approach.

During each outer-loop iteration:

1. One array position becomes the current position being sorted.
2. The remaining unsorted titles are examined.
3. The alphabetically earliest remaining title is identified.
4. That title is swapped with the first title in the unsorted section.
5. The sorted section becomes one element larger.
6. The process repeats until all titles are correctly ordered.

The portfolio should explain this logic clearly rather than relying only on source-code screenshots.

### Grade A – Delete a Book and Implement Another Sorting Algorithm

The Grade A solution builds upon all Grade B requirements and adds more advanced catalogue management.

The user should be allowed to enter a book title that they want to delete.

The program should search the catalogue for the requested title.

### Book Found

If the title is found:

- Remove the selected title
- Shift all following titles one position towards the beginning of the array
- Ensure that there is no unused gap between valid titles
- Update the number of valid books if necessary

Conceptually:

```text
Before deletion:

Index 0 -> Book A
Index 1 -> Book B
Index 2 -> Book C
Index 3 -> Book D

Delete Book B

After deletion:

Index 0 -> Book A
Index 1 -> Book C
Index 2 -> Book D
```

The remaining entries must therefore be shifted to maintain a continuous catalogue.

### Book Not Found

If the entered title cannot be found, the program should display an appropriate message rather than attempting to modify the catalogue.

For example:

```text
Book title not found.
```

### Alternative Sorting Algorithm

The Grade A solution must also implement a **different sorting algorithm** from the approach used for Grade B.

One suggested algorithm is:

```text
Bubble Sort
```

Bubble Sort repeatedly compares neighbouring titles.

If two neighbouring titles are in the wrong alphabetical order, they are swapped.

For example:

```text
Book B, Book A
```

becomes:

```text
Book A, Book B
```

Multiple passes are made through the array until the complete catalogue is sorted.

The Grade A solution should therefore demonstrate at least two different approaches to sorting:

- The original Grade B sorting method
- A different algorithm such as Bubble Sort

## Grade A Algorithm Comparison

The Grade A portfolio should contain a thorough comparison between the original sorting algorithm and the newly implemented algorithm.

The discussion should consider areas such as:

- How each algorithm works
- How titles are compared
- When swaps occur
- How many passes through the array may be required
- Differences in program logic
- Ease of understanding
- Ease of implementation
- Performance
- Behaviour with already sorted data
- Behaviour with data in reverse order
- Suitability for small arrays
- Advantages and disadvantages of each approach

The comparison should explain the algorithms rather than simply state which one is better.

## How to Compile and Run

From this folder, compile a program using GCC:

```bash
gcc grade_c_first_title_sort.c -o grade_c_first_title_sort
```

Run the compiled program:

```bash
./grade_c_first_title_sort
```

Replace the filename with the program you want to compile and run.

For example, to compile and run the Grade A solution:

```bash
gcc grade_a_delete_and_bubble_sort.c -o grade_a_delete_and_bubble_sort
./grade_a_delete_and_bubble_sort
```

## Suggested Folder Structure

```text
task-6-book-organizer/
│
├── README.md
├── grade_d_basic_book_array.c
├── grade_c_first_title_sort.c
├── grade_b_full_catalogue_sort.c
└── grade_a_delete_and_bubble_sort.c
```

## Testing Suggestions

Each solution should be tested using different book-title arrangements and user inputs to demonstrate that the program works correctly.

Useful test cases include:

- Eight book titles in mixed alphabetical order
- Displaying every title in the Grade D array
- Confirming that index 0 remains unchanged during Grade D
- Earliest title initially stored at index 0
- Earliest title stored in the middle of the array
- Earliest title stored at the final index
- Titles beginning with uppercase letters
- Titles beginning with lowercase letters
- Case-insensitive comparisons
- Confirming that Grade C moves only the earliest title to the front
- A completely unsorted catalogue
- An already sorted catalogue
- A catalogue in reverse alphabetical order
- Confirming that all titles are sorted correctly in Grade B
- Searching for an existing book
- Searching for a non-existing book
- Deleting the first book
- Deleting a book from the middle
- Deleting the final book
- Confirming that titles shift correctly after deletion
- Confirming that no gap remains after deletion
- Sorting after deleting a title
- Testing the Grade B sorting algorithm
- Testing the Grade A alternative sorting algorithm
- Comparing results from both sorting algorithms
- Confirming that both algorithms produce the same final alphabetical order

For Grade C and above, particular attention should be given to **case-insensitive comparisons**.

For Grade B, the nested loops should be tested with differently ordered catalogues to confirm that the complete list becomes alphabetically sorted.

For Grade A, deletion should be tested at the beginning, middle, and end of the valid catalogue to confirm that array shifting works correctly.

## Notes

- All programs are written in the C programming language.
- Each file is a separate runnable solution for a different assessment grade band.
- Each higher grade solution builds upon the requirements of the previous grade.
- Assessment Task 6 focuses particularly on sorting algorithms and handling strings.
- The program works with an array containing multiple book titles.
- Week 7 array knowledge is important for storing and manipulating the catalogue.
- Week 8 string knowledge is central to storing, comparing, copying, and sorting book titles.
- Week 9 introduces functions and modular programming, which may be applied where appropriate to improve program organisation.
- Grades D, C, and B are intended to demonstrate programming knowledge covered at this stage of the module.
- Grade A may use more advanced programming techniques where the student already understands them and where they are appropriate for the solution.
- Grade B requires an explanation of how the implemented sorting process works.
- Grade A requires a different sorting algorithm from the Grade B approach.
- Grade A requires a thorough comparison of the original and alternative sorting algorithms in terms of logic and performance.
- When deleting a book in Grade A, the remaining array entries must be shifted so that no gap remains.
- The source code files should be included in the ZIP submission together with the completed assessment portfolio.
- Screenshots of both the source code and program output should be included in the Word portfolio report.
- Multiple output screenshots should be used where different inputs or catalogue arrangements produce different program behaviour.
- Testing should demonstrate both normal operation and appropriate handling of unsuccessful searches or other relevant cases.
