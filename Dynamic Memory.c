#include <stdio.h>
#include <stdlib.h>

// Function KOMPUTE to calculate the sum of succeeding elements
void KOMPUTE(int *PointA, int *Point_B, int sizeA) {
    // We iterate one less time than the total elements in PointA
    // because we are adding pairs (i and i+1)
    for (int i = 0; i < sizeA - 1; i++) {
        *(Point_B + i) = *(PointA + i) + *(PointA + i + 1);
    }
}

int main() {
    int sizeA = 10;
    int sizeB = sizeA - 1; // Point_B will have 1 less element than PointA

    // 1. Dynamic memory allocation for the pointers
    int *PointA = (int *)malloc(sizeA * sizeof(int));
    int *Point_B = (int *)malloc(sizeB * sizeof(int));

    // Check if memory allocation was successful
    if (PointA == NULL || Point_B == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 2. Input 10 numbers into pointer PointA
    printf("Input 10 numbers for PointA (separated by spaces or newlines):\n");
    for (int i = 0; i < sizeA; i++) {
        scanf("%d", (PointA + i));
    }

    // 3. Call function KOMPUTE
    KOMPUTE(PointA, Point_B, sizeA);

    // 4. Print both pointer PointA and Point_B
    printf("\n--- Results ---\n");
    
    printf("Point_A:\n");
    for (int i = 0; i < sizeA; i++) {
        printf("%d\n", *(PointA + i));
    }
    // Note: Point_B has one less element than PointA, so we print sizeB elements
    printf("\nPoint_B (Sum of succeeding elements):\n");
    for (int i = 0; i < sizeB; i++) {
        printf("%d\n", *(Point_B + i));
    }

    // Free the dynamically allocated memory
    free(PointA);
    free(Point_B);

    return 0;
}