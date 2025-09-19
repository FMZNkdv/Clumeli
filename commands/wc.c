#include <stdio.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: wc <file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    int lines = 0, words = 0, chars = 0;
    char c, prev = ' ';

    while ((c = fgetc(file)) != EOF) {
        chars++;
        if (c == '\n') lines++;
        if (prev == ' ' || prev == '\n') {
            if (c != ' ' && c != '\n') words++;
        }
        prev = c;
    }

    fclose(file);
    printf("%d %d %d %s\n", lines, words, chars, argv[1]);
    return 0;
}
