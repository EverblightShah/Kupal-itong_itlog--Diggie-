#include <stdio.h>

int main(void){
    int base = 0; 
    int height = 0;
    int area_of_triangle = 0;
    int area_of_rectangle = 0;
    printf("Please input value for base: ");
    scanf("%d", &base);
    printf("Please input value for height: ");
    scanf("%d", &height);
    area_of_triangle =  base * height / 2; 
    area_of_rectangle = base * height; 
    printf("The area of the triangle is: %d\n", area_of_triangle);
    printf("The area of the rectangle is: %d\n", area_of_rectangle);
    return 0;
}