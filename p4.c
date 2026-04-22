#include <stdio.h>
#include <string.h>

int main() {
    int choice, i, n, key, found = 0;
    int arr[50], temp;
    char str1[100], str2[100];

    do {
        printf("\n----- MAIN MENU -----\n");
        printf("1. Sort Array\n");
        printf("2. Search in Array\n");
        printf("3. Concatenate Strings\n");
        printf("4. Compare Strings\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // SORT ARRAY
            case 1:
                printf("Enter size of array: ");
                scanf("%d", &n);

                printf("Enter elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }

                // Bubble sort
                for (i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }

                printf("Sorted Array: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            // SEARCH ARRAY
            case 2:
                printf("Enter size of array: ");
                scanf("%d", &n);

                printf("Enter elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }

                printf("Enter element to search: ");
                scanf("%d", &key);

                found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == key) {
                        found = 1;
                        break;
                    }
                }

                if (found)
                    printf("Element found at position %d\n", i + 1);
                else
                    printf("Element not found\n");
                break;

            // CONCATENATION
            case 3:
                printf("Enter first string: ");
                scanf("%s", str1);

                printf("Enter second string: ");
                scanf("%s", str2);

                strcat(str1, str2);

                printf("Concatenated String: %s\n", str1);
                break;

            // COMPARE STRINGS
            case 4:
                printf("Enter first string: ");
                scanf("%s", str1);

                printf("Enter second string: ");
                scanf("%s", str2);

                if (strcmp(str1, str2) == 0)
                    printf("Strings are equal\n");
                else
                    printf("Strings are not equal\n");
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
