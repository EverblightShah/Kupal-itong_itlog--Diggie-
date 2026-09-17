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
    printf("\nHow do you want to sort your merged array?\n");
    printf("\nType '1' for bubble sort, '2' for selection sort, '3' for insertion sort: ");
    char num;
    scanf(" %c", &num);  
    switch (num) {
            case '1':
            printf("\nYou have chosen bubble sort.\n");
            printf("To recap, here is your merged array with unique values: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", result[i]);
            }
            printf("\n");
            printf("\nHow do you want to sort the merged array? Type 'A' for ascending order, 'D' for descending order: ");
            scanf(" %c", &num);
                // Bubble sort
                if (num == 'A' || num == 'a') {
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
                } else if (num == 'D' || num == 'd') {
                    for (int i = 0; i < size - 1; i++) {
                        for (int j = 0; j < size - i - 1; j++) {
                            if (result[j] < result[j + 1]) {
                                int temp = result[j];
                                result[j] = result[j + 1];
                                result[j + 1] = temp;
                            }
                        }
                    }
                    printf("\nHere is the merged array sorted in descending order using bubble sort: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", result[i]);
                    }
                } else {
                    printf("Invalid input. Please enter 'A' or 'D'.\n");
                    scanf("%c", &num);
                }
                break;
            case '2':
                // Selection sort
                printf("\nYou have chosen selection sort.\n");
                printf("\nTo recap, here is your merged array with unique values: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", result[i]);
                }   
                printf("\n");
                printf("\nHow do you want to sort the merged array? Type 'A' for ascending order, 'D' for descending order: ");
                scanf(" %c", &num);
                int position;
                if (num == 'A' || num == 'a') {
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
                printf("\n");
                break;
                } else if (num == 'D' || num == 'd') {
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
                printf("\nHere is the merged array sorted in descending order using selection sort: ");
                for (int i = 0; i < size; i++) {    
                    printf("%d ", result[i]);
                }
                printf("\n");
            } else {
                    printf("Invalid input. Please enter 'A' or 'D'.\n");
                    scanf("%c", &num);
                }   
                break;
            case '3':
                printf("\nYou have chosen insertion sort.\n");
                printf("\nTo recap, here is your merged array with unique values: \n");
                for (int i = 0; i < size; i++) {
                    printf("%d ", result[i]);
                }
                printf("\n");
                printf("\nHow do you want to sort the merged array? Type 'A' for ascending order, 'D' for descending order: ");
                scanf(" %c", &num);
                if (num == 'A' || num == 'a') {
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
                } else if (num == 'D' || num == 'd') {
                    for (int i = 1; i < size; i++) {
                    int key = result[i];
                    int j = i - 1;
                    while (j >= 0 && result[j] < key) {
                        result[j + 1] = result[j];
                        j--;
                    }
                    result[j + 1] = key;
                }
                printf("\nHere is the merged array sorted in descending order using insertion sort: ");
                for (int i = 0; i < size; i++) {    
                    printf("%d ", result[i]);
                }
                break;
                } else {
                    printf("Invalid input. Please enter 'A' or 'D'.\n");
                    scanf("%c", &num);
                }
            default:
            printf("Invalid input. Please enter '1', '2', or '3'.\n");
            scanf(" %c", &num);
        }
    do {
        char answer;
        printf("\n\nDo you want to run the program again? (y/n): ");
        scanf(" %c", &answer);

        if (answer == 'y' || answer == 'Y') {
            system("cls");
            main(); 
        } else {
            printf("\n============= THE END =============\n");
            printf("+--------------------------------+\n");
            printf("| Thank you for trying our code! |\n");
            printf("+--------------------------------+\n");
        }
    } while (0);
    
    printf("\n");
    return 0;
}