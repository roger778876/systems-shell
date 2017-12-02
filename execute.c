#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "input.c"

void execute(char **command) {
  int parent = fork();
  if (parent) {
    int status;
    wait(&status);
    printf("Parent done!\n");
  }

  if (!parent) {
    execvp(command[0], command);
  }
}

int main() {
  execute(read_input());

  return 0;
}