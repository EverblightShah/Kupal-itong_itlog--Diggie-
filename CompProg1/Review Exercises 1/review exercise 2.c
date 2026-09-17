#include <stdio.h>

int main(void){
    float ft = 0.0;
    float feet_to_inches = 0.0;
    float inches_to_cm = 0.0;
    float cm_to_meter = 0.0;
    printf("Please input value of ft: ");
    scanf("%f", &ft);
    feet_to_inches = ft * 12.0;
    inches_to_cm = feet_to_inches * 2.54;
    cm_to_meter = inches_to_cm / 100;
    printf("The value inches: %.2f\n", feet_to_inches);
    printf("The value in cm: %.3f\n", inches_to_cm);
    printf("The value in feet: %.4f\n", cm_to_meter);
    return 0.0;
}