#include <stdio.h>
#include <stdlib.h>

// Function to compute sums
void KOMPUTE(int *PointA, int *PointB, int size) {
    for (int i = 0; i < size - 1; i++) {
        PointB[i] = PointA[i] + PointA[i + 1];
    }
}
int main() {
    int size = 10;
    int choice;

    do {
        int *PointA = (int *)malloc(size * sizeof(int));
        int *PointB = (int *)malloc((size - 1) * sizeof(int));

        if (PointA == NULL || PointB == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("\n=====================================\n");
        printf("      POINTER PAIR SUM PROGRAM       \n");
        printf("=====================================\n");

        // Input with validation
        printf("\nPlease enter your 10 integers or numbers:\n");
        for (int i = 0; i < size; i++) {
            while (1) {
                printf("PointA[%d] = ", i);

                if (scanf("%d", &PointA[i]) != 1) {
                    printf("Invalid input! Please enter an integer.\n");

                    // Clear invalid input from buffer
                    while (getchar() != '\n');
                } else {
                    break;
                }
            }
        }

        // Compute results
        KOMPUTE(PointA, PointB, size);

        // Display PointA
        printf("\nPointA Values:\n");
        for (int i = 0; i < size; i++) {
            printf("[%d]", PointA[i]);
            if (i < size - 1) printf(" -> ");
        }

        // Display PointB
        printf("\n\nPointB Values (Sum of Consecutive Elements):\n");
        for (int i = 0; i < size - 1; i++) {
            printf("[%d]", PointB[i]);
            if (i < size - 2) printf(" -> ");
        }

        // Detailed computation
        printf("\n\nDetailed Computation:\n");
        for (int i = 0; i < size - 1; i++) {
            printf("PointB[%d] = %d + %d = %d\n",
                   i, PointA[i], PointA[i + 1], PointB[i]);
        }

        // Free memory
        free(PointA);
        free(PointB);

        // Repeat option
        printf("\n=====================================\n");
        printf("Do you want to try again?\n");
        printf("1 = Yes | 0 = No\n");
        printf("Enter choice: ");

        while (scanf("%d", &choice) != 1 || (choice != 0 && choice != 1)) {
            printf("Invalid choice! Enter 1 (Yes) or 0 (No): ");
            while (getchar() != '\n');
        }

    } while (choice == 1);

    printf("\nThank you for using the program! Have a great day!\n");

    return 0;
}