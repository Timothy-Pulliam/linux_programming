#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *dirp;

    // Open the current directory
    dir = opendir(".");
    if (dir == NULL) {
        printf("Error: Unable to open directory.\n");
        return 1;
    }

    // Read and print all file/directory names
    while ((dirp = readdir(dir)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}
