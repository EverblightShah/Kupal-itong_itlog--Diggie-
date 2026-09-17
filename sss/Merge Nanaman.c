#include <stdio.h>
#include <stdlib.h>

int exists(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
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

    return index;
}

void bubbleSort(int arr[], int n, char order) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            int shouldSwap = 0;

            if (order == 'A' || order == 'a') {
                if (arr[j] > arr[j + 1]) shouldSwap = 1;
            } else if (order == 'D' || order == 'd') {
                if (arr[j] < arr[j + 1]) shouldSwap = 1;
            }

            if (shouldSwap) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n, char order) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        if (order == 'A' || order == 'a') {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
        } else if (order == 'D' || order == 'd') {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }

        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, char order) {
    for (int i = 0; i < n - 1; i++) {
        int selectedIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (order == 'A' || order == 'a') {
                if (arr[j] < arr[selectedIndex]) {
                    selectedIndex = j;
                }
            } else if (order == 'D' || order == 'd') {
                if (arr[j] > arr[selectedIndex]) {
                    selectedIndex = j;
                }
            }
        }

        if (selectedIndex != i) {
            int temp = arr[i];
            arr[i] = arr[selectedIndex];
            arr[selectedIndex] = temp;
        }
    }
}

int main(void) {
    char runAgain = 'y';

    while (runAgain == 'y' || runAgain == 'Y') {
        int arr1[5], arr2[5], result[100], originalResult[100];
        int choice;

        printf("=================================\n");
        printf("             MENU\n");
        printf("=================================\n");
        printf("1. Array Merge\n");
        printf("2. Sorting Techniques\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            char confirmExit;
            printf("\nAre you sure you want to exit? (Y/N): ");
            scanf(" %c", &confirmExit);

            if (confirmExit == 'Y' || confirmExit == 'y') {
                break;
            } else {
                continue;
            }
        }

        printf("\nPlease enter your 5 integers for the first array:\n");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &arr1[i]);
        }

        printf("\nPlease enter your 5 integers for the second array:\n");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &arr2[i]);
        }

        int size = mergeUnique(arr1, 5, arr2, 5, result);

        for (int i = 0; i < size; i++) {
            originalResult[i] = result[i];
        }

        if (choice == 1) {
            printf("\nHere is the merged array with unique values: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", result[i]);
            }
        }
        else if (choice == 2) {
            printf("\nHere is the merged array with unique values: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", result[i]);
            }

            char technique;
            printf("\n\nChoose sorting technique:\n");
            printf("A - Bubble Sort\n");
            printf("B - Insertion Sort\n");
            printf("C - Selection Sort\n");
            printf("Choice: ");
            scanf(" %c", &technique);

            char order;
            printf("\n\nArrange the merged array:\n");
            printf("A - Ascending\n");
            printf("D - Descending\n");
            printf("Choice: ");
            scanf(" %c", &order);

            if ((technique == 'A' || technique == 'a' || technique == 'B' || technique == 'b' || technique == 'C' || technique == 'c') &&
                (order == 'A' || order == 'a' || order == 'D' || order == 'd')) {

                if (technique == 'A' || technique == 'a') {
                    bubbleSort(result, size, order);
                } else if (technique == 'B' || technique == 'b') {
                    insertionSort(result, size, order);
                } else if (technique == 'c' || technique == 'C') {
                    selectionSort(result, size, order);
                }

                if (order == 'A' || order == 'a')
                    printf("\nAscending Order: ");
                else
                    printf("\nDescending Order: ");

                for (int i = 0; i < size; i++) {
                    printf("%d ", result[i]);
                }

                char other;
                printf("\n\nWould you like to see the other arrangement? (Y/N): ");
                scanf(" %c", &other);

                if (other == 'y' || other == 'Y') {
                    for (int i = 0; i < size; i++) {
                        result[i] = originalResult[i];
                    }

                    if (technique == 'A' || technique == 'a') {
                        if (order == 'A' || order == 'a')
                            bubbleSort(result, size, 'D');
                        else
                            bubbleSort(result, size, 'A');
                    } else if (technique == 'B' || technique == 'b') {
                        if (order == 'A' || order == 'a')
                            insertionSort(result, size, 'D');
                        else
                            insertionSort(result, size, 'A');
                    } else if (technique == 'C' || technique == 'c') {
                        if (order == 'A' || order == 'a')
                            selectionSort(result, size, 'D');
                        else
                            selectionSort(result, size, 'A');
                    }

                    if (order == 'A' || order == 'a')
                        printf("\nDescending Order: ");
                    else
                        printf("\nAscending Order: ");

                    for (int i = 0; i < size; i++) {
                        printf("%d ", result[i]);
                    }
                }
            } else {
                printf("\nInvalid choice. Showing only merged array.");
            }
        }
        else {
            printf("\nInvalid menu choice.");
        }

        printf("\n-------------------------------------------------");
        printf("\n\nDo you want to run the program again? (Y/N): ");
        scanf(" %c", &runAgain);

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    printf("\n============= THE END =============\n");
    printf("+--------------------------------+\n");
    printf("| Thank you for trying our code! |\n");
    printf("+--------------------------------+\n");

    return 0;
}
