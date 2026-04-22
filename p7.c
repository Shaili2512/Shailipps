#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int choice;
    char text[200], filename[50];

    printf("Enter file name: ");
    scanf("%s", filename);

    do {
        printf("\n--- FILE MENU ---\n");
        printf("1. Write to File\n");
        printf("2. Read File\n");
        printf("3. Append to File\n");
        printf("4. Clear File\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        switch (choice) {

            // WRITE
            case 1:
                fp = fopen(filename, "w");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    break;
                }

                printf("Enter text: ");
                fgets(text, sizeof(text), stdin);

                fputs(text, fp);
                fclose(fp);

                printf("Data written successfully!\n");
                break;

            // READ
            case 2:
                fp = fopen(filename, "r");
                if (fp == NULL) {
                    printf("File not found!\n");
                    break;
                }

                printf("File content:\n");
                while (fgets(text, sizeof(text), fp) != NULL) {
                    printf("%s", text);
                }

                fclose(fp);
                break;

            // APPEND
            case 3:
                fp = fopen(filename, "a");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    break;
                }

                printf("Enter text to append: ");
                fgets(text, sizeof(text), stdin);

                fputs(text, fp);
                fclose(fp);

                printf("Data appended successfully!\n");
                break;

            // CLEAR FILE
            case 4:
                fp = fopen(filename, "w");
                if (fp == NULL) {
                    printf("Error clearing file!\n");
                    break;
                }

                fclose(fp);
                printf("File cleared successfully!\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
