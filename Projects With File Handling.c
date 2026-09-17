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
    char status[MAX_LIMIT];
    char student_status[20]; 
    int opted_out;           
    int is_free_education;   
};

struct StudentFee student_db[MAX_LIMIT];
int student_count = 0;

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void to_lowercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (char)(str[i] + ('a' - 'A'));
        }
    }
}

int contains_case_insensitive(const char *haystack, const char *needle) {
    char haystack_lower[MAX_STR];
    char needle_lower[MAX_STR];

    if (strlen(haystack) >= MAX_STR || strlen(needle) >= MAX_STR) {
        return 0;
    }

    strcpy(haystack_lower, haystack);
    strcpy(needle_lower, needle);
    to_lowercase(haystack_lower);
    to_lowercase(needle_lower);

    return strstr(haystack_lower, needle_lower) != NULL;
}

// Consolidated safe-input tool to trap anomalies and overflows automatically
void safe_fgets(char *str, int size) {
    if (fgets(str, size, stdin)) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        } else {
            // Buffer filled entirely; clear remaining junk characters out of stdin
            clear_input_buffer();
        }
    } else {
        str[0] = '\0';
    }
}

int get_valid_int(const char *prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            clear_input_buffer();
            return value;
        } else {
            printf("Incorrect input. Please enter a valid number.\n");
            clear_input_buffer();
        }
    }
}

float get_valid_float(const char *prompt) {
    float value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%f", &value) == 1) {
            clear_input_buffer();
            return value;
        } else {
            printf("Incorrect input. Please enter a valid monetary amount.\n");
            clear_input_buffer();
        }
    }
}

static void set_academic_level_from_choice(int choice, char *level) {
    switch (choice) {
        case 1: strcpy(level, "undergraduate"); break;
        case 2: strcpy(level, "diploma programs"); break;
        case 3: strcpy(level, "masters"); break;
        case 4: strcpy(level, "doctorals"); break;
        case 5: strcpy(level, "law school"); break;
        case 6: strcpy(level, "post baccalaureate"); break;
        default: strcpy(level, "unknown"); break;
    }
}

void calculate_student_finances(struct StudentFee *s) {
    if (strcmp(s->academic_level, "undergraduate") == 0 || strcmp(s->academic_level, "diploma programs") == 0) {
        s->rate_per_unit = 100.0f;
    } else if (strcmp(s->academic_level, "masters") == 0 || strcmp(s->academic_level, "law school") == 0) {
        s->rate_per_unit = 200.0f;
    } else if (strcmp(s->academic_level, "post baccalaureate") == 0) {
        s->rate_per_unit = 150.0f; 
    } else if (strcmp(s->academic_level, "doctorals") == 0) {
        s->rate_per_unit = 250.0f;
    } else {
        s->rate_per_unit = 0.0f;
    }

    s->total_payable = s->number_of_units * s->rate_per_unit;

    if (s->is_free_education) {
        s->remaining_balance = 0.0f;
        strcpy(s->status, "Paid (Free)");
    } else {
        float total_paid = 0.0f;
        for (int i = 0; i < s->payment_count; i++) {
            total_paid += s->payments[i].amount_paid;
        }

        s->remaining_balance = s->total_payable - total_paid;
        if (s->remaining_balance <= 0.001f) { // Float safe boundary protection
            s->remaining_balance = 0.0f;
            strcpy(s->status, "Fully Paid");
        } else {
            if (total_paid >= (s->total_payable * 0.50f)) {
                strcpy(s->status, "Enrolled (Partial)");
            } else {
                strcpy(s->status, "Pending Downpayment");
            }
        }
    }
}

