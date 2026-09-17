#include <stdio.h>

int main() {
	char pattern[100][100];
    int layers;							
    int r, c;
    int rows;
    int col;
    int mid;
    
    printf("\nYou are an ancient architect summoned by Queen Cleopatra.\n"
        "She commands you to build a secret pyramid fortress where her body \n"
        "will lay rest after her death. The pyramid must be tall \n"
        "enough to scare intruders.\n\n");
	printf("How many levels should the pyramid have?: ");
    scanf("%d", &layers);
    printf("\n");
    rows = layers;
    col = (layers * 2) - 1;
    mid = col / 2;
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < col; c++) {
            pattern[r][c] = ' ';
        }
    for (int r = 0; r < rows; r++) {
        for(int c = 0; c <= r; c++) {
            pattern[r][mid - r + (c * 2)] = '*';
            if (c == col) {
                break;
            }
        }
    }
    printf("\n Here is the pyramid fortress you have built for Queen Cleopatra:\n\n");
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < col; c++) {
            printf("%c", pattern[r][c]);
        }
        printf("\n");
    }
    printf("\nThe pyramid fortress is complete! Queen Cleopatra will be pleased to see this.\n");
    return 0;
    }
}