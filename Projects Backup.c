#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 100
#define MAX_STR 100

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
    
    struct PaymentRecord payments[10]; 
    int payment_count;
    
    float remaining_balance;
    char status[15];
};

struct StudentFee student_db[MAX_LIMIT];
int student_count = 0;

static void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Convert numeric choice to academic level string
static void set_academic_level_from_choice(int choice, char *level) {
    switch (choice) {
        case 1:
            strcpy(level, "undergraduate");
            break;
        case 2:
            strcpy(level, "diploma programs");
            break;
        case 3:
            strcpy(level, "masters");
            break;
        case 4:
            strcpy(level, "doctorals");
            break;
        case 5:
            strcpy(level, "law school");
            break;
        case 6:
            strcpy(level, "post baccalaureate");
            break;
        default:
            strcpy(level, "unknown");
            break;
    }
}

void calculate_student_finances(struct StudentFee *s) {
    if (strcmp(s->academic_level, "undergraduate") == 0 || strcmp(s->academic_level, "diploma programs") == 0) {
        s->rate_per_unit = 100.0f;
        s->total_payable = 0.0f;  // Free tuition
    } else if (strcmp(s->academic_level, "masters") == 0 || strcmp(s->academic_level, "law school") == 0) {
        s->rate_per_unit = 200.0f;
        s->total_payable = s->number_of_units * s->rate_per_unit;
    } else if (strcmp(s->academic_level, "post baccalaureate") == 0) {
        s->rate_per_unit = 180.0f;
        s->total_payable = s->number_of_units * s->rate_per_unit;
    } else if (strcmp(s->academic_level, "doctorals") == 0) {
        s->rate_per_unit = 250.0f;
        s->total_payable = s->number_of_units * s->rate_per_unit;
    } else {
        s->rate_per_unit = 0.0f;
        s->total_payable = 0.0f;
    }

    float total_paid = 0.0f;
    for (int i = 0; i < s->payment_count; i++) {
        total_paid += s->payments[i].amount_paid;
    }

    if (strcmp(s->academic_level, "undergraduate") == 0 || strcmp(s->academic_level, "diploma programs") == 0) {
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
            
            if (strcmp(s.academic_level, "undergraduate") == 0 || strcmp(s.academic_level, "diploma programs") == 0) {
                strcpy(history_str, "Eligible for Free Education");
            } else if (s.payment_count > 0) {
                sprintf(history_str, "PHP %.2f | %s", s.payments[j].amount_paid, s.payments[j].payment_date);
            } else {
                strcpy(history_str, "No Payments");
            }

            if (j == 0) {
                printf("%22s | %18s | %18s | %5d | %22s | %18s | %25s | %18s | %8s\n",
                       s.name, s.student_number, s.academic_level, s.number_of_units, 
                       breakdown, payable_str, history_str, remaining_str, s.status);
            } else {
                printf("%22s | %18s | %18s | %5s | %22s | %18s | %25s | %18s | %8s\n",
                       "", "", "", "", "", "", history_str, "", "");
            }
        }
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
}

// Accepts a target batch size to dynamically control execution length
void input_students(int target_limit) {
    while (student_count < target_limit && student_count < MAX_LIMIT) {
        struct StudentFee *s = &student_db[student_count];
        s->payment_count = 0;
        
        printf("\n--- Entering Details for Student #%d of %d ---\n", student_count + 1, target_limit);
        
        printf("Student Name (e.g., Dela Cruz, Juan M.): ");
        fgets(s->name, MAX_STR, stdin);
        trim_newline(s->name);
        
        printf("Student Number (e.g., 2024-01-1672-MN-0): ");
        fgets(s->student_number, MAX_STR, stdin);
        trim_newline(s->student_number);
        
        printf("\nSelect Academic Level:\n");
        printf("  1 - Undergraduate\n");
        printf("  2 - Diploma Programs\n");
        printf("  3 - Masters\n");
        printf("  4 - Doctorals\n");
        printf("  5 - Law School\n");
        printf("  6 - Post Baccalaureate Degrees\n");
        printf("Enter your choice (1-6): ");
        int level_choice;
        scanf("%d", &level_choice);
        while (getchar() != '\n' && !feof(stdin));
        set_academic_level_from_choice(level_choice, s->academic_level);
        
        printf("Number of Units: ");
        scanf("%d", &s->number_of_units);
        while (getchar() != '\n' && !feof(stdin));
        
        if (strcmp(s->academic_level, "undergraduate") != 0 && strcmp(s->academic_level, "diploma programs") != 0) {
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
        
        calculate_student_finances(s);
        student_count++;
    }
}

int main(void) {
    int requested_students;
    
    printf("=============================================\n");
    printf("   UNIVERSITY STUDENT FEE LEDGER SYSTEM\n");
    printf("=============================================\n");
    printf("Enter the number of students to record (Max 100): ");
    scanf("%d", &requested_students);
    while (getchar() != '\n' && !feof(stdin)); // Clear input buffer
    
    // Validate bounds constraint entry safely
    if (requested_students > MAX_LIMIT) {
        printf("Requested size exceeds safety limit. Adjusting entry window to 100.\n");
        requested_students = MAX_LIMIT;
    } else if (requested_students < 1) {
        printf("Invalid record count. Initializing window with a baseline of 1.\n");
        requested_students = 1;
    }
    
    // Run loop using the precise customized limit
    input_students(requested_students);
    display_student_matrix();
    
    return 0;
}