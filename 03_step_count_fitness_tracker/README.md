# Assessment Task 3 – Step Count Fitness Tracker Loop Challenge

This folder contains four C programming solutions for **Assessment Task 3: Step Count Fitness Tracker Loop Challenge** from the **QH0305 Problem Solving** module.

The task is designed to demonstrate programming knowledge developed during the first five weeks of the module. This includes the knowledge gained during Weeks 1 to 4, such as variables, user input, calculations, conditional statements, switch statements, and loops, together with the new Week 5 topic: nested loops.

## Task Overview

The Step Count Fitness Tracker is a C program that tracks physical activity and converts different forms of activity data into steps, distance, and estimated calories burned.

Depending on the grade level, the program develops from a simple one-day step conversion into a more advanced fitness tracking system capable of:

- Converting steps into kilometres
- Estimating calories burned
- Tracking activity across multiple days
- Accepting different types of activity input
- Maintaining running totals
- Tracking daily step goals
- Calculating goal progress
- Applying activity intensity levels
- Producing per-day and overall summaries
- Tracking goal streaks

Each grade solution builds upon the requirements of the previous grade.

## Files

| File | Grade Band | Description |
|---|---:|---|
| `grade_d_basic_conversion.c` | 40–49 | Accepts one day's step count and converts it into kilometres and estimated calories burned. |
| `grade_c_multi_day_tracking.c` | 50–59 | Extends the program to track step counts across multiple days using loops and produces overall totals when the user finishes. |
| `grade_b_multi_type_activity.c` | 60–69 | Allows activity to be entered as steps, kilometres, or walking minutes and converts all activity into steps while maintaining running totals. |
| `grade_a_goal_tracking.c` | 70–100 | Adds daily step goals, activity intensity, robust input validation, multi-day tracking, per-day summaries, overall statistics, and goal streak tracking. |

## Topics Practised

### Previous Knowledge from Weeks 1 to 4

This task continues to apply C programming knowledge developed during the previous weeks of the module, including:

- Basic C program structure
- Variables and data types
- Arithmetic operations
- User input and formatted output
- Conditional statements
- Comparison and logical operators
- Switch/case statements
- Input validation
- `while` loops
- `for` loops
- Incrementing and decrementing values
- Repeated user interaction
- Structured problem-solving and program logic

### Week 5 – Nested Loops

Week 5 develops the understanding of loops further by introducing **nested loops**, where one loop is placed inside another.

Nested loops are useful when a program needs to perform repeated operations within another repeating process. They can be particularly useful when working with structured or multi-level data and more complex iteration patterns.

The main concepts introduced during Week 5 include:

- Nested loop structures
- Loops inside other loops
- Managing multiple levels of iteration
- Controlling inner and outer loops
- Using loops for structured and repetitive data processing
- Modifying loop behaviour for specific tasks
- Reducing unnecessary repetition
- Avoiding unnecessary computations
- Writing more scalable and structured C programs

The knowledge developed during Week 5 can be combined with previous loop, conditional, and switch/case knowledge when implementing the different fitness tracker solutions.

## Learning Scope Note

For Grades D, C, and B, the solutions are intended to use only the programming knowledge covered so far in the module, from Week 1 through Week 5. This helps demonstrate progression through the weekly learning topics and ensures that each solution reflects the expected stage of study.

For Grade A, students may use more advanced C programming knowledge if they already understand it, even where those techniques have not yet been fully covered in the current lectures or seminars. More advanced techniques may be used where they help produce a clearer, more structured, or more effective solution, while still satisfying all assessment requirements.

## Assessment Requirements

To achieve a higher grade band, each solution must build upon and include the requirements of the previous grade bands.

The assessment contains four progressive C programming solutions:

1. **D Grade:** Basic conversion of one day's steps into kilometres and estimated calories burned.
2. **C Grade:** Multi-day step tracking using loops and cumulative activity totals.
3. **B Grade:** Multi-type activity tracking using steps, kilometres, and walking minutes.
4. **A Grade:** Daily goal tracking, activity intensity, robust validation, multi-day summaries, and goal streak calculations.

## Conversion Rates

The assessment uses the following fixed conversion rates:

| Conversion | Rate |
|---|---:|
| Steps to Distance | 1 kilometre = 1,250 steps |
| Walking Time to Steps | 1 walking minute = 100 steps |
| Steps to Calories | 1,000 steps = 40 calories |

These conversion rates are used throughout the different grade solutions where applicable.

## Program Features by Grade

### Grade D – Basic Conversion

The Grade D solution creates a basic fitness tracker for one day.

The program should:

- Ask the user to enter the number of steps completed in one day
- Convert the step count into kilometres
- Calculate the estimated calories burned
- Display the total distance walked
- Display the estimated calories burned
- Format kilometres and calories to 2 decimal places

The fixed conversion rates are:

- 1 kilometre = 1,250 steps
- 1,000 steps = 40 calories

Example:

```text
Enter steps for today: 7500
Distance: 6.00 km
Calories burned: 300.00 kcal
```

### Grade C – Multi-Day Step Tracking

The Grade C solution builds on Grade D and allows the program to track activity across multiple days.

