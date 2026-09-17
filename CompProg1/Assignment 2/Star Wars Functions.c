#include <stdio.h>

char name[50];
float height = 0;
int age = 0;
char recommendee_of_master_obi;
char citizen_of_planet_endor;
void gather_user_info() {
    printf("Enter your name: ");
    scanf("%49s", name);
    printf("Enter your height in cm: ");
    scanf("%f", &height);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Are you a citizen of planet Endor? (y/n): ");
    scanf(" %c", &citizen_of_planet_endor);
}
void evaluate_eligibility() {
    if ((age >= 21 && age <= 25) && (height >= 200.00) && (citizen_of_planet_endor == 'y' || citizen_of_planet_endor == 'Y')) {
        printf("\nCongratulations %s, you are eligible to join the Jedi Academy!\n", name);
    } else {
        printf("\nAlthough you are not eligible to join the Jedi Knight Academy, there is still a chance.\n");
        printf("\nAre you a recommendee of Master Obi-Wan Kenobi? (y/n): ");
        scanf(" %c", &recommendee_of_master_obi);
        if (recommendee_of_master_obi == 'y' || recommendee_of_master_obi == 'Y') {
            printf("Congratulations %s, you are eligible to join the Jedi Knight Academy!\n", name);
        } else {
            printf("Sorry %s, you are not eligible to join the Jedi Academy.\n", name);
        }
    }
}
int main(void) {
    gather_user_info();
    evaluate_eligibility();
    return 0;
}