# Assessment Task 1 – Weekly Expense Tracker

This folder contains four C programming solutions for **Assessment Task 1: Weekly Expense Tracker** from the **QH0305 Problem Solving** module.

The task is designed to demonstrate programming knowledge developed during the first three weeks of the module, including C programming fundamentals, variables, user input, calculations, conditional statements, and switch statements.

## Task Overview

The Weekly Expense Tracker program records spending across categories such as:

* Food
* Transport
* Entertainment

The programs calculate weekly spending totals, daily averages, budget status, and spending changes between two weeks. Each solution builds upon the previous grade requirements.

## Files

| File                            | Grade Band | Description                                                                                                                                                             |
| ------------------------------- | ---------: | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `grade_d_weekly_total.c`        |      40–49 | Uses fixed spending values stored directly in variables. Calculates and displays category spending and the total weekly amount.                                         |
| `grade_c_user_input.c`          |      50–59 | Allows the user to enter spending values, calculates the weekly total and daily average, checks a budget limit, and validates negative input.                           |
| `grade_b_two_week_comparison.c` |      60–69 | Tracks spending for Week 1 and Week 2, compares both weeks against the budget, and identifies whether overall spending increased, decreased, or stayed the same.        |
| `grade_a_dynamic_categories.c`  |     70–100 | Allows the user to choose the number and names of spending categories, records two weeks of spending, and provides detailed overall and per-category trend comparisons. |

## Topics Practised

### Week 1 – Introduction to C Programming

* Basic C program structure
* Variables and data types
* Arithmetic operations
* Formatted output using `printf()`
* User input using `scanf()`
* Basic debugging

### Week 2 – Conditional Statements

* `if` statements
* `if-else` statements
* `else-if` statements
* Comparison operators, such as `==`, `!=`, `<`, `>`, `<=`, and `>=`
* Logical operators, such as `&&` and `||`
* Input validation
* Budget decision-making logic

### Week 3 – Switch Statements

* `switch` statements
* `case` labels
* `break` statements
* `default` cases
* Organising multiple program choices clearly
* Repeating actions based on conditions

## Assessment Requirements

To achieve a higher grade band, each program must include the requirements of the previous grade band.

The assessment requires four separate C programs:

1. **D Grade:** Basic weekly spending total using values assigned directly in the code.
2. **C Grade:** User input, daily average calculation, budget comparison, and negative-value validation.
3. **B Grade:** Two-week spending tracking and comparison.
4. **A Grade:** Dynamic category names, two-week category-level tracking, and detailed trend analysis.

The assessment also requires screenshots of the code and program output to be included in the portfolio report. Where different input values produce different outcomes, multiple output screenshots should be provided to demonstrate that the program works correctly.

## How to Compile and Run

From this folder, compile a program using GCC:

```bash
gcc grade_c_user_input.c -o grade_c_user_input
```

Run the compiled program:

```bash
./grade_c_user_input
```

Replace the filename with the program you want to compile and run.

## Suggested Folder Structure

```text
task-1-weekly-expense-tracker/
│
├── README.md
├── grade_d_weekly_total.c
├── grade_c_user_input.c
├── grade_b_two_week_comparison.c
└── grade_a_dynamic_categories.c
```

## Notes

* All programs are written in the C programming language.
* Each file is a separate solution for a different assessment grade band.
* Programs should be tested using valid values, zero values, negative values, and values above or below the selected weekly budget.
* The source code files should be included in the ZIP submission together with the completed assessment portfolio.
