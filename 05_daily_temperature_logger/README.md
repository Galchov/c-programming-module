# Assessment Task 5 – Daily Temperature Logger

This folder contains four C programming solutions for **Assessment Task 5: Daily Temperature Logger** from the **QH0305 Problem Solving** module.

The task is designed to apply and extend the programming knowledge developed throughout the module so far. It combines knowledge from previous weeks with the Week 7 topic of arrays and the Week 8 introduction to strings and character arrays.

The assessment itself focuses particularly on storing temperature readings in arrays, processing those readings using loops, providing a menu-driven interface, performing calculations, validating user choices, and progressively introducing more advanced data-handling techniques.

## Task Overview

The Daily Temperature Logger is a C program that stores and analyses daily temperature readings for a given period.

Depending on the grade level, the program develops from a basic array-based temperature logger into a more complete menu-driven application capable of:

- Recording daily temperature readings
- Storing multiple values in arrays
- Displaying all recorded temperatures
- Calculating an overall average temperature
- Finding the highest and lowest temperature
- Repeating menu operations using loops
- Handling invalid menu choices
- Counting temperatures above and below a threshold
- Calculating weekly temperature averages
- Processing incomplete weeks correctly
- Reversing temperature readings
- Displaying readings using relative-day labels
- Traversing and processing arrays using pointers
- Keeping the program running until the user chooses to exit

Each grade solution builds upon the requirements of the previous grade.

## Files

| File | Grade Band | Description |
|---|---:|---|
| `grade_d_basic_array_average.c` | 40–49 | Stores daily temperature readings in an array, displays all readings, and calculates the overall average temperature. |
| `grade_c_high_low_menu.c` | 50–59 | Adds highest and lowest temperature calculations, a repeating menu loop, an exit option, and invalid menu-choice handling. |
| `grade_b_threshold_weekly_average.c` | 60–69 | Uses fixed-size array storage with an appropriate end marker, adds threshold analysis, and calculates weekly averages. |
| `grade_a_reverse_pointers.c` | 70–100 | Adds reverse reading display with relative-day labels and uses pointers to traverse, reverse, and analyse the temperature readings. |

## Topics Practised

### Previous Knowledge from Earlier Weeks

This task continues to apply and combine C programming knowledge developed during the previous weeks of the module, including:

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
- Repeated user interaction
- Menu-driven program logic
- Running totals
- Average calculations
- Structured problem-solving
- Debugging and testing
- Writing readable and organised C programs

### Week 7 – Arrays

Week 7 introduces **arrays**, which allow multiple values of the same data type to be stored under one variable name.

Instead of creating a separate variable for every temperature reading, an array allows the program to store many readings together and access each value using an index.

The main array concepts practised include:

- Declaring arrays
- Initialising arrays
- Storing multiple values
- Accessing individual array elements
- Using array indexes
- Iterating through arrays using loops
- Accepting user input into arrays
- Processing stored values
- Calculating totals and averages from array data
- Finding minimum and maximum values
- Understanding array size
- Working with fixed-size arrays
- Introduction to multidimensional arrays

Arrays are particularly important for this task because the program must store and process several daily temperature readings.

### Week 8 – Strings in C

Week 8 introduces **strings in C**.

In C, a string is represented as an array of characters ending with the special null terminator:

```text
\0
```

The topics introduced during Week 8 include:

- Character arrays
- String declaration and initialisation
- Understanding the null terminator
- Iterating through characters using loops
- Basic string manipulation
- Processing text data
- Swapping values between different data types

Assessment Task 5 itself mainly focuses on numerical arrays and temperature processing rather than requiring extensive string manipulation. However, the Week 8 knowledge forms part of the broader C programming skills being developed at this stage of the module.

## Learning Scope Note

For Grades D, C, and B, the solutions are intended to use programming knowledge covered so far in the module. This includes the concepts introduced during the previous weeks together with arrays introduced in Week 7 and the relevant knowledge available by the time of Assessment Task 5.

This helps demonstrate progression through the module and ensures that each solution reflects the expected stage of study.

For Grade A, students may use more advanced C programming knowledge if they already understand it, even where some techniques have not yet been fully covered in earlier lectures or seminars.

In this assessment, Grade A specifically introduces the use of **pointers**, including using pointers to traverse readings, reverse readings, and find the highest and lowest temperature values.

More advanced techniques may be used where they help produce a clearer, more structured, efficient, or effective solution while still satisfying all assessment requirements.

## Assessment Requirements

To achieve a higher grade band, each solution must build upon and include the requirements of the previous grade bands.

The assessment contains four progressive C programming solutions:

