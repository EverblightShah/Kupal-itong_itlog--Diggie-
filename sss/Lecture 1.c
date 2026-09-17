#include <stdio.h>

int a = 100, b = 200;

int Yve(int y){
    int C, D;
    static int prod = 1;
    int func2(int x);
    C = func2(y);
    D = (C < 100) ? (a + C): b;
    prod *= D;
    return prod;
}
int Sora(int x){
    static int prod = 1;
    prod *= x;
    return prod;
}

int Soyou() {
    int c, last, middle, first, search, num[6], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &c);
    printf("Enter %d integers for your array: ", c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &num[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &search);
    first = 0;  
    last = c - 1;
    middle = (first + last) / 2;
    while (first <= last) {
        if (num[middle] < search) {
            first = middle + 1;
        } else if (num[middle] == search) {
            printf("%d found at index %d.\n", search, middle);
            return 0;
        } else {
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }
    if (first > last) {
        printf("%d not found in the array.\n", search);
    }
    return search;
}
int main() {
    may_butas_puno_ng_saging(5);
    puno_ng_saging(5);
}