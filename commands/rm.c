#include <stdio.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: rm <file>\n");
        return 1;
    }

    if (remove(argv[1]) == 0) {
        printf("Removed: %s\n", argv[1]);
    } else {
        printf("Error removing: %s\n", argv[1]);
        return 1;
    }

    return 0;
}
