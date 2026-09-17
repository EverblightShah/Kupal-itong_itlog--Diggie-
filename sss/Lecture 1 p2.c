#include <stdio.h>
#include <conio.h>
int x = 0, y = 0;

void you(){
    y = x++;
    x = y + 5;
    printf("YOu have %d and %d\n", x, y);
    return;
}
void me(){
    y = y + x++;
    x += y;
    printf("I have %d and %d\n", x, y);
    return;
}
int main(){
    int a = 10, b = 25;
    you();
    printf("After you, I have %d and %d\n", x, y);
    me();
    printf("After me, I have %d and %d\n", x, y);
    me();
    printf("After me again, I have %d and %d\n", x, y);
    you();
    printf("After you again, I have %d and %d\n", x, y);
    getch();
    return 0;
}