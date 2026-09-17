#include <stdio.h>
#include <math.h>

int main(void) {
    int x[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int y[20] = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
    int z[40];
    double square_root;
    int sum;
    double total_sum;

    for (int i = 0; i < 20; i++) {
        z[i] = x[i] * y[i];
        sum += z[i];
        total_sum += sum;
        printf("z[%d] = %d\n", i, z[i]);
    }
    
    square_root = sqrt(total_sum);
    printf("Total: %d\n", total_sum); 
    printf("Square root of total: %.5f\n", square_root);
    return 0;
}
