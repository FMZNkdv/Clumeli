#include <stdio.h>
#include <dirent.h>
#include <string.h>

void find_files(const char* dirname, const char* pattern) {
    DIR *dir = opendir(dirname);
    if (dir == NULL) return;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        if (strstr(entry->d_name, pattern) != NULL) {
            printf("%s/%s\n", dirname, entry->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: find <directory> <pattern>\n");
        return 1;
    }

    find_files(argv[1], argv[2]);
    return 0;
}
