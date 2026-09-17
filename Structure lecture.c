#include <stdio.h>
#include <conio.h>

// structure TEMPLATE which will be used to create a structure variable to store student details
// A structure is a user-defined data type that allows you to group different types of variables together under a single name.
// Much more organized than an array, which can only store one type of data. 
// Structures can contain multiple members of different types, making them ideal for representing complex data. 
struct student_record {
    char student_number[20]; // 
    char student_name[50];
    char course[50];
    char year_level[20];
};
int main() {
    struct student_record student;
    
    for(int i = 0; i < 3; i++) {
        printf("Enter student number: ");
        scanf("%s", student.student_number);
        
        printf("Enter student name: ");
        scanf("%s", student.student_name);
        
        printf("Enter course: ");
        scanf("%s", student.course);
        
        printf("Enter year level: ");
        scanf("%s", student.year_level);
    }
    printf("\n--- Student Details ---\n");
    for(int i = 0; i < 3; i++) {
        printf("Student Number: %s\n", student.student_number);
        printf("Student Name: %s\n", student.student_name);
        printf("Course: %s\n", student.course);
        printf("Year Level: %s\n", student.year_level);
        printf("\n");
    }
    return 0;
}