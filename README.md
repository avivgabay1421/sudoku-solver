Sudoku Solver in C
This project implements a Sudoku solver in C using dynamic memory allocation and a recursive backtracking algorithm.

Features
Supports NxN Sudoku boards (e.g., 4x4, 9x9)
Efficient matrix representation using dynamic memory allocation
Validation of rows, columns, and sub-grids
Full solution using backtracking
Algorithm
The solver is based on a backtracking approach:

Locate an empty cell in the grid
Attempt to place a valid value (1 to N)
Recursively continue solving the board
Backtrack if a dead-end is reached
Technologies
C
Dynamic Memory Allocation
Recursion
How to Run
Compile: gcc sudoku_solver.c -o sudoku

Run: ./sudoku

Example Input
4 1 0 2 3 0 2 4 0 0 1 0 0 4 0 1 0

Output
The solved Sudoku board is printed to the console.

Author
aviv gabay
