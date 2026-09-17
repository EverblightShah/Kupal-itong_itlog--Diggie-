#include <stdio.h>

int main(void){
int min, max;
int size = 6;
int arr[6] = {55, 12, 89, 4, 30, 77};
min = arr[0];
max = arr[0];

for (int i = 1; i < size; i++){
    if (arr[i] > max){
    max = arr[i];
    }
    if (arr[i] < min){
        min = arr[i];
    }
 }
    printf("Biggest number: %d\n", max);
    printf("Smallest number: %d", min);
    return 0;
}