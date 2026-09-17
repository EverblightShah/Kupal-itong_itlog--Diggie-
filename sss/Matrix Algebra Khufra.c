#include <stdio.h>
int main(void){
    int arrA[3];
    int arrB[3][3];
    int arrC[3];

    for (int i = 0; i < 3; i++) {
        printf("Enter value for your array A: ");
        scanf("%d", &arrA[i]);
    }
    printf("\nTo recap, here are the values you entered for array A: \n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", arrA[i]);
    }
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter value for your array B: ");
            scanf("%d", &arrB[i][j]);
        }
    }
    printf("\nTo recap, here are the values you entered for array B:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arrB[i][j]);
        }
        printf("\n");
    }
    printf("\nNow, we will perform the multiplication of array A and array B to get array C.\n");
    for (int i = 0; i < 3; i++) {
        arrC[i] = 0;
        for (int j = 0; j < 3; j++) {
            arrC[i] += arrA[j] * arrB[i][j];
        }
    }
    printf("\nHere is the results for array C: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", arrC[i]);
    }
    do {
        char answer;
        printf("\nDo you want to run the program again? (y/n): ");
        scanf(" %c", &answer);
        if (answer == 'y') {
            main();
        } else if (answer == 'n') {
            break;
        }
    } while(1);
    printf("\n");
    return 0;
}