The program should:

- Complete all Grade D requirements
- Use a loop to accept step counts for multiple days
- Convert each day's steps into kilometres
- Calculate estimated calories for each day
- Ask the user after each entry whether another day should be entered
- Continue until the user chooses to stop

When tracking finishes, the program should display:

- Number of days tracked
- Total steps
- Total distance in kilometres
- Total estimated calories burned

The use of loops allows the user to continue entering daily activity without restarting the program.

### Grade B – Multi-Type Activity Tracking

The Grade B solution builds on Grade C and allows different types of physical activity data to be entered.

The user should be presented with activity options such as:

```text
What would you like to add?

1: Steps
2: Kilometers
3: Walking minutes
```

The program should:

- Complete all Grade C requirements
- Allow activity to be entered as steps
- Allow activity to be entered as kilometres
- Allow activity to be entered as walking minutes
- Convert every activity type into steps
- Update running activity totals
- Allow the user to return to the activity menu
- Allow the user to exit after an entry

The following conversion rates should be used:

- 1 kilometre = 1,250 steps
- 1 walking minute = 100 steps
- 1,000 steps = 40 calories

When the user exits, the program should display:

- Total steps
- Total kilometres
- Total calories burned
- Number of step entries
- Number of kilometre entries
- Number of walking-minute entries

### Grade A – Goal Tracking, Activity Level, and Streak Summary

The Grade A solution builds on all previous grade requirements and develops the program into a more advanced fitness tracking system.

When the program starts, the user should be asked to set a **daily step goal**.

The program should also allow the user to select an activity intensity:

```text
Select activity intensity:

1: Light walking
2: Moderate walking
3: Fast walking
```

The activity intensity affects the estimated calories burned:

| Activity Intensity | Calorie Adjustment |
|---|---:|
| Light Walking | No adjustment |
| Moderate Walking | +10% |
| Fast Walking | +20% |

After each activity entry, the program should calculate and display the user's progress towards their daily step goal as a percentage.

For example:

```text
Progress: 62.50% of daily goal
```

The Grade A solution should include robust input validation.

It should handle:

- Invalid numeric values
- Zero or negative activity values
- Invalid menu choices
- Invalid yes/no responses
- Invalid activity intensity choices
- Other invalid user inputs where applicable

The program should re-prompt the user until valid input is provided rather than terminating unnecessarily.

The program should also support activity tracking across multiple days.

When tracking finishes, it should produce a **per-day summary** containing:

- Total steps for each day
- Total kilometres for each day
- Calories burned for each day
- Percentage of the daily goal reached

It should then produce an **overall summary** containing:

- Total steps across all days
- Total distance across all days
- Total calories burned
- Number of days meeting or exceeding the daily step goal
- Longest streak of consecutive days meeting or exceeding the daily goal

## How to Compile and Run

From this folder, compile a program using GCC:

```bash
gcc grade_c_multi_day_tracking.c -o grade_c_multi_day_tracking
```

Run the compiled program:

```bash
./grade_c_multi_day_tracking
```

Replace the filename with the program you want to compile and run.

For example, to compile and run the Grade A solution:

```bash
gcc grade_a_goal_tracking.c -o grade_a_goal_tracking
./grade_a_goal_tracking
```

## Suggested Folder Structure

```text
task-3-step-count-fitness-tracker/
│
├── README.md
├── grade_d_basic_conversion.c
├── grade_c_multi_day_tracking.c
├── grade_b_multi_type_activity.c
└── grade_a_goal_tracking.c
```

## Testing Suggestions

Each solution should be tested with different inputs to demonstrate that the program works correctly.

Useful test cases include:

- A normal positive step count
- A small step count
- A large step count
- Multiple days of activity
- Entering activity as steps
- Entering activity as kilometres
- Entering activity as walking minutes
- Multiple activity entries
- Choosing to add another entry
- Choosing to stop entering activity
- Different activity intensity levels
- Activity below the daily step goal
- Activity exactly equal to the daily step goal
- Activity above the daily step goal
- Multiple consecutive days meeting the goal
- Days where the goal is not reached
- Invalid menu choices
- Zero values
- Negative values
- Invalid yes/no responses
- Invalid activity intensity selections
- Exiting the program correctly

For the Grade A solution, testing different combinations of successful and unsuccessful goal days is particularly important to verify that the **longest goal streak** is calculated correctly.

## Notes

- All programs are written in the C programming language.
- Each file is a separate solution for a different assessment grade band.
- Each higher grade solution builds upon the requirements of the previous grade.
- Grades D, C, and B are intended to demonstrate the programming knowledge covered during Weeks 1 to 5.
- Grade A may use more advanced programming techniques where the student already understands them and where they are appropriate for the solution.
- The assessment focuses particularly on conversions, loops, conditional logic, and repeated activity tracking.
- The source code files should be included in the ZIP submission together with the completed assessment portfolio.
- Screenshots of both the source code and program output should be included in the Word portfolio report.
- Multiple output screenshots should be used where different inputs can produce different program behaviour.
- Testing should demonstrate both normal operation and appropriate handling of invalid input.
