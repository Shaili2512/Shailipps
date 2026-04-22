#include <stdio.h>
#include <string.h>

#define MAX 50

struct student {
    int roll;
    char name[50];
    float marks;
};

struct student s[MAX];
int count = 0;

// Add student
void add() {
    if (count == MAX) {
        printf("Record is full!\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &s[count].roll);

    printf("Enter Name: ");
    scanf("%s", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;
    printf("Record added successfully!\n");
}

// Display students
void display() {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nRoll: %d\nName: %s\nMarks: %.2f\n",
               s[i].roll, s[i].name, s[i].marks);
    }
}

// Search student
void search() {
    int roll, found = 0;

    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("Record Found:\n");
            printf("Name: %s\nMarks: %.2f\n",
                   s[i].name, s[i].marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found!\n");
}

// Modify student
void modify() {
    int roll, found = 0;

    printf("Enter Roll No to modify: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("Enter new Name: ");
            scanf("%s", s[i].name);

            printf("Enter new Marks: ");
            scanf("%f", &s[i].marks);

            printf("Record updated!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found!\n");
}

// Delete student
void deleteRecord() {
    int roll, found = 0;

    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            for (int j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }
            count--;
            printf("Record deleted!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found!\n");
}

int main() {
    int choice;

    do {
        printf("\n--- STUDENT MENU ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Modify Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: modify(); break;
            case 5: deleteRecord(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
