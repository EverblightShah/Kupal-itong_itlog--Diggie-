#include <stdio.h>
#include <stdlib.h>

int exists(int arr  [], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1; // Value exists in the array
        }
    }
    return 0; // Value does not exist in the array
}
int mergeUnique(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int index = 0;
    for (int i = 0; i < size1; i++) {
        if (!exists(result, index, arr1[i])) {
            result[index++] = arr1[i];
        }
    }
    for (int j = 0; j < size2; j++) {
        if (!exists(result, index, arr2[j])) {
            result[index++] = arr2[j];
        }
    }
    return index; // Return the size of the merged array
}
int main(void){
    int arr1[5], arr2[5], result[100];
    printf("\nPlease enter your 5 integers for the first array: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("\n");   
    printf("Please enter 5 integers for the second array: ");          
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr2[i]);

    }   
    printf("\n");
    exists(arr1, 5, 3);
    int size = mergeUnique(arr1, 5, arr2, 5, result);
    printf("Here is the merged array with unique values: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    
    do {
        char answer;
        printf("\n\nDo you want to run the program again? (y/n): ");
        scanf(" %c", &answer);

        if (answer == 'y' || answer == 'Y') {
            system("cls");
            main(); 
        } 
        else {
            printf("\n============= THE END =============\n");
            printf("+--------------------------------+\n");
            printf("| Thank you for trying our code! |\n");
            printf("+--------------------------------+\n");
            break;
        }

    } while (0);
    printf("\n");
    return 0;
}