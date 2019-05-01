// Write a program that opens the text.txt file (with the `fopen()` library
// call) located in this directory and then calls `fork()` to create a new
// process. Can both the child and parent access the file descriptor returned by
// `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *printFile(char *filename) {
  FILE *file = fopen(filename, "r");
  int c;
  while (1) {
    c = fgetc(file);
    if (feof(file)) {
      break;
    }
    printf("%c", c);
  }
  fclose(file);
}

void *writeFile(char *filename, char *input) {
  FILE *file = fopen(filename, "w");
  fputs(input, file);
  fclose(file);
}

int main(void) {
  writeFile("text.txt", "Parent Process: Print to file test 1\n");
  printFile("text.txt");
  int rc = fork();
  if (rc == 0) {
    writeFile("text.txt", "WAIT: Parent Process: Print to file after fork.\n");
  }
  if (rc > 0) {
    writeFile("text.txt", "WAIT: Child Process: Print to file after fork.\n");
  }
  printFile("text.txt");
  return 0;
}

// Inconsistent writes when done simultaneously sometimes child writes sometimes
// parent writes.