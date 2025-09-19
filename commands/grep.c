#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: grep <pattern> <file>\n");
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[2]);
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, argv[1]) != NULL) {
            printf("%s", line);
        }
    }

    fclose(file);
    return 0;
}
