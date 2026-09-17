#include <stdio.h>

int main(void) {
    int bucket_of_wine = 0;
    int barrel_leaks_of_wine_per_hour = 162;
    int drops_accumulated;
    int cat_leaks_in_wine_in_third_hour = 28;
    int hours, filled_barrel_hours = 0;
    for (int i = 1; i <= hours; i++) {
        drops_accumulated = bucket_of_wine + barrel_leaks_of_wine_per_hour;
        bucket_of_wine = drops_accumulated; 
        printf("Hour %d: drops accumulated = %d\n", i, drops_accumulated);
        printf("Current drops in a bucket of wine = %d\n", bucket_of_wine);
        hours++;
        if (i % 3 == 0) {
            bucket_of_wine = drops_accumulated - cat_leaks_in_wine_in_third_hour;
            printf("The cat licked some wine! New drops of bucket of wine = %d\n", bucket_of_wine);
        }
        if (bucket_of_wine >= 2452) {
            filled_barrel_hours = i;
            printf("The barrel is full!\n");
            break;
        }
    }
    printf("The barrel was filled in %d hours.\n", filled_barrel_hours);
    printf("The cat licked a total of %d drops of wine.\n", (filled_barrel_hours / 3) * cat_leaks_in_wine_in_third_hour);
    return 0;
}