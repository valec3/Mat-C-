#include <iostream>

using namespace std;

bool isSafe(int grid[4][4], int row, int col, int num) {
    // Check if the number is already present in the row
    for (int i = 0; i < 4; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // Check if the number is already present in the column
    for (int i = 0; i < 4; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    // Check if the number is already present in the 2x2 subgrid
    int subGridRowStart = (row / 2) * 2;
    int subGridColStart = (col / 2) * 2;

    for (int i = subGridRowStart; i < subGridRowStart + 2; i++) {
        for (int j = subGridColStart; j < subGridColStart + 2; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveQuadroku(int grid[4][4]) {
    // Check if there are any empty cells left
    bool isAnyEmptyCell = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                isAnyEmptyCell = true;
                break;
            }
        }
    }

    if (!isAnyEmptyCell) {
        // The puzzle has been solved
        return true;
    }

    // Try filling the empty cell with a number from 1 to 4
    for (int num = 1; num <= 4; num++) {
        // Find an empty cell
        int row = -1;
        int col = -1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (grid[i][j] == 0) {
                    row = i;
                    col = j;
                    break;
                }
            }
        }

        // Check if it is safe to place the number in the empty cell
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively solve the puzzle
            if (solveQuadroku(grid)) {
                return true;
            }

            // Backtrack if the recursive call failed
            grid[row][col] = 0;
        }
    }

    // No valid number could be placed in the empty cell, so the puzzle cannot be solved
    return false;
}

int main() {
    int grid[4][4] = {
        {1, 3, 3, 0},
        {4, 2, 0, 0},
        {0, 0, 4, 1},
        {0, 0, 3, 2}
    };
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin>>grid[i][j];
        }
    }
    
    if (solveQuadroku(grid)) {
        // The puzzle has been solved, print the solution
        cout<<"Yes"<<endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}
