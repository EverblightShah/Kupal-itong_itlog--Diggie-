#include <stdio.h>

int main(void){
    float weight_in_lbs;
    float height_in_inches;
    float bmi = 0.0;
    printf("Please enter your weight in pounds: ");
    scanf("%f", &weight_in_lbs);
    printf("Please enter your height in inches: ");
    scanf("%f", &height_in_inches);
    bmi = 703 * weight_in_lbs / (height_in_inches * height_in_inches);
    printf("\nYour BMI is: %.1f\n", bmi);
    if (bmi <= 18.5) {
        printf("\nYou are underweight. Please consult with your healthcare provider for advice.\n");
    } else {
        if (bmi >= 18.5 && bmi <= 24.9){
            printf("\nYou have a normal weight. Keep up the good work!\n");
        } else {
            if (bmi >= 25.0 && bmi <= 29.9){
                printf("\nYou are overweight. Consider a balanced diet and regular exercise.\n");
            } else {
                printf("\nYou are obese. It is advisable to seek guidance from a healthcare professional.\n");
            }
        }
    }
    return 0;
    }