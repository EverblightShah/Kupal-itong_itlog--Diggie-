#include <stdio.h>

int main(){
    
    int X = 0, Y = 0, Z = 0, SUM = 0;
    float AVERAGE = 0;
    
    printf("Input X Value: ");
    scanf("%d", &X);
    printf("Input Y Value: ");
    scanf("%d", &Y);
    printf("Input Z Value: ");
    scanf("%d", &Z);
    
    SUM = X + Y + Z;
    AVERAGE = SUM/3;
    
    printf("The Average of X, Y, Z is %.2f", AVERAGE);
    
    
    return 0;
}