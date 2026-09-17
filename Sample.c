#include <stdio.h>

int main() {
    int rows = 5;
    int cols = 13; // Increased width for 2-space gaps
    char canvas[5][13];

    // 1. Initialize the 2D array with spaces
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            canvas[i][j] = ' ';
        }
    }

    // 2. Logic to place '*' with 2 spaces in between
    // The center of 13 columns is index 6
    int mid = cols / 2;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Check if 'j' is within the triangle bounds 
            // and exactly 3 units apart (1 star + 2 spaces)
            if (j >= (mid - i * 3 / 2) && j <= (mid + i * 3 / 2)) {
                if ((j - mid + i * 3) % 3 == 0) {
                    canvas[i][j] = '*';
                }
            }
        }
    }

    // 3. Print the Result
    printf("Pattern with 2-space gaps:\n\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }

    return 0;
}