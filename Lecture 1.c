#include <stdio.h>

int main(void){
    int BSCS[3][3], sum_rows[3] = {0}, sum_col[3] = {0};
    printf("Enter the elements of BSCS, numbers only:\n");
    for(int rows = 0; rows < 3; rows++) {
        for(int col = 0; col < 3; col++){
            scanf("%d", &BSCS[rows][col]);
        }
    }
    // Sum of rows
    for(int rows = 0; rows < 3; rows++) {
        for(int col = 0; col < 3; col++){
            sum_rows[rows] += BSCS[rows][col];
        }
    }
    // Print sum of rows
    for (int rows = 0; rows < 3; rows++) {
        printf("%d\t", sum_rows[rows]);
    }
    printf("\n");

    // Sum of columns
    for(int rows = 0; rows < 3; rows++) {
        for(int col = 0; col < 3; col++){
            sum_col[col] += BSCS[col][rows];
        }
    }
    // Print sum of columns
    for (int col = 0; col < 3; col++) {
        printf("%d\t", sum_col[col]);
    }
    printf("\n");
    return 0;
}