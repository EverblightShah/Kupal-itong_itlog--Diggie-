#include <stdio.h>

int main(void){
    int num1, num2, gcf, largest;
    printf("Please enter your first positive integer: ");
    scanf("%d", &num1);
    printf("Please enter your second positive integer: ");
    scanf("%d", &num2);
    if (num1 > num2){
        largest = num1;
    } else {
        largest = num2;
    }
    for(int i = 1; i <= largest; i++){
        if(num1 % i == 0 && num2 % i == 0){
            gcf = i;
        }
    }
    printf("The Greatest Common Factor of %d and %d is: %d\n", num1, num2, gcf);
    return 0;
}   