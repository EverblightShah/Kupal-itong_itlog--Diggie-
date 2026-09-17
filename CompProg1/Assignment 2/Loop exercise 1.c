#include <stdio.h>

int main(void){
    int num1, num2, M, count = 0;

    printf("Please enter your first number: ");
    scanf("%d", &num1);
    printf("Please enter your second number: ");
    scanf("%d", &num2);
    printf("Please enter the value of M: ");
    scanf("%d", &M);

    printf("\nThe numbers %d - %d which are divisible by %d are: ", num1, num2, M);
    for(int i = num1; i <= num2; i++){
        if(i % M == 0){
            printf("%d ", i);
            count++;
        }
    }
    printf("\n\nThe total numbers divisible by %d between %d and %d are: %d\n", M, num1, num2, count);
    return 0;   
}