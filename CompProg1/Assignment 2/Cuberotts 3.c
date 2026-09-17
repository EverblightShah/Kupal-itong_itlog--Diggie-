#include <stdio.h>
#include <math.h>

int main(void){
    int sumofcuberoots = 0, upper_limit = 100;
    for (int i = 1; i < upper_limit; i+= 2) {
        double cuberoot = cbrt(i);
        if (cuberoot == (int)cuberoot) {
            sumofcuberoots += (int)cuberoot;
        }
    }
    printf("Sum of cube roots of odd perfect cubes below %d is: %d\n", upper_limit, sumofcuberoots);
    printf("Do You want to try again? (1 - yes /0 - no): ");
    int response;
    scanf("%d", &response);
    if (response == 1) {
        main();
    } else {
        printf("Thank you for using the program!\n");
    }
    return 0;
}