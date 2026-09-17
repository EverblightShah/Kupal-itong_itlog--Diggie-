#include <stdio.h>

int main(void){
    float average = 0.0;
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    average = (a + b + c) / 3.0;
    printf("The average is: %.2f\n", average);
    return 0;
}