1. **D Grade:** Basic temperature storage using an array, displaying readings, and calculating the overall average.
2. **C Grade:** Highest and lowest temperature calculations, a repeating menu, an exit option, and invalid menu-choice handling.
3. **B Grade:** Fixed-size array storage, threshold analysis, weekly temperature averages, and appropriate handling of incomplete weeks.
4. **A Grade:** Reversing temperature readings, displaying relative-day labels, and using pointers for array traversal and analysis.

## Full Menu Structure

The final Grade A version should contain the complete menu functionality.

A suitable menu structure is:

```text
Menu:

1. Display all temperature readings
2. Calculate average temperature
3. Find highest and lowest temperature
4. Count days above and below threshold
5. Calculate weekly averages
6. Reverse readings
7. Exit
```

Lower grade solutions only need to implement the menu options required for their respective grade bands.

## Program Features by Grade

### Grade D – Basic Array Storage and Average

The Grade D solution introduces the use of an array to store daily temperature readings.

The program should first ask the user how many days they want to record.

The maximum number of days is:

```text
30
```

The program should then:

- Create an array for the temperature readings
- Ask the user to enter a temperature for each day
- Store each temperature in the array
- Provide a menu
- Allow the user to display all recorded temperatures
- Allow the user to calculate the overall average temperature

The Grade D menu should implement:

```text
1. Display all temperature readings
2. Calculate average temperature
```

Example input:

```text
How many days do you want to record? 3

Enter temperature for day 1: 18.5
Enter temperature for day 2: 20.0
Enter temperature for day 3: 17.5
```

Displaying the readings could produce:

```text
Day 1: 18.5°C
Day 2: 20.0°C
Day 3: 17.5°C
```

The average should be calculated from all stored readings.

For the example above:

```text
Average Temperature: 18.67°C
```

The user should demonstrate both menu options when testing the Grade D solution.

### Grade C – Highest, Lowest, and Menu Loop

The Grade C solution builds on all Grade D requirements.

The program should additionally:

- Find the highest recorded temperature
- Find the lowest recorded temperature
- Add an Exit option
- Run the menu repeatedly using a loop
- Continue running until the user chooses Exit
- Handle invalid menu choices gracefully
- Display an error message for an invalid menu choice
- Return the user to the menu after an invalid choice

The Grade C menu should contain:

```text
Menu:

1. Display all temperature readings
2. Calculate average temperature
3. Find highest and lowest temperature
7. Exit
```

For example:

```text
Enter choice: 3

Highest Temperature: 22.4°C
Lowest Temperature: 15.8°C
```

If an invalid menu option is entered:

```text
Enter choice: 9

Invalid choice. Please try again.
```

The program should then return to the menu rather than terminating.

When the user chooses option 7:

```text
Enter choice: 7

Exiting program...
```

### Grade B – Threshold and Weekly Averages

The Grade B solution builds on all Grade C requirements.

The temperature readings array should be changed to use a **fixed size**, for example:

```text
50
```

The program should use an appropriate **terminator or sentinel value** to indicate where the valid temperature entries finish.

The Grade B solution should add two additional menu options.

#### Threshold Analysis

The program should ask the user for a temperature threshold.

For example:

```text
Enter temperature threshold: 20
```

It should then count and display how many recorded days are:

- Above the threshold
- Below the threshold

For example:

```text
Days above threshold: 4
Days below threshold: 6
```

#### Weekly Average Calculation

The program should also calculate average temperatures for individual weeks.

The assessment defines:

```text
Day 1 = Start of Week 1
Every 7 entries = One week
```

For example:

```text
Days 1–7   = Week 1
Days 8–14  = Week 2
Days 15–21 = Week 3
```

If the final week contains fewer than seven readings, the program should calculate the average using only the available readings.

For example:

```text
Week 1 Average: 19.43°C
Week 2 Average: 21.10°C
```

The Grade B menu should contain:

```text
Menu:

1. Display all temperature readings
2. Calculate average temperature
3. Find highest and lowest temperature
4. Count days above and below threshold
5. Calculate weekly averages
7. Exit
```

All existing menu actions should continue to work correctly.

The program should also include a brief explanation of the implemented logic either through appropriate in-code comments or within the assessment portfolio.

### Grade A – Reverse Readings and Pointer Implementation

The Grade A solution builds upon all Grade B requirements and completes the full Daily Temperature Logger.

The Grade A solution should add:

```text
6. Reverse readings
```

The complete menu should therefore be:

```text
Menu:

1. Display all temperature readings
2. Calculate average temperature
3. Find highest and lowest temperature
4. Count days above and below threshold
5. Calculate weekly averages
6. Reverse readings
7. Exit
```

