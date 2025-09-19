#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: mkdir <directory>\n");
        return 1;
    }

    if (mkdir(argv[1], 0777) == 0) {
        printf("Directory created: %s\n", argv[1]);
    } else {
        printf("Error creating directory: %s\n", argv[1]);
        return 1;
    }

    return 0;
}
