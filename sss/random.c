#include <stdio.h>

int main(void){
    int grades[3][3] = {0};
    int sum = 0;
    int row = 2; 
    int col = 3;
    float average = 0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("Enter your grade: ");
            scanf("%d", &grades[i][j]);
        }
    }
    printf("Calculating for the sum and average\n");

    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            sum += grades[i][j];
        }
        average = sum / 3;
    }
    printf("The final average is %.2f", average);
    return 0; 
}