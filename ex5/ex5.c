// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define MSGSIZE 16

char *msg1 = "hello world #1\n";
char *msg2 = "hello world #2\n";
char *msg3 = "hello world #3\n";

int main(void) {
  // Your code here
  char inbuf[MSGSIZE];
  int p[2];
  pipe(p);
  int rc = fork();
  if (rc == 0) {
    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);
  } else {
    for (int i = 0; i < 3; i++) {
      read(p[0], inbuf, MSGSIZE);
      printf("%s", inbuf);
    }
  }
  return 0;
}
