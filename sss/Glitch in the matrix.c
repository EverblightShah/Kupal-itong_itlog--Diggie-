#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int arrA[3];
    int arrB[3][3];
    int arrC[3];
    
    printf("\n================ ARRAY A INPUT ================\n");

    for (int i = 0; i < 3; i++) {
        printf("Enter value for your array A[%d]: ", i);
        scanf("%d", &arrA[i]);
    }

    printf("\n=========== ARRAY A (RECAP) ===========\n");
    printf("+-------+-------+-------+\n");
    printf("|  A[0] |  A[1] |  A[2] |\n");
    printf("+-------+-------+-------+\n");
    printf("| %5d | %5d | %5d |\n", arrA[0], arrA[1], arrA[2]);
    printf("+-------+-------+-------+\n");


    printf("\n================ ARRAY B INPUT ================\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter value for your array B[%d][%d]: ", i, j);
            scanf("%d", &arrB[i][j]);
        }
    }

    printf("\n================ ARRAY B (RECAP) ================\n");
    printf("+-------+-------+-------+-------+\n");
    printf("|       |   0   |   1   |   2   |\n");
    printf("+-------+-------+-------+-------+\n");

    for (int i = 0; i < 3; i++) {
        printf("| B[%d]  | %5d | %5d | %5d |\n", i,  arrB[i][0], arrB[i][1], arrB[i][2]);
        printf("+-------+-------+-------+-------+\n");
    }


    printf("\nMultiplying ARRAY A and ARRAY B to get ARRAY C...\n");

    for (int i = 0; i < 3; i++) {
        arrC[i] = 0;
        for (int j = 0; j < 3; j++) {
            arrC[i] += arrA[j] * arrB[i][j];
        }
    }

    printf("\n=========== ARRAY C RESULT ===========\n");
    printf("+-------+-------+-------+\n");
    printf("|  C[0] |  C[1] |  C[2] |\n");
    printf("+-------+-------+-------+\n");
    printf("| %5d | %5d | %5d |\n", arrC[0], arrC[1], arrC[2]);
    printf("+-------+-------+-------+\n");


    do {
        char answer;
        printf("\nDo you want to run the program again? (y/n): ");
        scanf(" %c", &answer);

        if (answer == 'y' || answer == 'Y') {
            system("cls"); // Clear the console for better readability
            main(); 
        } 
        else {
            printf("\n============= THE END =============\n");
            printf("+--------------------------------+\n");
            printf("| Thank you for trying our code! |\n");
            printf("+--------------------------------+\n");
            break;
        }

    } while (1);

    printf("\n");
    return 0;
}

// Problem 2, pangalan po ito