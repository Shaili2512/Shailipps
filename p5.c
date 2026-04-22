#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int n = 0, newSize, choice, i;

    do {
        printf("\n--- Dynamic Array Operations ---\n");
        printf("1. Create Array (malloc)\n");
        printf("2. Add Elements\n");
        printf("3. Resize Array (realloc)\n");
        printf("4. Display Array\n");
        printf("5. Free Memory & Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // CREATE ARRAY
            case 1:
                if (arr != NULL) {
                    printf("Array already created!\n");
                    break;
                }

                printf("Enter number of elements: ");
                scanf("%d", &n);

                if (n <= 0) {
                    printf("Invalid size!\n");
                    break;
                }

                arr = (int *)malloc(n * sizeof(int));

                if (arr == NULL) {
                    printf("Memory allocation failed!\n");
                } else {
                    printf("Memory allocated successfully.\n");
                }
                break;

            // ADD ELEMENTS
            case 2:
                if (arr == NULL) {
                    printf("Create array first!\n");
                    break;
                }

                printf("Enter %d elements: ", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                break;

            // RESIZE ARRAY
            case 3:
                if (arr == NULL) {
                    printf("Create array first!\n");
                    break;
                }

                printf("Enter new size: ");
                scanf("%d", &newSize);

                if (newSize <= 0) {
                    printf("Invalid size!\n");
                    break;
                }

                int *temp = (int *)realloc(arr, newSize * sizeof(int));

                if (temp == NULL) {
                    printf("Reallocation failed!\n");
                } else {
                    arr = temp;
                    n = newSize;
                    printf("Array resized successfully.\n");
                }
                break;

            // DISPLAY ARRAY
            case 4:
                if (arr == NULL) {
                    printf("Array is empty!\n");
                    break;
                }

                printf("Array elements: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            // FREE MEMORY
            case 5:
                free(arr);
                arr = NULL;
                printf("Memory freed. Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
