#include <stdio.h>
#define MINUTES_IN_HOUR 60
int main(void){
    
    float hr = 0.0;
    float num_of_min = 0.0;
    printf("Enter number of hours: ");
    scanf("%f", &hr);
    num_of_min = hr * 60;
    printf("%.f hours is equal to %.2f minutes", hr, num_of_min);
    return 0;
}