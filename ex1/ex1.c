// Write a program that calls `fork()`. Before calling `fork()`, have the main
// process access a variable (e.g., x) and set its value to something (e.g.,
// 100). What value is the variable in the child process? What happens to the
// variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  // Your code here
  int test = 1;
  int child = fork();
  if (child == 0) {
    printf("Child Test: %d\n", test);
  }
  if (child > 0) {
    printf("Parent Test: %d\n", test);
  }
  test = 2;
  if (child == 0) {
    printf("Child Test: %d\n", test);
  }
  if (child > 0) {
    printf("Parent Test: %d\n", test);
  }
  if (child == 0) {
    test = 3;
    printf("Child Test: %d\n", test);
  }
  if (child > 0) {
    printf("Parent Test: %d\n", test);
  }
  return 0;
}

// It's the same if I only change it before it's also the same if I change it
// without a condition. If I do it with a condition it changes them seperately.