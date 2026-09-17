#include <stdio.h>

int main(){
    float grades [50][10];
    int students = 0;
    float average = 0;
    int sum = 0;
    int subjects = 0;
    printf("Please input the number of students: ");
    scanf("%d", &students);
    printf("Please input the number of subjects: ");
    scanf("%d", &subjects);
    for (int i = 0; i < students; i++){
        grades[students][subjects] = 0;
        printf("\nEnter the grades of student %d: ", i + 1);
        for (int j = 0; j < subjects; j++){
            scanf("%f", &grades[j][i]);
            sum += grades[j][i];
        }
            average = 0;
            average = sum / subjects;
            printf("Student %d Average grade: %.2f\n", i + 1, average);
    }
    printf("\n");
    for (int i = 0; i < students; i++){
        if (average < 75){
            printf("Student %d, FAILED; his/her average was %.2f", i + 1, average);
        }
    }
    return 0; 
}