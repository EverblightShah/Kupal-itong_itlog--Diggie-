#include <stdio.h>

// Mating rabbit Fibonacci sequence, they mate constantly and produce a new pair of rabbits every month, 
// starting with 1 pair of rabbits in the first month. How many rabbits will there be after n months?
// This a problem for the owner
int FIBO_spay_your_rabbits(int n){
    if (n == 1 || n == 2){
        return 1;
    } else {
        return FIBO_spay_your_rabbits(n - 1) + FIBO_spay_your_rabbits(n - 2);
    }
}
int main(){
    int rabbits[12];
    printf("Welcome to the rabbit calculator!\n");
    printf("Where we calculate the number of rabbits you will have after 12 months!\n");
    printf("\nPress any key to continue...");
    char answer;
    scanf("%c", &answer);
    if(answer){
        for (int i = 0; i < 12; i++){
            rabbits[i] = FIBO_spay_your_rabbits(i + 1);
        }
        printf("\nCalculating the number of rabbits...\n");
        printf("\n");
        printf("\nYou will have %d rabbits after 12 months!\n", rabbits[11]);
    }
    printf("\nJust A friendly reminder, rabbits can reproduce very quickly.\n");
    printf("Make sure to spay or neuter your rabbits to avoid overpopulation.\n");
    do {
        printf("\nDo you want to run the rabbit calculator again? (y/n): ");
        scanf(" %c", &answer);
        if (answer == 'y' || answer == 'Y') {
            main(); // Call main again to restart the program
        } else if (answer == 'n' || answer == 'N') {
            printf("\nThank you for using the rabbit calculator! Goodbye!\n");
            break;
            return 0; // Exit the program
        } else {
            printf("\nInvalid input, please enter 'y' or 'n'.\n");
            scanf(" %c", &answer); // Read input again
        }
    } while (1);
    return 0;
}