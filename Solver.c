#include <stdio.h>

// Function prototypes
int solveSudoku(int, int);
void printSudoku(void);
int sameColumn(int, int, int);
int sameSquare(int, int, int);
int sameRow(int, int, int);

// 2D array holds Sudoku puzzle moving left to right from top to bottom
int sudoku[9][9] = {0, 2, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 3, 0, 0, 4, 1, 0, 0, 0, 0, 0, 6, 0, 0, 0, 8, 0, 0, 2, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 1, 0, 0, 9, 0, 0, 0, 0, 0, 4, 8, 0, 0, 0, 0, 0, 8, 4, 2, 0, 0, 5, 1, 0, 0, 0, 8, 3, 0, 0, 4, 7, 0, 5, 0, 0, 0, 0};

int main()
{
    int x = 0; // initializing x and y values
    int y = 0;

    printf("\t# # # # # # # # # \n");
    printf("\t  Initial Puzzle\n");
    printf("\t# # # # # # # # # \n");

    printSudoku(); // Outputting the initial puzzle

    solveSudoku(x, y); // Solving the Puzzle

    printf("\t# # # # # # # # # \n");
    printf("\t  Final Puzzle\n");
    printf("\t# # # # # # # # # \n");

    printSudoku(); // Outputting the final puzzle

    return 0;
}

// Function to print the Sudoku grid
void printSudoku()
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            printf("-----------------------------\n");
        }
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0)
            {
                printf("|");
            }

            printf(" %d ", sudoku[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("-----------------------------\n\n\n");
}

// Recursive function to solve the Sudoku puzzle
int solveSudoku(int x, int y)
{
    int num = 1;
    int tx = 0;
    int ty = 0;

    // If the current cell is not empty, move to the next cell
    if (sudoku[x][y] != 0)
    {
        if (x == 8 & y == 8)
        {
            return 1;
        }
        if (x < 8)
        {
            x++;
        }
        else
        {
            x = 0;
            y++;
        }

        if (solveSudoku(x, y))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // If the current cell is empty, try filling it with a number
    if (sudoku[x][y] == 0)
    {
        while (num < 10)
        {
            // Check if the number is valid in the current cell
            if (!sameSquare(x, y, num) && !sameRow(x, y, num) && !sameColumn(x, y, num))
            {
                sudoku[x][y] = num;
                if (x == 8 && y == 8)
                {
                    return 1;
                }

                if (x < 8)
                {
                    tx = x + 1;
                }
                else
                {
                    tx = 0;
                    ty = y + 1;
                }

                if (solveSudoku(tx, ty))
                {
                    return 1;
                }
            }
            num++;
        }

        // If no number can be placed in the current cell, reset it and backtrack
        sudoku[x][y] = 0;
        return 0;
    }
}

// Function to check if a number is in the same column
int sameColumn(int x, int y, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[x][i] == num)
        {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is in the same 3x3 square
int sameSquare(int x, int y, int num)
{
    // Adjust the x and y coordinates to the top-left cell of the 3x3 square
    if (x < 3)
    {
        x = 0;
    }
    else if (x < 6)
    {
        x = 3;
    }
    else
    {
        x = 6;
    }

    if (y < 3)
    {
        y = 0;
    }
    else if (y < 6)
    {
        y = 3;
    }
    else
    {
        y = 6;
    }

    // Check the 3x3 square for the same number
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (sudoku[i][j] == num)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if a number is in the same row
int sameRow(int x, int y, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][y] == num)
        {
            return 1;
        }
    }
    return 0;
}
