#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
void appendRecord(char file[][50], int *numRecords) {
    if (*numRecords < MAX_RECORDS) {
        printf("Enter the record: ");
        scanf("%s", file[*numRecords]);
        (*numRecords)++;
        printf("Record added successfully.\n");
    } else {
        printf("File is full. Cannot add more records.\n");
    }
}
void readAllRecords(char file[][50], int numRecords) {
    printf("Contents of the file:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%s\n", file[i]);
    }
}

int main() {
    char file[MAX_RECORDS][50];
    int numRecords = 0;
    int choice;

    while (1) {
        printf("\nFile Allocation Strategy Simulation\n");
        printf("1. Append a record\n");
        printf("2. Read all records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                appendRecord(file, &numRecords);
                break;
            case 2:
                readAllRecords(file, numRecords);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

