#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <utime.h>

bool touch(const char *filename) {
  int fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
  // O_CREAT: This flag is used to create the file if it doesn't exist. If the
  // file already exists, this flag has no effect.

  // O_RDWR: This flag indicates that the file should be opened in read-write
  // mode. It means that you can both read from and write to the file.

  // O_WRONLY: This flag indicates that the file should be opened in write-only
  // mode. It means that you can only write to the file and not read from it.

  // S_IRUSR: This constant specifies the read permission for the owner (user)
  // of the file. In this case, it allows the owner to read the file.

  // S_IWUSR: This constant specifies the write permission for the owner (user)
  // of the file. In this case, it allows the owner to write to the file.

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
