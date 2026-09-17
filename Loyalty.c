#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// Validate File
void validate_file(){
       FILE *file = fopen("C:\\Users\\nooba\\Downloads\\record.txt", "r");
       if (file == NULL) {
        printf("Cannot open File.");
       } else {
        printf("All good.");
    }
}

// Loyalty Awardee Requirement
int current_year = 2026;
int employee_count; 
// Employee Info 

struct employee_info {
    char employee_id[50];
    char employee_name[MAX];
    char employee_address[MAX];
    char dept_name[MAX];
    char position[MAX];
    int year_hired;
};

void input_employee_details(struct employee_info){
    int i, employee_count = 0;
    printf("How many employees do you want to input?: ");
    scanf("%d", &employee_count);
    FILE *file = fopen("C:\\Users\\nooba\\Downloads\\record.txt", "a");
    for(i = 0; i < employee_count; i++) {
        printf("Employee info # %d ", i + 1);
        printf("Employee id: ");
        scanf("%s" , &(employee_info[i].employee_id));
        printf("Employee name (Replace spaces with underscore): ");
        scanf("%s", &employee_info[i].employee_name);
        printf("Employee address (Replace spaces with underscore): ");
        scanf("%s", &employee_info[i].employee_adress);
        printf("Employee Department Name (Replace spaces with underscore): ");
        scanf("%s", &employee_info[i].dept_name);
        printf("Employee Position (Replace spaces with underscore): ");
        scanf("%s", &employee_info[i].position);
        printf("Year hired: ");
        scanf("%d", &employee_info[i].year_hired);
    }
    for (i = 0; i < employee_count; i++){
        FILE *file = fopen("C:\\Users\\nooba\\Downloads\\record.txt", "a");
        fprintf("%s | %50s | %100s | %100s |  %100s | %100s | %d ", employee_info[i].employee_id, employee_info[i].employee_name, employee_info[i].employee_adress, employee_info[i].dept_name, employee_info[i].position, employee_info[i].year_hired);
    }
    fclose(file);
}
void employee_validation_awardee(int year_hired) {
    FILE *file = fopen("C:\\Users\\nooba\\Downloads\\record.txt", "rw");
    for (int i = 0; i < employee_count; i++){
        if (year_hired >= current_year){
            fprintf("Loyalty Awardee\n", "a");
        }
    }
}
int main() {
    struct employee_info;
    validate_file();
    input_employee_details();
    employee_validation_awardee();
    return 0;
}