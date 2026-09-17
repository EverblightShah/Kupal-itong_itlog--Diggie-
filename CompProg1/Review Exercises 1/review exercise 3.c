#include <stdio.h>

int main(void){
    float weight_in_earth;
    float weight_in_mars;
    float weight_in_jupiter;
    printf("Please input your current weight in pounds: ");
    scanf("%f", &weight_in_earth);
    weight_in_mars = weight_in_earth * 0.38;
    weight_in_jupiter = weight_in_earth * 2.64;
    printf("Your weight in mars is: %.2f lbs\n", weight_in_mars);
    printf("Your weight in Jupiter is: %.2f lbs\n", weight_in_jupiter);
    return 0;

}