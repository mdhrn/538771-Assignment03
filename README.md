# Assignment 03 - Arrays & Algorithm Analysis

**Name:** Madah Sulam Cahya </br>
**Student ID:** 24/538771/TK/59750 </br>

## Description of Solutions
* **`problem2.cpp`**: Contains the procedural implementation of a resizable dynamic array (`DynArray`). It features manual memory management on the heap, a dynamic doubling resizing strategy for `pushBack` operations, and $O(n)$ shifting logic for `insertAt` and `removeAt`.
* **`problem3.cpp`**: Implements and tests `linearSearch` and an iterative `binarySearch`. It includes a custom sorted array generator and demonstrates the searches side-by-side to verify matching indices and to handle missing targets appropriately.
* **Written Analysis (PDF)**: Contains the exact operation counting, Big-O derivations for Problem 1, the complexity comparison table for Problem 3B, and the amortized analysis and growth factor proofs for Problem 4.


## Time Spent
~ 12 hours on written assignment </br>
~ 1.5 hours on code assignment </br>

## Compilation Commands
Run the following commands in your terminal to compile the source files using the standard C++17 compiler flags:


```bash
g++ -std=c++17 -Wall -Wextra problem2.cpp -o problem2
g++ -std=c++17 -Wall -Wextra problem3.cpp -o problem3

```

## Issues Encountered
I had some difficulties while completing the written assignment, mainly in deriving the mathematical breakdown of time complexity and exact operation counting. These are some of the more specific issues i dealt with :
- Compilation Error Due to Environment Limitations : I encountered linker errors (cannot find -lasan) when trying to run the Address Sanitizer (-fsanitize=address) on Windows MinGW. I had to verify my memory management logic and utilize a Linux-based environment to properly run the leak case, in this case i use online compiler that use Linux-based environment and further clarify it by running the program natively on Ubuntu.

- Big-O Formal Proofing : In Big-O notation section for Problem 1, i tried to provide more proof of the upper bounds by finding the constant multiplier

- The Standard Cost Model: Realizing that simple syntax like i++ actually costs 2 operations under the hood (1 arithmetic + 1 assignment) rather than just being a single step.


