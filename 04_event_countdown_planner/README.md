# Assessment Task 4 – Event Countdown Planner 2026

This folder contains four C programming solutions for **Assessment Task 4: Event Countdown Planner 2026** from the **QH0305 Problem Solving** module.

The task is designed to consolidate and apply the programming knowledge developed throughout Weeks 1 to 5 of the module.

Week 6 introduces no new C programming concepts. Instead, it focuses on revision, problem-solving, debugging, logical thinking, and combining previously learned programming techniques to create more complete and structured solutions.

## Task Overview

The Event Countdown Planner 2026 is a C program that helps the user track important events during the year 2026.

Depending on the grade level, the program develops from a basic approximate date calculation into a more advanced event management system capable of:

- Accepting current and future event dates
- Calculating the number of days remaining until an event
- Using correct month lengths
- Validating dates
- Determining whether an event is upcoming or has already passed
- Calculating the weekday of an event
- Tracking multiple events
- Highlighting urgent events
- Navigating forwards and backwards between stored events
- Adding additional events while the program is running
- Keeping the program active until the user chooses to exit

Each grade solution builds upon the requirements of the previous grade.

## Files

| File | Grade Band | Description |
|---|---:|---|
| `grade_d_basic_countdown.c` | 40–49 | Calculates an approximate number of days until an event using a fixed 30-day month length. |
| `grade_c_date_validation.c` | 50–59 | Uses the correct number of days in each month of 2026, validates dates, calculates an accurate countdown, and displays an event status. |
| `grade_b_weekday_calculation.c` | 60–69 | Extends the accurate countdown by automatically calculating and displaying the weekday of the event using modular arithmetic. |
| `grade_a_event_navigation.c` | 70–100 | Adds support for multiple named events, urgency highlighting, full validation, event navigation, adding new events, and a repeating menu system. |

## Topics Practised

### Knowledge from Weeks 1 to 5

This task revises and combines C programming knowledge developed throughout the previous five weeks of the module, including:

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
- Mathematical calculations
- Structured problem-solving
- Debugging and testing

### Week 6 – Revision of Weeks 1–5

Week 6 focuses on consolidating the programming knowledge developed during Weeks 1 to 5 rather than introducing new C programming concepts.

The main purpose of the week is to apply previously learned techniques together when solving more integrated programming problems.

The key areas developed during Week 6 include:

- Combining multiple programming concepts in one solution
- Applying conditional logic to more complex problems
- Using loops and control flow effectively
- Improving problem-solving techniques
- Refining debugging skills
- Identifying and correcting logical errors
- Writing structured and readable code
- Improving program efficiency
- Testing different program behaviours
- Applying feedback to improve solutions
- Developing confidence when solving larger programming problems

Assessment Task 4 therefore provides an opportunity to combine previous C programming knowledge into a more complete and structured application.

## Learning Scope Note

For Grades D, C, and B, the solutions are intended to use only the programming knowledge covered so far in the module, from Week 1 through Week 6. Since Week 6 is a revision week, this means applying and combining the concepts introduced during Weeks 1 to 5.

This helps demonstrate progression through the module and ensures that each solution reflects the expected stage of study.

For Grade A, students may use more advanced C programming knowledge if they already understand it, even where those techniques have not yet been covered in future lectures or seminars. More advanced techniques may be used where they help produce a clearer, more structured, efficient, or effective solution, while still satisfying all assessment requirements.

## Assessment Requirements

To achieve a higher grade band, each solution must build upon and include the requirements of the previous grade bands.

The assessment contains four progressive C programming solutions:

1. **D Grade:** Basic approximate countdown using a fixed 30-day month length.
2. **C Grade:** Accurate date calculations using correct month lengths, date validation, and event status.
3. **B Grade:** Automatic weekday calculation using the event's position within the year and modular arithmetic.
4. **A Grade:** Multiple event tracking, urgency highlighting, event navigation, additional event creation, full validation, and a repeating menu system.

## Calendar Information

The assessment works specifically with dates in the year **2026**.

The correct number of days in each month is:

| Month | Days |
|---|---:|
| January | 31 |
| February | 28 |
| March | 31 |
| April | 30 |
| May | 31 |
| June | 30 |
| July | 31 |
| August | 31 |
| September | 30 |
| October | 31 |
| November | 30 |
| December | 31 |

The assessment also provides the fact that:

```text
1 January 2026 is Thursday
```

This information is used in the Grade B and Grade A solutions to calculate the weekday of an event.

## Event Status Rules

From Grade C onwards, the program should classify events according to the number of days remaining.

| Days Remaining | Status |
|---|---|
| 0 days | Today |
| 1–7 days | Coming soon |
| More than 7 days | Later in the year |
| Negative value | Already passed |

These status rules allow the program to provide more meaningful information than displaying the countdown alone.

## Program Features by Grade

### Grade D – Basic Countdown Using Fixed Month Length

The Grade D solution creates a basic event countdown program.

The user should enter:

- Current day
- Current month
- Event day
- Event month

For this solution, every month is treated as having exactly **30 days**.

The program should:

- Ask for the current date
- Ask for the event date
- Convert both dates into approximate day numbers
- Calculate the approximate number of days between them
- Display the number of days until the event
- Display an error if the event date occurs before the current date

Example:

```text
Enter current day: 10
Enter current month: 3
Enter event day: 25
Enter event month: 4

Approximate days until event: 45 days
```

This grade focuses on basic arithmetic, variables, user input, conditional logic, and date conversion.

### Grade C – Correct Month Length and Date Validation

The Grade C solution builds on Grade D and replaces the approximate 30-day month system with the correct calendar month lengths for 2026.

The program should:

