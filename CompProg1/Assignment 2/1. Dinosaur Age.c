#include <stdio.h>

int main(void){
    float erick_years_old = 0;
    float erick_months_old = 0;
    float erick_days_old = 0;
    float erick_seconds_old = 0;
    float alfred_years_old = 0;
    float alfred_months_old = 0;
    float alfred_days_old = 0;
    float alfred_seconds_old = 0;
    float years_in_a_day = 365.25;
    int months_in_a_year = 12;
    int days_in_a_month = 30;
    float seconds_in_a_day = 86400;
    printf("Enter Erick's age in years: ");
    scanf("%f", &erick_years_old);
    printf("Enter Alfred's age in years: ");
    scanf("%f", &alfred_years_old);
    erick_days_old = erick_years_old * years_in_a_day;
    erick_months_old = erick_years_old * months_in_a_year;
    erick_days_old = erick_months_old * days_in_a_month;
    erick_seconds_old = erick_days_old * seconds_in_a_day;
    alfred_days_old = alfred_years_old * years_in_a_day;
    alfred_months_old = alfred_years_old * months_in_a_year;
    alfred_days_old = alfred_months_old * days_in_a_month;
    alfred_seconds_old = alfred_days_old * seconds_in_a_day;
    printf("Erick is %.2f months old.\n", erick_months_old);
    printf("Erick is %.2f days old.\n", erick_days_old);
    printf("Erick is %.2f seconds old.\n", erick_seconds_old);
    printf("Alfred is %.2f months old.\n", alfred_months_old);
    printf("Alfred is %.2f days old.\n", alfred_days_old);
    printf("Alfred is %.2f seconds old.\n", alfred_seconds_old);
    return 0;
}