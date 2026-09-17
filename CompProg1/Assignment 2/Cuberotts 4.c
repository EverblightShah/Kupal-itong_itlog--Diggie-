#include <stdio.h>
#include <math.h>

int main(void){
    float num1, cuberoot, sum_of_cube_roots = 0.0;
    int num;
    printf("Please enter your starting number: ");
    scanf("%d", &num);
    if(num % 2 == 0){
        num1 = num + 1;
    } else {
        num1 = num;
    }
    for(float i = num1; i < 100; i += 2){
        cuberoot = cbrt(i);
        sum_of_cube_roots += cuberoot;
    }
    printf("The sum of the cube roots is: %.2f\n", sum_of_cube_roots);
    int response;
    printf("Do you wish to continue? (1- Yes/0 - No): ");
    scanf("%d", &response);
    if(response == 1){
        main();
    } else {
        printf("Thank you for using the program. Goodbye!\n");
    }
}