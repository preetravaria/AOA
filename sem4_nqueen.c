#include <stdio.h>
#define N 8

int board[N][N]; // Chessboard represented by a 2D array

// Function to check if placing a queen at board[row][col] is safe
int isSafe(int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;
            

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (i = row, j = col; j >= 0 && i >=0; i++, j--)
        if (board[i][j])
            return 0;

    return 1; // If no conflicts, it's safe to place a queen
}

// Recursive function to solve the N Queens problem
int solveNQueens(int col)
{
    // Base case: If all queens are placed, return true
    if (col >= N)
        return 1;

    // Try placing queen in each row of this column
    for (int i = 0; i < N; i++)
    {
        // Check if queen can be placed on board[i][col]
        if (isSafe(i, col))
        {
            board[i][col] = 1;

            // Recur to place rest of the queens/
            if (solveNQueens(col + 1))
                return 1;

            board[i][col] = 0;
        }
    }

    // If queen cannot be placed in any row of this column, return false
    return 0;
}

// Function to print the solution
void printSolution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int main()
{
    // Initialize all cells of the board to 0 (no queen is placed initially)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

 
    solveNQueens(0);
    printSolution();
    return 0;
}
