// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  // Your code here
  int rc = fork();
  if (rc == 0) {
    char *lsargs[3];
    lsargs[0] = "/bin/ls";
    lsargs[1] = "./";
    lsargs[2] = NULL;
    execvp(lsargs[0], lsargs);
  } else if (rc > 0) {
    printf("Just look at that concurrency!\n");
  }
  return 0;
}
