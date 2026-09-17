#include <stdio.h>
#include <stdlib.h>

void char_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Discard characters until a newline or EOF is found
    }
}
void clear_input_buffer() {
    int time;
    while ((time = getchar()) != '\n' && time != EOF) {
        // Discard characters until a newline or EOF is found
    }
}
int check_time(int time){
    int hours, minutes;
    printf("\nPlease enter a time in 24 hour format (e.g. 1300):\n");
    while (1) {
        if (scanf("%d", &time) != 1) {
            clear_input_buffer();
            printf("\nInvalid input. Please enter a valid time.\n");
            printf("Please enter a time in 24 hour format (e.g. 1300): \n");
            continue;
        }
        hours = time / 100;
        minutes = time % 100;
        if (time < 0 || time > 2400 || minutes >= 60) {
            clear_input_buffer();
            printf("\nInvalid time format. Please enter a valid time.\n");
            printf("Please enter a time in 24 hour format (e.g. 1300): \n");
            continue;
        }
        break;
    }
    printf("The time you entered is: %02d:%02d\n\n", hours, minutes);
    return time;
}
void time_conversion(int time) {
    int hours, minutes;
    hours = time / 100;
    minutes = time % 100;
    if (hours == 0) {
        printf("The time in 12 hour format is: 12:%02d AM\n\n", minutes);
    } else if (hours == 24) {
        printf("The time in 12 hour format is: 12:00 AM the next day\n\n");
    } else if (hours < 12) {
        printf("The time in 12 hour format is: %02d:%02d AM\n\n", hours, minutes);
    } else if (hours == 12) {
        printf("The time in 12 hour format is: 12:%02d PM\n\n", minutes);
    } else {
        printf("The time in 12 hour format is: %02d:%02d PM\n\n", hours - 12, minutes);
    }
    return;
}
int main(){
    char answer;
    int time;

    printf("\nWelcome to the time converter!\n");
    printf("\nWhere we convert Military Time to 12 hour time!\n");

    while (1) {
        time = check_time(0);
        time_conversion(time);

        printf("Do you want to check another time? (y/n)\n");
        scanf(" %c", &answer);

        if (answer == 'y' || answer == 'Y') {
            continue;
        } else if (answer == 'n' || answer == 'N') {
            printf("Thank you for using the time checker! Goodbye!\n");
            return 0;
        } else {
            char_input_buffer();
            printf("Invalid input. Please enter 'y' or 'n'.\n");
            scanf(" %c", &answer);
        }
    }
}