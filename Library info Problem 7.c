#include <stdio.h>
#include <conio.h>
#include <string.h>

// Collecting information about a book and its borrower and the date of borrowing and returning the book, and calculating the penalty if the book is returned late.
struct book_and_borrower_info {
    char book_title[30];
    char book_author[30];
    char ISBN[10];
    char borrower_name[30];
    int date_borrowed;
    int date_returned;
    int penalty_days;
};
// Function to collect information about the book and its borrower
void collect_info(struct book_and_borrower_info *info) {
    printf("Enter the book title: ");
    fgets(info->book_title, sizeof(info->book_title), stdin);
    info->book_title[strcspn(info->book_title, "\n")] = '\0';

    printf("Enter the book author: ");
    fgets(info->book_author, sizeof(info->book_author), stdin);
    info->book_author[strcspn(info->book_author, "\n")] = '\0';

    printf("Enter the ISBN: ");
    fgets(info->ISBN, sizeof(info->ISBN), stdin);
    info->ISBN[strcspn(info->ISBN, "\n")] = '\0';

    printf("Enter the borrower name: ");
    fgets(info->borrower_name, sizeof(info->borrower_name), stdin);
    info->borrower_name[strcspn(info->borrower_name, "\n")] = '\0';

    printf("Enter the day number when the book was borrowed: ");
    printf("\nPlease use this format when entering the date YYYYMMDD (e.g., 20240101 for January 1, 2024): ");
    scanf("%d", &info->date_borrowed);
    printf("Enter the day number when the book was returned: ");
    printf("\nPlease use this format when entering the date YYYYMMDD (e.g., 20240108 for January 8, 2024): ");
    scanf("%d", &info->date_returned);
    while (getchar() != '\n');

    info->penalty_days = 7;
}
// Function to calculate the penalty for late return of the book
float calculate_penalty(struct book_and_borrower_info info) {
    float penalty = 0;
    if (info.date_returned > info.date_borrowed + info.penalty_days) {
        // Penalty for late return is 10.00 pesos per day beyond the penalty days which is 7 days
        penalty = (float)(info.date_returned - (info.date_borrowed + info.penalty_days)) * 10.00; 
    }
    return penalty;
}
float display_penalty(float penalty, char *borrower_name) {
    if (penalty > 0) {
        printf("%s, you have a penalty for late return: %.2f pesos\n", borrower_name, penalty);
        printf("Please pay the penalty to the library before borrowing another book.\n");
    } else {
        printf("%s, no penalty for late return.\n", borrower_name);
        printf("Thank you for returning the book on time, keep it up!\n");  
    }
    return penalty;
}

// Function to display all book and borrower information
void display_info(struct book_and_borrower_info info) {
    printf("\n--- Book and Borrower Information ---\n");
    printf("Book Title: %s\n", info.book_title);
    printf("Book Author: %s\n", info.book_author);
    printf("ISBN: %s\n", info.ISBN);
    printf("Borrower Name: %s\n", info.borrower_name);
    printf("Date Borrowed: %d\n", info.date_borrowed);
    printf("Date Returned: %d\n", info.date_returned);
}
// Main function
int main() {
    char choice;
    struct book_and_borrower_info info;
    printf("\n================================================\n");
    printf("Library book borrowing system\n");
    printf("================================================\n");
    printf("Version: 1.0\n");
    printf("\n");
    printf("Welccome to the library book borrowing system. Please enter the following information:\n");
    collect_info(&info);
    float penalty = calculate_penalty(info);
    display_penalty(penalty, info.borrower_name);
    printf("Do you want to borrow another book? (Y/N): ");
    choice = getch();
    printf("\n");

    // If the user wants to borrow another book, the program will restart and collect information again. 
    // If the user does not want to borrow another book, the program will end with a goodbye message.
   
}