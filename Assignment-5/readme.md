# Assignment-05 : Dynamic Array Management

## Objective

To understand Dynamic Memory Allocation using malloc() and free() for storing and processing student marks.

---

## Problem Statement

Create a program that:

- Dynamically allocates memory.
- Stores student marks.
- Displays marks.
- Calculates Highest Marks.
- Calculates Lowest Marks.
- Calculates Total Marks.
- Calculates Average Marks.
- Releases memory using free().

---

## Algorithm

1. Accept the number of students.
2. Allocate memory dynamically using malloc().
3. Store student marks.
4. Display menu options.
5. Perform the selected operation.
6. Release the allocated memory using free() before terminating the program.

---

## Time Complexity

| Operation              | Complexity |
| ---------------------- | ---------- |
| Input                  | O(n)       |
| Display                | O(n)       |
| Statistics Calculation | O(n)       |
| Memory Allocation      | O(1)       |
| Memory Deallocation    | O(1)       |

---

## Space Complexity

O(n)

---

## Sample Input

5

78
89
56
90
95

---

## Sample Output

Student Marks:

78
89
56
90
95

Highest Marks : 95

Lowest Marks : 56

Total Marks : 408

Average Marks : 81.60

Memory Released Successfully.

---

## Learning Outcome

- Dynamic Memory Allocation
- malloc()
- free()
- Arrays and Pointers
- Functions
- Memory Management in C
