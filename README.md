# Assignment 03 - Arrays & Algorithm Analysis

**Name:** Madah Sulam Cahya </br>
**Student ID (NIU):** 538771 </br>

## Description of Solutions
* **`problem2.cpp`**: Contains the procedural implementation of a resizable dynamic array (`DynArray`). It features manual memory management on the heap, a dynamic doubling resizing strategy for `pushBack` operations, and $O(n)$ shifting logic for `insertAt` and `removeAt`.
* **`problem3.cpp`**: Implements and tests `linearSearch` and an iterative `binarySearch`. It includes a custom sorted array generator and demonstrates the searches side-by-side to verify matching indices and to handle missing targets appropriately.
* **Written Analysis (PDF)**: Contains the exact operation counting, Big-O derivations for Problem 1, the complexity comparison table for Problem 3B, and the amortized analysis and growth factor proofs for Problem 4.

## Compilation Commands
Run the following commands in your terminal to compile the source files using the standard C++17 compiler flags:

```bash
g++ -std=c++17 -Wall -Wextra problem2.cpp -o problem2
g++ -std=c++17 -Wall -Wextra problem3.cpp -o problem3
