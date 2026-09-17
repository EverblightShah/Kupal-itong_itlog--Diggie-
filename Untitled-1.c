#include <stdio.h>

int main(void){ 
    int radius = 0, area_circle = 0;
    int cic_circle = 0;
    float pi = 3.14;
    printf("Please input value of radius: ");
    scanf("%d", &radius);
    area_circle = radius * radius * pi;
    cic_circle = 2 * radius * pi;
    printf("The area of circle is %d", area_circle);
    printf("ln%d is the circumference of the circle", cic_circle);
    return 0;  
}