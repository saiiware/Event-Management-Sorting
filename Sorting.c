#include <stdio.h>
#include <string.h>

struct Events {
    char name[50];
    int no_of_guests;
    char month[30];
    int date;
    char timing[10];
    char contact_no[30];
    char full_date[50];
};


int getMonthNumber(const char *month) {
    if (strcasecmp(month, "January") == 0) return 1;
    if (strcasecmp(month, "February") == 0) return 2;
    if (strcasecmp(month, "March") == 0) return 3;
    if (strcasecmp(month, "April") == 0) return 4;
    if (strcasecmp(month, "May") == 0) return 5;
    if (strcasecmp(month, "June") == 0) return 6;
    if (strcasecmp(month, "July") == 0) return 7;
    if (strcasecmp(month, "August") == 0) return 8;
    if (strcasecmp(month, "September") == 0) return 9;
    if (strcasecmp(month, "October") == 0) return 10;
    if (strcasecmp(month, "November") == 0) return 11;
    if (strcasecmp(month, "December") == 0) return 12;
    return 0; 
}

int main() {
    int i, j;
    struct Events reservation[5];  
    struct Events temp;

    
    for (i = 0; i < 5; i++) {
        printf("\n------- Reservation %d -------\n", i + 1);

        printf("Enter Name: ");
        fgets(reservation[i].name, sizeof(reservation[i].name), stdin);
        reservation[i].name[strcspn(reservation[i].name, "\n")] = '\0';

        printf("Enter Contact number: ");
        fgets(reservation[i].contact_no, sizeof(reservation[i].contact_no), stdin);
        reservation[i].contact_no[strcspn(reservation[i].contact_no, "\n")] = '\0';

        printf("Enter No. Of Guests: ");
        scanf("%d", &reservation[i].no_of_guests);
        getchar();

        printf("Enter Month: ");
        fgets(reservation[i].month, sizeof(reservation[i].month), stdin);
        reservation[i].month[strcspn(reservation[i].month, "\n")] = '\0';

        printf("Enter Date: ");
        scanf("%d", &reservation[i].date);
        getchar();

        printf("Enter 'Time-Slot' for the event: ");
        fgets(reservation[i].timing, sizeof(reservation[i].timing), stdin);
        reservation[i].timing[strcspn(reservation[i].timing, "\n")] = '\0';

       
        char date_str[10];
        sprintf(date_str, "%d", reservation[i].date);
        strcpy(reservation[i].full_date, date_str);
        strcat(reservation[i].full_date, " ");
        strcat(reservation[i].full_date, reservation[i].month);
    }

    
    for (i = 0; i < 5 - 1; i++) {
        for (j = 0; j < 5 - i - 1; j++) {
            int monthA = getMonthNumber(reservation[j].month);
            int monthB = getMonthNumber(reservation[j + 1].month);

            if (monthA > monthB ||
                (monthA == monthB && reservation[j].date > reservation[j + 1].date)) {
                temp = reservation[j];
                reservation[j] = reservation[j + 1];
                reservation[j + 1] = temp;
            }
        }
    }


    printf("\n\n======== Reservation Details (Sorted by Month & Date) ========\n");
    for (i = 0; i < 5; i++) {
        printf("\nReservation %d:\n", i + 1);
        printf("Name: %s\n", reservation[i].name);
        printf("Contact No: %s\n", reservation[i].contact_no);
        printf("No. Of Guests: %d\n", reservation[i].no_of_guests);
        printf("Date: %s\n", reservation[i].full_date);
        printf("Time Slot: %s\n", reservation[i].timing);
    }

    return 0;
}
