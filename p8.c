#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp, *fodd, *feven;
    int num;

    fp = fopen("data.txt", "r");
    fodd = fopen("odd.txt", "w");
    feven = fopen("even.txt", "w");

    // Check all files
    if (fp == NULL || fodd == NULL || feven == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Separate numbers
    while (fscanf(fp, "%d", &num) != EOF) {
        if (num % 2 == 0)
            fprintf(feven, "%d ", num);
        else
            fprintf(fodd, "%d ", num);
    }

    fclose(fp);
    fclose(fodd);
    fclose(feven);

    // Display odd numbers
    printf("\nOdd numbers:\n");
    fodd = fopen("odd.txt", "r");
    while (fscanf(fodd, "%d", &num) != EOF) {
        printf("%d ", num);
    }
    fclose(fodd);

    // Display even numbers
    printf("\nEven numbers:\n");
    feven = fopen("even.txt", "r");
    while (fscanf(feven, "%d", &num) != EOF) {
        printf("%d ", num);
    }
    fclose(feven);

    return 0;
}
