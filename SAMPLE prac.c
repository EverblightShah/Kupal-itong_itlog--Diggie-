#include <stdio.h>

#define MAX_STUDENTS 50   //  3 points Task 1
#define MAX_NAME_LEN 50  
#define MAX_SUBJECTS 50

void clear_input_buffer(void); // 5 points Task 4
void clear_char(char answer[10]);  // 5 points Task 4

int students(char student_names[MAX_STUDENTS][MAX_NAME_LEN]) {  // 10 points Task 1
    int number_of_students;

    printf("Enter the number of students: ");
    scanf("%d", &number_of_students);
    if (number_of_students != 1) {
        clear_input_buffer();
        printf("Invalid input. Please enter the number of students again.\n");
        scanf("%d", &number_of_students);
    }

    if (number_of_students < 1) {
        number_of_students = 1;
    }
    if (number_of_students > MAX_STUDENTS) {
        number_of_students = MAX_STUDENTS;
    }

    for (int i = 0; i < number_of_students; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%49s", student_names[i]);
    }

    return number_of_students;
}
int get_subject_count(void) {  // 3 points Task 1 - Total 20 points Task 1
    int subjects;
    while (1) {
        printf("Enter the number of subjects: ");
        if (scanf("%d", &subjects) != 1) {
            clear_input_buffer();
            printf("Invalid input. Please enter a whole number.\n");
            continue;
        }
        clear_input_buffer();
        break;
    }

    if (subjects < 1) {
        subjects = 1;
    }
    if (subjects > MAX_SUBJECTS) {
        subjects = MAX_SUBJECTS;
    }

    return subjects;
}
void clear_input_buffer(void) { // 5 points Task 4
    int grades;
    while ((grades = getchar()) != '\n' && grades != EOF) {  
        // Discard characters until a newline or EOF is encountered
    }
}
//  4 points Task 1 - Total 20 points Task 1
void student_grades(float grades[MAX_SUBJECTS], int subjects, const char student_name[MAX_NAME_LEN]) {
    printf("\nEntering grades for %s\n", student_name);
    for (int i = 0; i < subjects; i++) {
        int is_valid = 0;
        while (!is_valid) {
            printf("Enter grade for subject %d: ", i + 1);
            if (scanf("%f", &grades[i]) != 1) {
                clear_input_buffer();
                printf("Invalid input. Please enter a number from 0 to 100.\n");
                continue;
            }

            if (grades[i] < 0.0f || grades[i] > 100.0f) {
                clear_input_buffer();
                printf("Invalid grade. Please enter a number from 0 to 100.\n");
                continue;
            }

            is_valid = 1;
            clear_input_buffer();
        }
    }
}
void clear_char(char answer[10]) { // 5 points Task 4 - Total 20 points Task 4
    if (answer[0] != 'y' && answer[0] != 'Y' && answer[0] != 'n' && answer[0] != 'N') {
        printf("Invalid input. Please enter 'yes' or 'no': ");
        scanf("%s", answer);
    }
    return;
}
// 5 points Task 3 
float calculate_average(float grades[MAX_SUBJECTS], int subjects) {
    float sum = 0.0;
    for (int i = 0; i < subjects; i++) {
        sum += grades[i];
    }
    return sum / subjects;
}
// 10 Points Task 3 - total 20 points Task 3
void passed_or_failed(float average, const char student_name[MAX_NAME_LEN]) {
    if (average >= 75.0) {
        printf(" %s Passed the exam with an average grade of %.2f.\n", student_name, average);
    } else {
        printf("Unfortunately, %s failed the exam with an average grade of %.2f. Better luck next time!\n", student_name, average);
    }
}
// 5 points Task 3 - Total 20 points Task 3
void display_results(float average, const char student_name[MAX_NAME_LEN]) {
    printf("\n");
    printf("Student Name: %s\n", student_name);
    printf("Average Grade: %.2f\n", average);
    passed_or_failed(average, student_name);
}

int main() {
    char student_names[MAX_STUDENTS][MAX_NAME_LEN];
    float grades[MAX_SUBJECTS];
    char response[10];

    printf("Do you want to submit the exam? (yes/no): "); // 5 points Task 5
    scanf("%s", response);
    clear_char(response);

    if (response[0] == 'y' || response[0] == 'Y') { // 3 points Task 5
        printf(" \n");
    } else {
        printf("This is a test run, this does not reflect the final submission.\n"); // 2 points Task 5
    }

    printf("\n");
    printf("Welcome to the student grade management system.\n"); // 5 points Task 5

    int number_of_students = students(student_names);
    int subjects = get_subject_count();

    for (int i = 0; i < number_of_students; i++) {
        student_grades(grades, subjects, student_names[i]);
        float average = calculate_average(grades, subjects);
        display_results(average, student_names[i]);
    }
    do { // 5 points Task 5 - Total 20 points Task 5
        printf("Do you want to run the program again? (yes/no): ");
        scanf("%s", response);
        if (response[0] == 'y' || response[0] == 'Y') {
            main();
        } else if (response[0] == 'n' || response[0] == 'N') {
            printf("Exiting the program. Goodbye!\n");
            return 0;
        } else {
            clear_char(response);
        }
    }
    while (1);
}
// Final score: 95 points Sample practical exam. made within 1 hour. 