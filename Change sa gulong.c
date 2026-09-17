#include <stdio.h>

int main() {
    // Defining a 5x9 array based on the [5][9] note on the board
    char canvas[5][9];
    int rows = 5;
    int cols = 9;

    // 1. Initialize the array with spaces
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            canvas[i][j] = ' ';
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j >= (rows - 1 - i) && j <= (rows - 1 + i) && (i + j) % 2 == (rows - 1) % 2) {
                canvas[i][j] = '*';
            }
        }
    }
    // 3. Print the Multi-dimensional Array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n"); // New line after each row
    }

    return 0;
}