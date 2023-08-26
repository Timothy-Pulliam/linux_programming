#include <stdio.h>
#include <unistd.h>

#define MAX_PATH 1024

int main() {
  char buffer[MAX_PATH];

  // Get the current working directory
  if (getcwd(buffer, sizeof(buffer)) == NULL) {
    perror("Error getting current working directory");
    return 1;
  }

  // Print the current working directory
  printf("%s\n", buffer);

  return 0;
}