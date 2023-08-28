#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file_or_directory>\n", argv[0]);
    return 1;
  }

  // Try to remove as file
  int status = remove(argv[1]);

  // If failed, try to remove as directory
  if (status != 0) {
    status = rmdir(argv[1]);
  }

  if (status != 0) {
    perror("Error deleting");
    return 1;
  }

  return 0;
}
