#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
struct student {
    int roll;
    char name[50];
    float marks;
};

// Function to add student record
void addStudent() {
    struct student s;
    FILE *fp;

    fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("File cannot be opened\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student record added successfully!\n");
}

// Function to view all student records
void viewStudents() {
    struct student s;
    FILE *fp;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No records found\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               s.roll, s.name, s.marks);
    }

    fclose(fp);
}

// Function to search student by roll number
void searchStudent() {
    struct student s;
    FILE *fp;
    int roll, found = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("File not found\n");
        return;
    }

    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("Record Found!\n");
            printf("Roll: %d | Name: %s | Marks: %.2f\n",
                   s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found\n");
    }

    fclose(fp);
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            viewStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