void save_database_to_file(void) {
    FILE *file = fopen("Payment_Records.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }
    
    fprintf(file, "%d\n", student_count);
    for (int i = 0; i < student_count; i++) {
        struct StudentFee s = student_db[i];
        fprintf(file, "%s;%s;%s;%d;%f;%f;%f;%s;%s;%d;%d;%d\n",
                s.name, s.student_number, s.academic_level, s.number_of_units,
                s.rate_per_unit, s.total_payable, s.remaining_balance, s.status,
                s.student_status, s.opted_out, s.is_free_education, s.payment_count);
        
        for (int j = 0; j < s.payment_count; j++) {
            fprintf(file, "%f;%s\n", s.payments[j].amount_paid, s.payments[j].payment_date);
        }
    }
    fclose(file);
}

void load_database_from_file(void) {
    FILE *file = fopen("Payment_Records.txt", "r");
    if (file == NULL) {
        return; 
    }
    
    int logged_count = 0;
    if (fscanf(file, "%d\n", &logged_count) != 1 || logged_count < 0 || logged_count > MAX_LIMIT) {
        student_count = 0;
        fclose(file);
        return;
    }
    
    student_count = 0; 
    char line[500];

    for (int i = 0; i < logged_count && i < MAX_LIMIT; i++) {
        struct StudentFee *s = &student_db[student_count];
        
        if (fgets(line, sizeof(line), file)) {
            // Added width limits (%99[^;], %19[^;]) to prevent raw layout parsing exploits
            int tokens = sscanf(line, "%99[^;];%99[^;];%99[^;];%d;%f;%f;%f;%99[^;];%19[^;];%d;%d;%d",
                               s->name, s->student_number, s->academic_level, &s->number_of_units,
                               &s->rate_per_unit, &s->total_payable, &s->remaining_balance, s->status,
                               s->student_status, &s->opted_out, &s->is_free_education, &s->payment_count);
            
            if (tokens < 12) {
                break; 
            }
            
            int expected_payments = s->payment_count;
            s->payment_count = 0; 
            
            for (int j = 0; j < expected_payments; j++) {
                if (fgets(line, sizeof(line), file)) {
                    // Safe verification read to prevent spilling historical logs out-of-bounds
                    if (j < 10) {
                        if (sscanf(line, "%f;%19[^;\n]", &s->payments[j].amount_paid, s->payments[j].payment_date) == 2) {
                            s->payment_count++;
                        }
                    }
                }
            }
            student_count++;
        } else {
            break; 
        }
    }
    fclose(file);
}

void display_student_matrix(void) {
    if (student_count == 0) {
        printf("\nNo active session records available to display.\n");
        return;
    }

    printf("\n%-25s | %-18s | %-20s | %-6s | %-22s | %-15s | %-28s | %-18s | %-20s\n",
           "Name", "Student Number", "Academic Level", "Units", "Balance Breakdown", 
           "Total Payable", "Payment History", "Remaining Balance", "Status");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < student_count; i++) {
        struct StudentFee s = student_db[i];
        
        char breakdown[50];
        char payable_str[30];
        char remaining_str[30];
        char units_str[10];
        
        sprintf(units_str, "%d", s.number_of_units);
        sprintf(breakdown, "%d Units * PHP %.0f", s.number_of_units, s.rate_per_unit);
        sprintf(payable_str, "PHP %.2f", s.total_payable);
        sprintf(remaining_str, "PHP %.2f", s.remaining_balance);

        int lines_to_print = (s.payment_count > 0) ? s.payment_count : 1;
        for (int j = 0; j < lines_to_print; j++) {
            char history_str[50] = "";
            
            if (s.is_free_education) {
                strcpy(history_str, "Eligible for Free Education");
            } else if (s.payment_count > 0) {
                sprintf(history_str, "PHP %.2f | %s", s.payments[j].amount_paid, s.payments[j].payment_date);
            } else {
                strcpy(history_str, "No Payments");
            }

            if (j == 0) {
                printf("%-25.25s | %-18s | %-20s | %-6s | %-22s | %-15s | %-28s | %-18s | %-20s\n",
                       s.name, s.student_number, s.academic_level, units_str, 
                       breakdown, payable_str, history_str, remaining_str, s.status);
            } else {
                printf("%-25s | %-18s | %-20s | %-6s | %-22s | %-15s | %-28s | %-18s | %-20s\n",
                       "", "", "", "", "", "", history_str, "", "");
            }
        }
        printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
}

void input_students(int count_to_add) {
    int target_total = student_count + count_to_add;
    
    if (target_total > MAX_LIMIT) {
        printf("\nWarning: Allocation request out of bounds. Capping data append to max limit (%d).\n", MAX_LIMIT);
        target_total = MAX_LIMIT;
    }

    while (student_count < target_total) {
        struct StudentFee *s = &student_db[student_count];
        s->payment_count = 0;
        s->is_free_education = 0; 
        
        printf("\n--- Entering Details for Student #%d ---\n", student_count + 1);
        
        printf("Student Name (e.g., Dela Cruz, Juan M.): ");
        safe_fgets(s->name, MAX_STR);
        
        printf("Student Number (e.g., 2024-01-1672-MN-0): ");
        safe_fgets(s->student_number, MAX_STR);
        
        int level_choice = 0;
        while (level_choice < 1 || level_choice > 6) {
            printf("\nSelect Academic Level:\n");
            printf("  1 - Undergraduate\n");
            printf("  2 - Diploma Programs\n");
            printf("  3 - Masters\n");
            printf("  4 - Doctorals\n");
            printf("  5 - Law School\n");
            printf("  6 - Post Baccalaureate Degrees\n");
            level_choice = get_valid_int("Enter your choice (1-6): ");
            if (level_choice < 1 || level_choice > 6) {
                printf("Incorrect input. Choice must be between 1 and 6.\n");
            }
        }
        set_academic_level_from_choice(level_choice, s->academic_level);
        
        do {
            s->number_of_units = get_valid_int("Number of Units: ");
            if(s->number_of_units <= 0) printf("Units must be greater than zero.\n");
        } while(s->number_of_units <= 0);

        if (strcmp(s->academic_level, "undergraduate") == 0 || strcmp(s->academic_level, "diploma programs") == 0) {
            int status_choice = 0, opt_choice = 0;
            
            printf("\n--- Free Education Eligibility Validation ---\n");
            while (status_choice != 1 && status_choice != 2) {
                status_choice = get_valid_int("Select Student Status:\n  1 - Regular\n  2 - Irregular\nChoice: ");
                if (status_choice != 1 && status_choice != 2) printf("Incorrect input. Choose 1 or 2.\n");
            }
            
            while (opt_choice != 1 && opt_choice != 2) {
                opt_choice = get_valid_int("Does the student want to voluntarily opt-out of Free Education?\n  1 - Yes (Will become a Paying Student)\n  2 - No\nChoice: ");
                if (opt_choice != 1 && opt_choice != 2) printf("Incorrect input. Choose 1 or 2.\n");
            }

            if (status_choice == 1 && opt_choice == 2) {
                s->is_free_education = 1;
                strcpy(s->student_status, "Regular");
                s->opted_out = 0;
                printf("\n>>> Validation Passed: Eligible for Free Education. Total Balance auto-set to PHP 0.00.\n");
            } else {
                s->is_free_education = 0;
                strcpy(s->student_status, (status_choice == 1) ? "Regular" : "Irregular");
                s->opted_out = (opt_choice == 1) ? 1 : 0;
                printf("\n>>> Validation Ended: Classified as a PAYING individual.\n");
            }
        } else {
            s->is_free_education = 0;
            strcpy(s->student_status, "N/A");
            s->opted_out = 0;
        }

        calculate_student_finances(s);
        printf("\n======================================================\n");
        printf("  INITIAL STATEMENT OF ACCOUNT\n");
        printf("  Base Rate/Unit: PHP %.2f\n", s->rate_per_unit);
        printf("  Total Calculated Tuition: PHP %.2f\n", s->total_payable);
        if (!s->is_free_education) {
            printf("  * Reminder: Pay minimum 50%% (PHP %.2f) to enroll for the semester.\n", s->total_payable * 0.50f);
        }
        printf("======================================================\n");

        if (!s->is_free_education) {
            int p_count = -1;
            while (p_count < 0 || p_count > 10) {
                p_count = get_valid_int("\nHow many payment installments has this student made? ");
                if (p_count < 0 || p_count > 10) printf("Incorrect input. Please enter a value between 0 and 10.\n");
            }
            
            for (int i = 0; i < p_count; i++) {
                char prompt_buf[50];
                sprintf(prompt_buf, "  Enter payment amount #%d: PHP ", i + 1);
                
                do {
                    s->payments[i].amount_paid = get_valid_float(prompt_buf);
                    if (s->payments[i].amount_paid <= 0) printf("Payment must be greater than PHP 0.00\n");
                } while (s->payments[i].amount_paid <= 0);
                
                printf("  Enter payment date #%d (MM/DD/YY): ", i + 1);
                safe_fgets(s->payments[i].payment_date, 20);
                
                s->payment_count++;
            }
        }
        
        calculate_student_finances(s);
        student_count++;
    }
    save_database_to_file();
    printf("\nRecords successfully processed and saved to Payment_Records.txt.\n");
}

void clear_all_records(void){
    FILE *file = fopen("Payment_Records.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    } else {
        fprintf(file, "0\n"); // Standardize baseline metadata line
        student_count = 0; 
        printf("Successfully deleted all data, you may add data now.\n");
        fclose(file);
    }
}

void search_records(void) {
    char search_target[MAX_STR];
    int found = 0;

    if (student_count == 0) {
        printf("\nNo active student records available to search inside this session.\n");
        return;
    }

    printf("\nEnter Student Number or Name to search: ");
    safe_fgets(search_target, MAX_STR);

    printf("\n=================== SEARCH RESULTS ===================\n");
    for (int i = 0; i < student_count; i++) {
        if (contains_case_insensitive(student_db[i].student_number, search_target) ||
            contains_case_insensitive(student_db[i].name, search_target)) {
            
            struct StudentFee s = student_db[i];
            printf("Name: %s\n", s.name);
            printf("Student Number: %s\n", s.student_number);
            printf("Academic Level: %s\n", s.academic_level);
            printf("Units Enrolled: %d\n", s.number_of_units);
            printf("Total Payable: PHP %.2f\n", s.total_payable);
            printf("Remaining Balance: PHP %.2f\n", s.remaining_balance);
            printf("Status: %s\n", s.status);
            
            if (s.is_free_education) {
                printf("Payment History Breakdown:\n  -> Eligible for Free Education\n");
            } else if (s.payment_count > 0) {
                printf("Payment History Breakdown:\n");
                for (int j = 0; j < s.payment_count; j++) {
                    printf("  -> Installment #%d: PHP %.2f on %s\n", j + 1, s.payments[j].amount_paid, s.payments[j].payment_date);
                }
            } else {
                printf("Payment History Breakdown:\n  -> No Payments Recorded\n");
            }
            printf("------------------------------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No existing student matching '%s' found.\n", search_target);
    }
    printf("======================================================\n");
}

void update_records(void) {
    char target_id[MAX_STR];
    int found = 0;

    if (student_count == 0) {
        printf("\nNo records available to update.\n");
        return;
    }

    printf("\nEnter the Student Number of the record you want to modify: ");
    safe_fgets(target_id, MAX_STR);

    for (int i = 0; i < student_count; i++) {
        if (strcmp(student_db[i].student_number, target_id) == 0) {
            found = 1;
            struct StudentFee *s = &student_db[i];
            
            printf("\nRecord Located for %s [%s]\n", s->name, s->academic_level);
            printf("1. Modify Enrolled Units\n");
            printf("2. Append a New Payment Entry\n");
            int modify_choice = get_valid_int("Enter update path choice (1-2): ");

            if (modify_choice == 1) {
                int new_units = 0;
                do {
                    new_units = get_valid_int("Enter new total units: ");
                    if (new_units <= 0) printf("Units must be greater than zero.\n");
                } while (new_units <= 0);
                
                s->number_of_units = new_units;
                calculate_student_finances(s);
                printf("\nUnits updated successfully! New tuition is PHP %.2f\n", s->total_payable);
            } 
            else if (modify_choice == 2) {
                if (s->is_free_education) {
                    printf("\nThis student has Free Education access. Adding transactions is restricted.\n");
                } else if (s->payment_count >= 10) {
                    printf("\nPayment ledger full (Max 10 entries reached).\n");
                } else {
                    int next_idx = s->payment_count;
                    float new_pay = 0;
                    do {
                        new_pay = get_valid_float("Enter new installment amount: PHP ");
                        if (new_pay <= 0) printf("Payment must be greater than PHP 0.00\n");
                    } while (new_pay <= 0);
                    
                    s->payments[next_idx].amount_paid = new_pay;
                    printf("Enter payment date (MM/DD/YY): ");
                    safe_fgets(s->payments[next_idx].payment_date, 20);
                    
                    s->payment_count++;
                    calculate_student_finances(s);
                    printf("\nPayment entry processed smoothly! Remaining balance: PHP %.2f\n", s->remaining_balance);
                }
            } else {
                printf("\nIncorrect choice path selected. Aborting file mutations.\n");
                return;
            }
            
            save_database_to_file();
            printf("System text database synchronized successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("\nError: Student ID '%s' not registered in current ledger.\n", target_id);
    }
}

int main(void) {
    char choice;
    
    load_database_from_file();
    
    printf("=============================================\n");
    printf("    UNIVERSITY STUDENT FEE LEDGER SYSTEM\n");
    printf("=============================================\n");
    printf("\nWelcome, what do you want to do today?\n");
    
    do {
        printf("\nPlease Enter from the choices below: \n\n");
        printf("1. Add Records.\n");
        printf("2. Search for student record.\n");
        printf("3. Update student records.\n");
        printf("4. Erase all records.\n");
        printf("5. View all existing records.\n");
        printf("6. Exit the records.\n");
        printf("Enter your choice: ");
        
        if (scanf(" %c", &choice) != 1) {
            choice = '\0';
        }
        printf("----------------------------------------------\n");
        clear_input_buffer(); 

        switch (choice) {
            case '1': {
                printf("\nAdding new student records.\n");
                int requested_students = 0;
                do {
                    requested_students = get_valid_int("How many students do you want to add? ");
                    if (requested_students <= 0) {
                        printf("Please enter a positive number of students.\n");
                    } else if (student_count + requested_students > MAX_LIMIT) {
                        printf("The requested amount exceeds the maximum allowed records (%d).\n", MAX_LIMIT);
                    }
                } while (requested_students <= 0 || student_count + requested_students > MAX_LIMIT);
                input_students(requested_students);
                break;
            }
            case '2':
                search_records();
                break;
            case '3':
                update_records();
                break;
            case '4':
                clear_all_records();
                break;
            case '5':
                display_student_matrix();
                break;
            case '6':
                printf("Thank you, your records are safe for record keeping.\n");
                break;
            default:
                printf("\nIncorrect choice. Please try again.\n");
                break;
        }
    } while (choice != '6');
    
    printf("Thank you, have a nice day.\n");
    return 0;
}