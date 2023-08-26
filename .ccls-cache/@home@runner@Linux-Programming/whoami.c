#include <stdio.h>
#include <unistd.h>

int main() {
  char *username;

  // Get the username of the current user
  username = getlogin();
  if (username == NULL) {
    perror("Error getting username");
    return 1;
  }

  // Print the username
  printf("%s\n", username);

  return 0;
}
