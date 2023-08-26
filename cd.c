#include <stdio.h>
#include <unistd.h>

// It's important to note that changing the directory using chdir() in C only
// affects the current process and does not change the directory of the parent
// shell.

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <directory>\n", argv[0]);
    return 1;
  }

  // Change the current working directory
  if (chdir(argv[1]) != 0) {
    perror("Error changing directory");
    return 1;
  }

  return 0;
}
