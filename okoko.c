#include <stdio.h>

int main() {
    int rows[5][9]; // Initialize a 5x9 array with zeros
    for (int i = 1; i <= 5; i++) {
        for (int space = 1; space <= 5 - i + 1; space++) {
            printf("  "); // Print spaces
        }
        for (int k = 0; k < i; k++) {
            printf(" * "); // Print asterisks
        }
        printf("\n"); // Move to the next line after each row
    }
}