- Complete all Grade D requirements
- Use the correct number of days for every month
- Validate the current month
- Validate the current day
- Validate the event month
- Validate the event day
- Convert each date into its accurate day number within the year
- Calculate the accurate number of days between the two dates
- Determine the event status

Months must be between:

```text
1 and 12
```

The day entered must also be valid for the selected month.

For example:

- February cannot contain day 30
- April cannot contain day 31
- January can contain day 31

The program should classify the event as:

- Today
- Coming soon
- Later in the year
- Already passed

Example:

```text
Enter current day: 10
Enter current month: 3
Enter event day: 25
Enter event month: 4

Days until event: 46 days
Status: Later in the year
```

### Grade B – Automatic Weekday Calculation

The Grade B solution builds on Grade C and automatically determines which day of the week the event occurs on.

The program uses the fact that:

```text
1 January 2026 is Thursday
```

The weekday numbering system is:

| Number | Weekday |
|---:|---|
| 1 | Monday |
| 2 | Tuesday |
| 3 | Wednesday |
| 4 | Thursday |
| 5 | Friday |
| 6 | Saturday |
| 7 | Sunday |

The program should:

- Complete all Grade C requirements
- Calculate the event's day number within 2026
- Use the known weekday of 1 January 2026
- Use modular arithmetic to determine the event weekday
- Display the event weekday
- Display the number of days remaining
- Display the event status

For example:

```text
Enter current day: 10
Enter current month: 3
Enter event day: 25
Enter event month: 4

Days until event: 46 days
Event weekday: Saturday
Status: Later in the year
```

The portfolio should also include a clear explanation of how the weekday calculation works.

The basic principle is that weekdays repeat every seven days. The event's position within the year can therefore be combined with the known weekday of 1 January and calculated using modulo 7.

### Grade A – Multiple Events, Urgency Highlighting, and Navigation

The Grade A solution builds on all previous grade requirements and develops the program into a more advanced Event Countdown Planner.

The program should allow the user to enter several events.

For each event, the program should store:

- Event name
- Event day
- Event month

The user should also enter the current date.

The program should display one event at a time and show:

- Event name
- Event date
- Number of days remaining
- Event weekday
- Event status

### Urgency Highlighting

The Grade A solution should highlight events requiring immediate attention.

If an event occurs today, display:

```text
*** EVENT IS TODAY ***
```

If an event is within seven days, display:

```text
*** URGENT EVENT ***
```

### Event Navigation

The program should contain a navigation menu:

```text
Navigation:

1. View next event
2. View previous event
3. Add another event
4. Exit
```

The program should:

- Allow the user to move to the next event
- Allow the user to move to the previous event
- Allow the user to add another event
- Allow the user to exit
- Continue running until Exit is selected
- Prevent navigation before the first event
- Prevent navigation beyond the last event

### Grade A Input Validation

The Grade A solution should validate all important user inputs.

This includes:

- Invalid days
- Invalid months
- Invalid number of events
- Invalid menu choices
- Invalid dates for the selected month

Invalid input should be handled appropriately without causing unexpected program behaviour.

## How to Compile and Run

From this folder, compile a program using GCC:

```bash
gcc grade_c_date_validation.c -o grade_c_date_validation
```

Run the compiled program:

```bash
./grade_c_date_validation
```

Replace the filename with the program you want to compile and run.

For example, to compile and run the Grade A solution:

```bash
gcc grade_a_event_navigation.c -o grade_a_event_navigation
./grade_a_event_navigation
```

## Suggested Folder Structure

```text
task-4-event-countdown-planner/
│
├── README.md
├── grade_d_basic_countdown.c
├── grade_c_date_validation.c
├── grade_b_weekday_calculation.c
└── grade_a_event_navigation.c
```

## Testing Suggestions

Each solution should be tested with different inputs to demonstrate that the program behaves correctly.

Useful test cases include:

- An event later in the same month
- An event in a later month
- An event occurring today
- An event occurring within seven days
- An event occurring more than seven days later
- An event that has already passed
- Events in 30-day months
- Events in 31-day months
- Events in February
- The first day of the year
- The last day of the year
- Invalid month below 1
- Invalid month above 12
- Day equal to zero
- Negative day
- Day beyond the valid range for a month
- February 29 in 2026
- April 31
- Valid weekday calculations
- Multiple events
- Moving to the next event
- Moving to the previous event
- Attempting to move before the first event
- Attempting to move beyond the last event
- Adding another event
- Invalid navigation menu choices
- Correct urgency highlighting
- Exiting the program correctly

For the Grade B and Grade A solutions, several known dates should be tested to confirm that the weekday calculation works correctly.

For the Grade A solution, navigation should also be tested carefully at both the first and last stored events to confirm that the user cannot move outside the available event range.

## Notes

- All programs are written in the C programming language.
- Each file is a separate runnable solution for a different assessment grade band.
- Each higher grade solution builds upon the requirements of the previous grade.
- Week 6 is a revision week and introduces no new C programming concepts.
- Grades D, C, and B are intended to demonstrate and combine the programming knowledge covered during Weeks 1 to 5 and revised during Week 6.
- Grade A may use more advanced programming techniques where the student already understands them and where they are appropriate for the solution.
- The assessment focuses particularly on loops, conditional logic, date calculations, validation, calendar formatting, and menu navigation.
- The Grade B portfolio should include an explanation of how the automatic weekday calculation works.
- The source code files should be included in the ZIP submission together with the completed assessment portfolio.
- Screenshots of both the source code and program output should be included in the Word portfolio report.
- Multiple output screenshots should be used where different inputs can produce different program behaviour.
- Testing should demonstrate both normal operation and appropriate handling of invalid input.
