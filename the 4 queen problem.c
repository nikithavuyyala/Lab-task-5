#include <stdio.h>
#include <stdbool.h>

#define N 4

int board[N][N];

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int row, int col) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queens problem
bool solveNQueens(int col) {
	int i;
    if (col >= N)
        return true;

    for (i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solveNQueens(col + 1))
                return true;

            board[i][col] = 0; // Backtrack
        }
    }
    return false;
}

// Function to print the solution
void printSolution() {
	int i,j;
    for (i = 0; i < N; i++) {
        for ( j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int main() {
	int i,j;
    for ( i = 0; i < N; i++)
        for ( j = 0; j < N; j++)
            board[i][j] = 0;

    if (solveNQueens(0) == false) {
        printf("Solution does not exist");
        return 0;
    }

    printSolution();
    return 0;
}

