#include <stdio.h>

int main(void){
    int num, cube_root, sum_cube_root = 0, answer;

    printf("Enter a number: ");
    scanf("%d", &num);
    for (int i = 1; i * i * i <= num; i++) {
        cube_root = i * i * i;
        sum_cube_root += cube_root;
    }
    printf("The sum of cube roots is: %d\n", sum_cube_root);
    if (sum_cube_root == 100) {
        printf("The sum of cube roots is equal to 100\n");
    } else {
        printf("The sum of cube roots is not equal to 100\n");
    }
    printf("Do you want to continue (1- Yes/0- No): ");
    scanf("%d", &answer);
    /* If you want to actually repeat the process, wrap the main logic in a loop.
       For now, exit when the user chooses not to continue or immediately exit on 1. */
    while (answer == 1) {
        return 1; // Indicate to the caller to rerun the program
    }
    return 0;
}