#include <stdio.h>
#include <string.h>

int main(void){
    int age;
    float height;
    char citizenshipOfPlanetEndor[4];
    char recomendeeOfMasterObi[4];
    printf("Enter your age in years: ");
    scanf("%d", &age);
    printf("Enter your height in cm: ");
    scanf("%f", &height);
    printf("Are you a citizen of Planet Endor? (y/n): ");
    scanf("%3s", citizenshipOfPlanetEndor);
    if (((age >= 21 && age <= 25) && height >= 200.00 && citizenshipOfPlanetEndor[0] == 'y')) {
        printf("Congratulations! You are accepted to join the Jedi Knight Academy.\n");
    } else {
        printf("You are not eligible to join the Jedi Knight Academy but there is still a chance.\n");
        printf("Are you a recomendee of Master Obi-Wan Kenobi? (y/n): ");
        scanf("%3s", & recomendeeOfMasterObi);
        if (recomendeeOfMasterObi[0] == 'y') {
            printf("Congratulations! You are accepted to join the Jedi Knight Academy.\n");
        } else {
            printf("You are not eligible to join the Jedi Knight Academy.\n");
        }
    }
    return 0;
}