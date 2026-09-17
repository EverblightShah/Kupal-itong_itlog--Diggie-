#include <stdio.h>
#include <string.h>

#define MAX 50
#define ALLOWED_DAYS 7
#define FINE_PER_DAY 10.00

int isLeapYear(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return 1;
    return 0;
}

int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        return 29;

    return days[month - 1];
}

int isValidDate(int month, int day, int year) {
    if (year < 1900 || year > 2100)
        return 0;

    if (month < 1 || month > 12)
        return 0;

    if (day < 1 || day > daysInMonth(month, year))
        return 0;

    return 1;
}

int getDateValue(int month, int day, int year) {
    int totalDays = 0;
    int y, m;

    for (y = 1900; y < year; y++) {
        if (isLeapYear(y))
            totalDays += 366;
        else
            totalDays += 365;
    }

    for (m = 1; m < month; m++) {
        totalDays += daysInMonth(m, year);
    }

    totalDays += day;

    return totalDays;
}

void inputDate(char label[], int *month, int *day, int *year) {
    char date[20];
    int valid;

    do {
        valid = 1;

        printf("Enter %s, month/day/year: ", label);
        scanf(" %[^\n]", date);

        if (sscanf(date, "%d/%d/%d", month, day, year) != 3) {
            printf("Invalid format. Please use month/day/year.\n");
            valid = 0;
        } else if (!isValidDate(*month, *day, *year)) {
            printf("Invalid date. Please enter a correct date.\n");
            valid = 0;
        }

    } while (!valid);
}

int main() {
    char choice;
    char borrower[MAX][50];
    char isbn[MAX][30];
    char title[MAX][50];
    char author[MAX][50];

    int borrowedMonth[MAX], borrowedDay[MAX], borrowedYear[MAX];
    int returnedMonth[MAX], returnedDay[MAX], returnedYear[MAX];

    int n, i;
    int borrowedValue, returnedValue;
    int daysBorrowed, lateDays;
    float fine[MAX];

    printf("===== Library Borrowing System =====\n\n");

    printf("Enter number of borrowing records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nRecord %d\n", i + 1);

        printf("Enter Name of Borrower: ");
        scanf(" %[^\n]", borrower[i]);

        printf("Enter ISBN: ");
        scanf(" %[^\n]", isbn[i]);

        printf("Enter Book Title: ");
        scanf(" %[^\n]", title[i]);

        printf("Enter Book Author(s): ");
        scanf(" %[^\n]", author[i]);

        inputDate("Date Borrowed", &borrowedMonth[i], &borrowedDay[i], &borrowedYear[i]);
        inputDate("Date Returned", &returnedMonth[i], &returnedDay[i], &returnedYear[i]);

        borrowedValue = getDateValue(borrowedMonth[i], borrowedDay[i], borrowedYear[i]);
        returnedValue = getDateValue(returnedMonth[i], returnedDay[i], returnedYear[i]);

        while (returnedValue < borrowedValue) {
            printf("Error: Date returned cannot be earlier than date borrowed.\n");
            inputDate("Date Returned", &returnedMonth[i], &returnedDay[i], &returnedYear[i]);
            returnedValue = getDateValue(returnedMonth[i], returnedDay[i], returnedYear[i]);
        }

        daysBorrowed = returnedValue - borrowedValue;

        if (daysBorrowed > ALLOWED_DAYS) {
            lateDays = daysBorrowed - ALLOWED_DAYS;
            fine[i] = lateDays * FINE_PER_DAY;
        } else {
            fine[i] = 0.00;
        }
    }

    printf("\n\n");
    printf("========================================================================================================================\n");
    printf("                                                   ABC Library                                                          \n");
    printf("                                                   Weekly Report                                                        \n");
    printf("========================================================================================================================\n");

    printf("%-20s %-15s %-25s %-20s %-15s %-15s %-10s\n",
           "Name of Borrower",
           "ISBN",
           "Book Title",
           "Book Author(s)",
           "Date Borrowed",
           "Date Returned",
           "Fine");

    printf("------------------------------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        char borrowedDate[20];
        char returnedDate[20];

        sprintf(borrowedDate, "%d/%d/%d", borrowedMonth[i], borrowedDay[i], borrowedYear[i]);
        sprintf(returnedDate, "%d/%d/%d", returnedMonth[i], returnedDay[i], returnedYear[i]);

        printf("%-20s %-15s %-25s %-20s %-15s %-15s %.2f\n",
               borrower[i],
               isbn[i],
               title[i],
               author[i],
               borrowedDate,
               returnedDate,
               fine[i]);
    }

    printf("------------------------------------------------------------------------------------------------------------------------\n");
    while (choice == 'Y' || choice == 'y') {
        main();
        printf("Do you want to borrow another book? (Y/N): ");
        scanf(" %c", &choice);
        printf("\n");
    }
    if (choice == 'N' || choice == 'n') {
        printf("Thank you for using the library book borrowing system. Goodbye!\n");
    }
    return 0;

    return 0;
}
// Compose
// Write to COMROG 2 - Group 12
// Library book borrowing system