### Reverse Reading Display

The program should display the temperature readings in reverse order.

The final entry in the array represents the most recent day.

The reversed output should use relative-day labels.

For example:

```text
Today: 21.5°C
Yesterday: 19.8°C
2 days ago: 20.1°C
3 days ago: 18.9°C
```

The program should therefore interpret:

- Last recorded value as `Today`
- Previous value as `Yesterday`
- Earlier values as `2 days ago`, `3 days ago`, and so on

### Pointer Implementation

The Grade A solution should also use **pointers** instead of array indexing for selected parts of the program.

Pointers should be used to:

- Traverse the temperature readings
- Reverse the readings
- Find the highest temperature
- Find the lowest temperature

The menu loop, validation, and program output should remain clear and well formatted.

## Grade A Pointer Research

In addition to the program, the Grade A requirements include approximately **200–300 words of research explaining pointers and their use in this task**.

The explanation should cover:

- What pointers are
- How pointers work
- Why pointers are useful in this program
- How pointers can be used to access array values
- How pointer arithmetic can be used when traversing an array
- How pointers are used when reversing the readings
- How pointers can be used when finding the highest and lowest values

This research should be included in the assessment portfolio rather than only appearing as source-code comments.

## How to Compile and Run

From this folder, compile a program using GCC:

```bash
gcc grade_c_high_low_menu.c -o grade_c_high_low_menu
```

Run the compiled program:

```bash
./grade_c_high_low_menu
```

Replace the filename with the program you want to compile and run.

For example, to compile and run the Grade A solution:

```bash
gcc grade_a_reverse_pointers.c -o grade_a_reverse_pointers
./grade_a_reverse_pointers
```

## Suggested Folder Structure

```text
task-5-daily-temperature-logger/
│
├── README.md
├── grade_d_basic_array_average.c
├── grade_c_high_low_menu.c
├── grade_b_threshold_weekly_average.c
└── grade_a_reverse_pointers.c
```

## Testing Suggestions

Each solution should be tested with different values and menu choices to demonstrate that the program works correctly.

Useful test cases include:

- Recording one temperature
- Recording several temperatures
- Recording the maximum intended number of readings
- Positive temperatures
- Zero-degree temperatures
- Negative temperatures
- Decimal temperature values
- Displaying all stored readings
- Calculating the average of several readings
- Finding the highest temperature
- Finding the lowest temperature
- Using identical temperature readings
- Entering an invalid menu choice
- Returning to the menu after completing an action
- Exiting the program correctly
- Using a threshold lower than all readings
- Using a threshold higher than all readings
- Using a threshold between recorded readings
- Temperatures exactly equal to the threshold
- Seven readings for one complete week
- More than seven readings
- Fourteen readings for two complete weeks
- An incomplete final week
- Reversing several readings
- Checking that the latest reading displays as `Today`
- Checking that the previous reading displays as `Yesterday`
- Checking relative labels such as `2 days ago`
- Verifying pointer-based highest and lowest calculations
- Verifying pointer traversal produces the correct readings

For Grade B, particular attention should be given to weekly averages where the final week contains fewer than seven readings.

For Grade A, the pointer-based operations should be tested carefully to ensure they produce the same correct results as equivalent array-indexing operations.

## Notes

- All programs are written in the C programming language.
- Each file is a separate runnable solution for a different assessment grade band.
- Each higher grade solution builds upon the requirements of the previous grade.
- Assessment Task 5 introduces significant practical use of arrays for storing and processing multiple temperature readings.
- Week 7 focuses on arrays and their use with loops for storing and processing multiple values.
- Week 8 introduces strings as null-terminated character arrays and further develops understanding of how arrays are represented and processed in C.
- The assessment itself primarily uses numerical arrays rather than requiring extensive string manipulation.
- Grades D, C, and B are intended to demonstrate the programming knowledge covered in the module up to this stage.
- Grade A may use more advanced programming techniques where required or where the student already understands them.
- Grade A specifically requires the use and explanation of pointers.
- Grade A requires approximately 200–300 words explaining pointers and their application to the task.
- Only the final Grade A version needs to contain all menu options.
- The Grade B solution should include a brief explanation of its logic through in-code comments or within the portfolio.
- The source code files should be included in the ZIP submission together with the completed assessment portfolio.
- Screenshots of both the source code and program output should be included in the Word portfolio report.
- Multiple output screenshots should be used where different inputs or menu selections produce different program behaviour.
- Testing should demonstrate both normal operation and appropriate handling of invalid input.
