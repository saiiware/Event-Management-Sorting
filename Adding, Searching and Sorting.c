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
    int i;
    int j;
    int choice;
    int count=0;
    char searchName[50];
    int found = 0;
    struct Events reservation[5];  
    struct Events temp;
    
     while (1) {
    printf("\n-------Event Management Menu-------\n");
    printf("1. Add Event");
    printf("\n2. Search Event");
    printf("\n3. Sort Event");
    printf("\n4. Exit");
    
    printf("\nEnter Choice: ");
    scanf("%d", &choice);
    getchar();
    
    if(choice==1){
        
        if (count >= 5) {
                    printf("Event list is full. Cannot add more.\n");
                }
                
        printf("\n------- Reservation %d -------\n", count + 1);

        printf("Enter Name: ");
        fgets(reservation[count].name, sizeof(reservation[count].name), stdin);
        reservation[count].name[strcspn(reservation[count].name, "\n")] = '\0';

        printf("Enter Contact number: ");
        fgets(reservation[count].contact_no, sizeof(reservation[count].contact_no), stdin);
        reservation[count].contact_no[strcspn(reservation[count].contact_no, "\n")] = '\0';

        printf("Enter No. Of Guests: ");
        scanf("%d", &reservation[count].no_of_guests);
        getchar();
        
        printf("Enter Month: ");
        fgets(reservation[count].month, sizeof(reservation[count].month), stdin);
        reservation[count].month[strcspn(reservation[count].month, "\n")] = '\0';
        
        printf("Enter Date: ");
        scanf("%d", &reservation[count].date);
        getchar();

        printf("Enter Time Slot: ");
        fgets(reservation[count].timing, sizeof(reservation[count].timing), stdin);
        reservation[count].timing[strcspn(reservation[count].timing, "\n")] = '\0';
        
        char date_str[10];
        sprintf(date_str, "%d", reservation[count].date);
        strcpy(reservation[count].full_date, date_str);
        strcat(reservation[count].full_date, " ");
        strcat(reservation[count].full_date, reservation[count].month);
        
        printf("Event added successfully!\n");
        count++; 
        }
    
    else if(choice==2){
        
        printf("Enter Registered Name to Search:");
         fgets(searchName, sizeof(searchName), stdin);
            searchName[strcspn(searchName, "\n")] = '\0';
        
        for(i=0; i < 5; i++){
         if(strcasecmp(searchName, reservation[i].name) == 0){
              printf("\nEvent Found:\n");
              printf("Name: %s\n", reservation[i].name);
              printf("Contact No: %s\n", reservation[i].contact_no);
              printf("No. Of Guests: %d\n", reservation[i].no_of_guests);
              printf("Date: %s\n", reservation[i].full_date);
              printf("Time Slot: %s\n", reservation[i].timing);
              found=1;
         }
        }
        if (!found) printf("Event not found.\n");
    }
    
    else if(choice==3){
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
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
    printf("\n======== Sorted Reservations ========\n");
            for (i = 0; i < count; i++) {
                printf("\nReservation %d:\n", i + 1);
                printf("Name: %s\n", reservation[i].name);
                printf("Contact No: %s\n", reservation[i].contact_no);
                printf("Guests: %d\n", reservation[i].no_of_guests);
                printf("Date: %s\n", reservation[i].full_date);
                printf("Time: %s\n", reservation[i].timing);
            }
        }

        else if (choice == 4) {
            printf("Exiting program. Goodbye!\n");
        }

        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
