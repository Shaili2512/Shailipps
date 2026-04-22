#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("File not found!\n");
        return 0;
    }

    // Move to end of file
    fseek(fp, 0, SEEK_END);

    // Get last position
    int pos = ftell(fp);

    // Read file in reverse
    while (pos >= 0) {
        fseek(fp, pos, SEEK_SET);
        ch = fgetc(fp);
        printf("%c", ch);
        pos--;
    }

    fclose(fp);
    return 0;
}
