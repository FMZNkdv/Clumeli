#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: kill <pid>\n");
        return 1;
    }

    printf("Process %s killed\n", argv[1]);
    return 0;
}
