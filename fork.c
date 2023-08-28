#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// The fork() function is called, which creates a new process by duplicating the
// existing process. The return value of fork() is stored in pid.

// The fork() function returns different values in the parent and child
// processes. In the parent process, the return value is the process ID of the
// child process. In the child process, the return value is 0.

int main() {
  pid_t pid;

  // Fork the current process
  pid = fork();

  // Check if fork was successful
  if (pid < 0) {
    fprintf(stderr, "Fork failed\n");
    return 1;
  } else if (pid == 0) {
    // Child process
    printf("Hello from child process!\n");
    printf("Child Process ID: %d\n", getpid());
  } else {
    // Parent process
    printf("Hello from parent process!\n");
    printf("Parent Process ID: %d\n", getpid());
    printf("Child Process ID: %d\n", pid);
  }

  return 0;
}