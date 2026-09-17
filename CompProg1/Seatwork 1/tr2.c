#include <stdio.h>

int main(){
    
    int  rectangle_height = 0, rectangle_base = 0, triangle_height = 0, triangle_base = 0, triangle_area = 0, rectangle_area = 0;
    
    printf("Input Triangle Base: ");
    scanf("%d",&triangle_base);
    printf("Input Triangle Height: ");
    scanf("%d",&triangle_height);
    printf("Input Rectangle Base: ");
    scanf("%d",&rectangle_base);
    printf("Input Rectangle Height: ");
    scanf("%d",&rectangle_height);
    
    rectangle_area = rectangle_base * rectangle_height;
    triangle_area = (triangle_height * triangle_base)/2;
    
    printf("\nArea of Triangle is %d", triangle_area);
    printf("\nArea of Rectangle is %d", rectangle_area);
    
    
    return 0;
}