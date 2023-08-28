#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <utime.h>

bool touch(const char *filename) {
  int fd = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

  if (fd == -1) {
    perror("Unable to touch file");
    return false;
  }
  close(fd);

  // Update the file's timestamps
  struct utimbuf new_times;
  new_times.actime = time(NULL);  // set access time to current time
  new_times.modtime = time(NULL); // set modification time to current time

  if (utime(filename, &new_times) < 0) {
    perror("Error updating timestamps");
    return false;
  }

  return true;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
    return EXIT_FAILURE;
  }

  for (int i = 1; i < argc; i++) {
    if (!touch(argv[i])) {
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}
