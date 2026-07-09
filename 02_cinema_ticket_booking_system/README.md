# Assessment Task 2 – Cinema Ticket Booking System

This folder contains four C programming solutions for **Assessment Task 2: Cinema Ticket Booking System** from the **QH0305 Problem Solving** module.

The task is designed to demonstrate programming knowledge developed during the first four weeks of the module. This includes the knowledge from Weeks 1 to 3, such as variables, user input, calculations, conditional statements, and switch statements, together with the new Week 4 topic: loops.

## Task Overview

The Cinema Ticket Booking System calculates the total cost of cinema tickets based on user selections.

The program uses movie types, ticket types, ticket prices, ticket quantity, optional snack combos, discounts, and a menu-driven system depending on the grade level.

The main ticket options are:

- Action movie
- Comedy movie
- Horror movie
- Standard seat
- Premium seat

The assessment requires the use of `switch` / `case` structures to determine ticket prices and, for the highest grade band, to control a menu-driven system.

## Files

| File | Grade Band | Description |
|---|---:|---|
| `grade_d_basic_ticket_price.c` | 40–49 | Uses fixed movie and ticket values. Calculates and displays the price of one cinema ticket using switch/case. |
| `grade_c_multi_ticket_total.c` | 50–59 | Allows the user to enter movie type, ticket type, and number of tickets. Calculates and displays the total ticket cost with basic validation. |
| `grade_b_discount_and_snacks.c` | 60–69 | Adds group discount logic and an optional snack combo. Displays total before discount, discount amount, snack cost, and final total. |
| `grade_a_menu_booking_system.c` | 70–100 | Creates a menu-driven cinema booking system that repeats until the user exits. Allows ticket booking, viewing ticket prices, and full input validation. |

## Topics Practised

### Previous Knowledge from Weeks 1 to 3

This task continues to practise earlier C programming skills, including:

- Basic C program structure
- Variables and data types
- Arithmetic operations
- User input and formatted output
- Conditional statements
- Comparison and logical operators
- Switch/case statements
- Input validation
- Problem-solving using structured program logic

### Week 4 – While Loops and For Loops

This task also applies loop structures introduced in Week 4.

Loops allow a program to repeat actions without writing the same code many times. This makes the program more efficient, easier to read, and easier to maintain.

The main loop concepts practised are:

- `while` loops
- `for` loops
- Repeating menu options
- Repeating user input until the user chooses to exit
- Incrementing and decrementing values
- Controlling when a loop starts and stops
- Avoiding infinite loops
- Using loops to make programs more interactive

## Learning Scope Note

For Grades D, C, and B, the solutions are intended to use only the programming knowledge covered so far in the module. This helps demonstrate progress through the weekly learning topics and shows that each solution matches the expected stage of study.

For Grade A, students may use more advanced C programming knowledge if they already understand it, even if it has not yet been fully covered in future lectures or seminars. However, the solution should still remain clear, readable, and suitable for the assessment requirements.

## Assessment Requirements

To achieve a higher grade band, each program must include the requirements of the previous grade band.

The assessment requires four separate C programs:

1. **D Grade:** Basic ticket price calculation using fixed movie and ticket values.
2. **C Grade:** User input, multiple ticket calculation, and validation of ticket quantity.
3. **B Grade:** Group discount, optional snack combo, final cost calculation, and additional validation.
4. **A Grade:** Menu-driven cinema booking system using switch/case and loops, allowing the user to book tickets, view prices, or exit.

## Ticket Price Table

| Movie Type | Standard Seat | Premium Seat |
|---|---:|---:|
| Action | £10.00 | £15.00 |
| Comedy | £8.00 | £13.00 |
| Horror | £9.00 | £14.00 |

## Program Features by Grade

### Grade D – Basic Ticket Price Calculation

The Grade D solution uses fixed values directly in the code.

It should display:

- Movie type
- Ticket type
- Ticket price formatted to 2 decimal places

### Grade C – User Input and Multi-Ticket Total

The Grade C solution asks the user to enter:

- Movie type
- Ticket type
- Number of tickets

It should validate that the number of tickets is greater than zero, calculate the total cost, and display a clear booking summary.

### Grade B – Group Discount and Optional Snack Add-On

The Grade B solution builds on Grade C and adds:

- A 10% group discount if the number of tickets is greater than 6
- Optional snack combo costing £5.50 per ticket
- Validation for movie type, ticket type, ticket count, and snack combo choice

It should display:

- Movie type
- Ticket type
- Number of tickets
- Total before discount
- Discount amount
- Snack combo cost
- Final total cost

### Grade A – Menu-Driven Cinema Booking System

The Grade A solution builds on Grade B and adds a repeating menu system.

The menu should include:

- Cinema Ticket Booking System
- Book Tickets
-  View Ticket Prices
-  Exit

The program should continue running until the user chooses to exit.

It should validate:

- Invalid menu choices
- Invalid movie types
- Invalid ticket types
- Invalid ticket counts
- Invalid snack combo choices

## How to Compile and Run

From this folder, compile a program using GCC:

```bash
gcc grade_c_multi_ticket_total.c -o grade_c_multi_ticket_total
```

Run the compiled program:

```bash
./grade_c_multi_ticket_total
```

Replace the filename with the program you want to compile and run.

For example, to compile and run the Grade A solution:

```bash
gcc grade_a_menu_booking_system.c -o grade_a_menu_booking_system
./grade_a_menu_booking_system
```

## Suggested Folder Structure

```text
task-2-cinema-ticket-booking-system/
│
├── README.md
├── grade_d_basic_ticket_price.c
├── grade_c_multi_ticket_total.c
├── grade_b_discount_and_snacks.c
└── grade_a_menu_booking_system.c
```

## Testing Suggestions

Each program should be tested with different inputs to show that it works correctly.

Useful test cases include:

- Valid movie type and ticket type
- Invalid movie type
- Invalid ticket type
- Ticket count equal to zero
- Negative ticket count
- Ticket count below the discount limit
- Ticket count above the discount limit
- Snack combo selected
- Snack combo not selected
- Invalid snack combo choice
- Invalid menu choice in the Grade A solution
- Exiting the menu in the Grade A solution

## Notes

- All programs are written in the C programming language.
- Each file is a separate solution for a different assessment grade band.
- The Grade A solution should use loops so the menu can repeat until the user exits.
- The source code files should be included in the ZIP submission together with the completed assessment portfolio.
- Screenshots of both code and output should be included in the Word portfolio report.
- Multiple output screenshots should be used where different input values produce different results.
