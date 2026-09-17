#include <stdio.h>
#include <string.h>

int main(void){
     int score = 0;
     int total_score = 0;
     float average = 0.0;
     int i = 0;
     struct {
         char name[50];
     } student;
        printf("Please enter your name: ");
        scanf("%49s", student.name);
        for (i = 0; i < 5; i++) {
            printf("Enter your answer for question %d: ", i + 1);
            scanf("%d", &score);
            /* validate score: if out of expected range (e.g., negative or >6), treat as zero */
            if (score >= 6 || score < 0) {
                printf("You are out of range. Your score for this question will be zero.\n");
                score = 0;
            }
            total_score += score;
        }
        average = total_score / 5.0;
        printf("\nStudent Name: %s\n", student.name);
        printf("Total Score: %d\n", total_score);
        printf("Average Score: %.2f\n", average);
    return 0;
}
