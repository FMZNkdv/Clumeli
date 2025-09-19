#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: sort <file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char lines[MAX_LINES][MAX_LENGTH];
    int count = 0;

    while (fgets(lines[count], MAX_LENGTH, file) && count < MAX_LINES) {
        count++;
    }

    fclose(file);

    // Простая сортировка пузырьком
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(lines[i], lines[j]) > 0) {
                char temp[MAX_LENGTH];
                strcpy(temp, lines[i]);
                strcpy(lines[i], lines[j]);
                strcpy(lines[j], temp);
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s", lines[i]);
    }

    return 0;
}
