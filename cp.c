#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char contents[1024];
  int fd_read, fd_write;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
    exit(1);
  }

  fd_read = open(argv[1], O_RDONLY);
  if (fd_read == -1) {
    perror("open input file");
    exit(1);
  }

  fd_write = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0744);
  if (fd_write == -1) {
    perror("open output file");
    exit(1);
  }

  int n_read;
  while ((n_read = read(fd_read, contents, sizeof(contents))) > 0) {
    write(fd_write, contents, n_read);
  }

  if (n_read == -1) {
    perror("read error");
    exit(1);
  }

  close(fd_read);
  close(fd_write);

  return 0;
}
