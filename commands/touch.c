#include <stdio.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: touch <file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "w");
    if (file == NULL) {
        printf("Error creating file: %s\n", argv[1]);
        return 1;
    }

    fclose(file);
    printf("File created: %s\n", argv[1]);
    return 0;
}
