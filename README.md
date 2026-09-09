# QH0305 – Problem Solving in C

This repository contains my programming work for the **QH0305 Problem Solving** module, part of the BSc (Hons) Computer Science / BSc (Hons) Cyber Security programme.

The repository documents my progression through the module using the **C programming language**, with seven practical programming assessment tasks and a final reflective assessment.

Each programming task contains separate solutions for the **D, C, B, and A grade bands**, with complexity increasing as the module progresses.

## Module Overview

The module develops fundamental programming and problem-solving skills through a progressive series of practical C programming tasks.

Topics covered throughout the module include:

- C program structure
- Variables and data types
- Arithmetic and logical operators
- User input and formatted output
- Conditional statements
- `switch` / `case`
- `while` and `for` loops
- Nested loops
- Arrays
- Strings and character arrays
- Functions
- Function parameters and return values
- Structures
- Sorting and searching
- File handling
- Data persistence
- Input validation
- Debugging and testing
- Modular program design
- Problem-solving and algorithmic thinking

Each assessment task builds upon knowledge developed during the previous weeks.

## Assessment Tasks

| Task | Project | Main Concepts |
|---|---|---|
| **Task 1** | Weekly Expense Tracker | Variables, operators, calculations, input, conditions |
| **Task 2** | Cinema Ticket Booking System | `switch` / `case`, validation, loops, menu logic |
| **Task 3** | Step Count Fitness Tracker | Conversions, loops, repeated input, activity tracking |
| **Task 4** | Event Countdown Planner 2026 | Date calculations, conditions, loops, validation, navigation |
| **Task 5** | Daily Temperature Logger | Arrays, averages, searching, weekly analysis, pointers |
| **Task 6** | Book Organizer | Arrays of strings, string comparison, sorting, deletion |
| **Task 7** | Media Lab Equipment Loan Manager | Structures, functions, file handling, persistence, CRUD-style operations |
| **Task 8** | Reflective Statement | Reflection on learning, development, progress, strengths, weaknesses, and improvement |

Detailed requirements, implementation notes, testing suggestions, and grade-specific functionality are documented in the individual `README.md` files inside each task folder.

## Grade Bands

The seven programming assessments use four progressive grade bands:

| Grade Band | Percentage | General Level |
|---|---:|---|
| **D** | 40–49% | Basic implementation |
| **C** | 50–59% | Extended functionality |
| **B** | 60–69% | More advanced implementation and problem-solving |
| **A** | 70–100% | Complete and more advanced solution |

To work towards a higher grade band, the requirements of the lower grade bands must also be completed.

For example, an A-grade submission is not intended to replace the D, C, and B solutions. The portfolio demonstrates progression by including the required solutions for each grade level.

## Learning Scope

For **Grades D, C, and B**, solutions are intended to demonstrate the C programming knowledge covered in the module up to the point when each assessment task is completed.

This allows the different solutions to show progression through the module rather than relying unnecessarily on programming techniques that have not yet been taught.

For **Grade A**, more advanced C programming techniques may be used where appropriate if the student already understands them, including techniques that may not yet have been formally covered at that stage of the module.

The priority remains to produce code that is:

- Correct
- Readable
- Structured
- Appropriate for the assessment requirements
- Clearly understood by the student

## Repository Structure

The repository is organised by assessment task.

```text
qho305-problem-solving/
│
├── README.md
│
├── 01_weekly_expense_tracker/
│   ├── README.md
│   ├── grade_d_*.c
│   ├── grade_c_*.c
│   ├── grade_b_*.c
│   └── grade_a_*.c
│
├── 02_cinema_ticket_booking_system/
│   ├── README.md
│   └── ...
│
├── 03_step_count_fitness_tracker/
│   ├── README.md
│   └── ...
│
├── 04_event_countdown_planner/
│   ├── README.md
│   └── ...
│
├── 05_daily_temperature_logger/
│   ├── README.md
│   └── ...
│
├── 06_book_organizer/
│   ├── README.md
│   └── ...
│
└── 07_media_lab_equipment_loan_manager/
    ├── README.md
    └── ...
```

Each task folder contains its own README with the full grade-specific requirements and information about the solution.

## Assessment Task 8 – Reflective Statement

Assessment Task 8 is different from Tasks 1–7 because it does not require another C program.

Instead, it requires a **reflective statement covering the experience of the module as a whole**.

The reflection considers areas such as:

- Skills developed during the module
- Personal strengths and weaknesses
- Areas requiring further improvement
- How progress was monitored
- How areas for improvement were identified
- Time management
- Managing multiple assessments and tasks
- What could have been changed or improved in previous assessment work

The reflective statement:

- Is a mandatory part of the portfolio
- Should have its own clearly identifiable heading
- Should appear at the end of the portfolio
- May be written in the first person
- Should not exceed **1,000 words ±10%**

Unlike Tasks 1–7, Task 8 does not require a separate D, C, B, or A C source-code solution.

## Assessment Portfolio

The complete module assessment consists of **eight tasks**:

- **Tasks 1–7:** C programming assessment tasks
- **Task 8:** Final reflective statement

For the programming tasks, the portfolio should provide evidence of both the source code and the program output.

Where a program can produce different results depending on the input, multiple examples should be provided to demonstrate that the solution has been tested appropriately.

The C source files are also submitted as part of the required source-code ZIP alongside the portfolio.

## Compilation

The programs can be compiled using GCC.

General example:

```bash
gcc program.c -o program
```

Run the compiled program:

```bash
./program
```

On Windows, the generated executable will normally be:

```text
program.exe
```

The exact compilation command for individual solutions can be found in each task's README.

## Development Environment

The projects in this repository are written using:

- **Language:** C
- **Compiler:** GCC
- **Editor / IDE:** Visual Studio Code
- **Version Control:** Git
- **Repository Hosting:** GitHub

## Purpose of This Repository

This repository serves as a structured record of my development throughout the **QH0305 Problem Solving** module.

Rather than containing only final solutions, it demonstrates progression from basic C programs to more structured applications involving arrays, strings, functions, algorithms, structures, and persistent file storage.

The individual task folders document each stage of that progression, while the complete assessment portfolio provides the accompanying explanation, testing evidence, analysis, and reflection.
