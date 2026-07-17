# Assignment-09 : Dynamic Array Operations

## Objective

To implement insertion, deletion, updation, displaying and searching operations using dynamic arrays.

---

## Problem Statement

The program performs:

- Insertion
- Deletion
- Updation
- Displaying Elements
- Linear Search
- Binary Search
- Dynamic Memory Allocation

---

## Algorithm

1. Dynamically allocate memory using realloc().
2. Insert elements whenever required.
3. Perform deletion and updation operations.
4. Search elements using:
   - Linear Search
   - Binary Search
5. Sort the array before performing Binary Search.
6. Release memory using free().

---

## Time Complexity

| Operation     | Complexity |
| ------------- | ---------- |
| Insertion     | O(n)       |
| Deletion      | O(n)       |
| Display       | O(n)       |
| Linear Search | O(n)       |
| Sorting       | O(n²)      |
| Binary Search | O(log n)   |
| Update        | O(n)       |

---

## Space Complexity

O(n)

---

## Sample Input

1
50

1
20

1
90

4

5
90

6
20

---

## Sample Output

Element Inserted Successfully.

Array Elements:
50 20 90

Element Found at Index 2

Element Found at Index 0

Program Terminated Successfully.

---

## Learning Outcome

- Dynamic Memory Allocation
- Searching Algorithms
- Sorting Algorithms
- Arrays
- Binary Search
- Time Complexity Analysis
