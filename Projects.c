#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_STR 100

// Nested structure to cleanly catalog multiple historic payment installments
struct PaymentRecord {
    float amount_paid;
    char payment_date[20];
};

struct StudentFee {
    char name[MAX_STR];
    char student_number[MAX_STR];
    char academic_level[MAX_STR];
    int number_of_units;
    float rate_per_unit;
    float total_payable;
    
    struct PaymentRecord payments[10]; // Up to 10 separate payment installments per student
    int payment_count;
    
    float remaining_balance;
    char status[15];
};

// Global database array to scale up to 100 students safely
struct StudentFee student_db[MAX_STUDENTS];
int student_count = 0;

// Helper to safely strip trailing newlines from string inputs
static void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Helper function to calculate student financial totals based on matrix rules
void calculate_student_finances(struct StudentFee *s) {
    // Assign Per-Unit Rates based on Academic Level matching the matrix profile
    if (strcmp(s->academic_level, "Undergraduate") == 0) {
        s->rate_per_unit = 100.0f;
        s->total_payable = 0.0f; // Eligible for Free Education
    } else if (strcmp(s->academic_level, "Masters") == 0 || strcmp(s->academic_level, "Law School") == 0) {
        s->rate_per_unit = 200.0f;
        s->total_payable = s->number_of_units * s->rate_per_unit;
    } else if (strcmp(s->academic_level, "Doctorals") == 0) {
        s->rate_per_unit = 250.0f;
        s->total_payable = s->number_of_units * s->rate_per_unit;
    } else if (strcmp(s->academic_level, "Diploma Programs") == 0) {
        s->rate_per_unit = 100.0f;
        s->total_payable = s->number_of_units * s->rate_per_unit;
    } else {
        s->rate_per_unit = 0.0f;
        s->total_payable = 0.0f;
    }

    // Sum up all submitted history installments
    float total_paid = 0.0f;
    for (int i = 0; i < s->payment_count; i++) {
        total_paid += s->payments[i].amount_paid;
    }

    // Compute the final outstanding balances and statuses
    if (strcmp(s->academic_level, "Undergraduate") == 0) {
        s->remaining_balance = 0.0f;
        strcpy(s->status, "Paid");
    } else {
        s->remaining_balance = s->total_payable - total_paid;
        if (s->remaining_balance <= 0.0f) {
            s->remaining_balance = 0.0f;
            strcpy(s->status, "Paid");
        } else {
            strcpy(s->status, "Unpaid");
        }
    }
}

// Loops through the total student count and prints a clean layout table
void display_student_matrix(void) {
    if (student_count == 0) {
        printf("\nNo student records available to display.\n");
        return;
    }

    printf("\n%22s | %18s | %18s | %5s | %22s | %18s | %25s | %18s | %8s\n",
           "Name", "Student Number", "Academic Level", "Units", "Balance Breakdown", 
           "Total Payable", "Payment History", "Remaining Balance", "Status");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < student_count; i++) {
        struct StudentFee s = student_db[i];
        
        char breakdown[50];
        char payable_str[30];
        char remaining_str[30];
        
        sprintf(breakdown, "%d Units * PHP %.0f", s.number_of_units, s.rate_per_unit);
        sprintf(payable_str, "PHP %.2f", s.total_payable);
        sprintf(remaining_str, "PHP %.2f", s.remaining_balance);

        int lines_to_print = (s.payment_count > 0) ? s.payment_count : 1;
        for (int j = 0; j < lines_to_print; j++) {
            char history_str[50] = "";
            
            if (strcmp(s.academic_level, "Undergraduate") == 0) {
                strcpy(history_str, "Eligible for Free Education");
            } else if (s.payment_count > 0) {
                sprintf(history_str, "PHP %.2f | %s", s.payments[j].amount_paid, s.payments[j].payment_date);
            } else {
                strcpy(history_str, "No Payments");
            }

            if (j == 0) {
                // Primary data row mapping flag configuration
                printf("%22s | %18s | %18s | %5d | %22s | %18s | %25s | %18s | %8s\n",
                       s.name, s.student_number, s.academic_level, s.number_of_units, 
                       breakdown, payable_str, history_str, remaining_str, s.status);
            } else {
                // Sub-rows tracking payment installments matching original matrix logic blocks
                printf("%22s | %18s | %18s | %5s | %22s | %18s | %25s | %18s | %8s\n",
                       "", "", "", "", "", "", history_str, "", "");
            }
        }
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
}

// Dynamic Input collection workflow to populate the array up to 100 students
void input_students(void) {
    char choice;
    
    while (student_count < MAX_STUDENTS) {
        struct StudentFee *s = &student_db[student_count];
        s->payment_count = 0;
        
        printf("\n--- Entering Details for Student #%d ---\n", student_count + 1);
        
        printf("Student Name (e.g., Dela Cruz, Juan M.): ");
        fgets(s->name, MAX_STR, stdin);
        trim_newline(s->name);
        
        printf("Student Number (e.g., 2024-01-1672-MN-0): ");
        fgets(s->student_number, MAX_STR, stdin);
        trim_newline(s->student_number);
        
        printf("Academic Level (Undergraduate/Masters/Doctorals/Law School/Diploma Programs): ");
        fgets(s->academic_level, MAX_STR, stdin);
        trim_newline(s->academic_level);
        
        printf("Number of Units: ");
        scanf("%d", &s->number_of_units);
        while (getchar() != '\n' && !feof(stdin)); // Clear keyboard input buffer safely
        
        // Collect custom payment sequences for fee-paying academic tiers
        if (strcmp(s->academic_level, "Undergraduate") != 0) {
            printf("How many payment installments has this student made? ");
            int p_count;
            scanf("%d", &p_count);
            while (getchar() != '\n' && !feof(stdin));
            
            for (int i = 0; i < p_count && i < 10; i++) {
                printf("  Enter payment amount #%d: ", i + 1);
                scanf("%f", &s->payments[i].amount_paid);
                while (getchar() != '\n' && !feof(stdin));
                
                printf("  Enter payment date #%d (MM/DD/YY): ", i + 1);
                fgets(s->payments[i].payment_date, 20, stdin);
                trim_newline(s->payments[i].payment_date);
                
                s->payment_count++;
            }
        }
        
        // Calculate ledger data positions immediately
        calculate_student_finances(s);
        student_count++;
        
        // Evaluation prompt check step
        if (student_count < MAX_STUDENTS) {
            printf("\nDo you want to add another student record? (y/n): ");
            scanf(" %c", &choice);
            while (getchar() != '\n' && !feof(stdin));
            if (choice == 'n' || choice == 'N') {
                break;
            }
        }
    }
}

int main(void) {
    input_students();
    display_student_matrix();
    return 0;
}