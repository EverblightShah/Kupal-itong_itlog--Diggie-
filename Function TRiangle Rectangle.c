#include <stdio.h>

int area_of_triangle = 0;
int area_of_rectangle = 0;
int base = 0;
int height = 0;

int input_base_height() {
    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the height: ");
    scanf("%d", &height);
    return(base, height);
}
int calculate_area() {
    area_of_triangle = 0.5 * base * height;
    area_of_rectangle = base * height;
    return area_of_triangle, area_of_rectangle;
}
void display_area(int triangle_area, int rectangle_area) {
    printf("Area of Triangle: %d\n", triangle_area);
    printf("Area of Rectangle: %d\n", rectangle_area);
}
int main(void) {
    input_base_height();
    calculate_area();
    display_area(area_of_triangle, area_of_rectangle);
    return 0;
}