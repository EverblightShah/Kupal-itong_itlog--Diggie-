#include <stdio.h>

int main(void){
    int count = 0, sumofcuberoots = 0, response = 0, num;

    printf("Please enter your numbers: ");

    for (int i = 1; i < 100; i){
    scanf("%d", &num);
    }
    for (int i = 1; i <= 100; i+=2) {
        int cube = i * i * i;
        sumofcuberoots += cube;
        count++;
    }

    printf("The sum of the cubes of the first %d natural numbers is: %d\n", count, sumofcuberoots);
    printf("Do you want to continue? (1 for Yes / 0 for No): ");
    if (scanf("%d", &response) != 1) return 0;

    while (response == 1){
        sumofcuberoots = 0;
        count = 0;
        for (int i = 1; i <= 100; i++){
            int cube = i * i * i;
            sumofcuberoots += cube;
            count++;
        }
        printf("The sum of the cubes of the first %d natural numbers is: %d\n", count, sumofcuberoots);
        printf("Do you want to continue? (1 for Yes / 0 for No): ");
        if (scanf("%d", &response) != 1) break;
    }
    return 0;
}