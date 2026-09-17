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
    char continueProgram = 'y';
    
    while (continueProgram == 'y' || continueProgram == 'Y') {
        int arr1[5], arr2[5], result[100];
        char answer;
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
        printf("\nHere is the merged array with unique values: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", result[i]);
        }
        printf("How do you want to sort your merged array?\n");
        printf("\nType '1' for bubble sort, '2' for selection sort, '3' for insertion sort: ");
        scanf(" %c", &answer);

        switch (answer) {
            case '1':
            printf("\nYou have chosen bubble sort.\n");
            printf("How do you want to sort the merged array? Type 'A' for ascending order, 'D' for descending order: ");
            scanf(" %c", &answer);
                // Bubble sort
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (result[j] > result[j + 1]) {
                            int temp = result[j];
                            result[j] = result[j + 1];
                            result[j + 1] = temp;
                        }
                    }
                }
                printf("\nHere is the merged array sorted in ascending order using bubble sort: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", result[i]);
                }
                break;
            case '2':
                // Selection sort
                int position;
                for (int i = 0; i < (size - 1); i++) {
                    position = i;
                    for (int j = i + 1; j < size ; j++) {
                        if (result[position] > result[j]) {
                            position = j;
                        }
                    }
                    // Swap the elements
                    if (position != i) {
                        int temp = result[i];
                        result[i] = result[position];
                        result[position] = temp;
                    }
                }
                printf("\nHere is the merged array sorted in ascending order using selection sort: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", result[i]);
                }
                break;
            case '3':
                // Insertion sort
                for (int i = 1; i < size; i++) {
                    int key = result[i];
                    int j = i - 1;
                    while (j >= 0 && result[j] > key) {
                        result[j + 1] = result[j];
                        j--;
                    }
                    result[j + 1] = key;
                }
                printf("\nHere is the merged array sorted in ascending order using insertion sort: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", result[i]);
                }
                break;
            default:
                printf("Invalid input. Please enter '1', '2', or '3'.\n");
        }
        printf("\nHow do you want to sort the merged array? Type 'A' for ascending order, 'D' for descending order: ");
        scanf(" %c", &answer);
        // Sorting the merged array based on user's choice
        if (answer == 'A' || answer == 'a') {
            // Sort in ascending order using selection sort
            int position;
            for (int i = 0; i < (size - 1); i++) {
                position = i;
                for (int j = i + 1; j < size ; j++) {
                    if (result[position] > result[j]) {
                        position = j;
                    }
                }
                // Swap the elements
                if (position != i) {
                    int temp = result[i];
                    result[i] = result[position];
                    result[position] = temp;
                }
            }
            printf("\nHere is the merged array sorted in ascending order: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", result[i]);
            }
        } else if (answer == 'D' || answer == 'd') {
            // Sort in descending order using selection sort
            int position;
            for (int i = 0; i < (size - 1); i++) {
                position = i;
                for (int j = i + 1; j < size ; j++) {
                    if (result[position] < result[j]) {
                        position = j;
                    }
                }
                // Swap the elements
                if (position != i) {
                    int temp = result[i];
                    result[i] = result[position];
                    result[position] = temp;
                }
            }
            printf("\nHere is the merged array sorted in descending order: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", result[i]);
            }
        } else {
            printf("Invalid input. Please enter 'A' for ascending order or 'D' for descending order.\n");
        }
        printf("\n\nDo you want to run the program again? (y/n): ");
        scanf("%c", &continueProgram);

        if (continueProgram == 'y' || continueProgram == 'Y') {
            system("cls");
        } 
        else {
            printf("\n============= THE END =============\n");
            printf("+--------------------------------+\n");
            printf("| Thank you for trying our code! |\n");
            printf("+--------------------------------+\n");
        }
    }
    printf("\n");
    return 0;
}