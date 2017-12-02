#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *read_input() {
  printf("Input: ");
  char *in;
  fgets(in, 256, stdin); // 256 bytes
  return in;
}

char **parse_args(char *line) {
  // removing last newline character
  char lineCopy[strlen(line)];
  strcpy(lineCopy, line);
  lineCopy[strlen(lineCopy) - 1] = 0;

  // counting # of args
  char *line1 = lineCopy;
  int numArgs = 0;
  while(line1) {
    strsep(&line1, " ");
    numArgs++;
  }
  // printf("numArgs: %d\n", numArgs);

  // separating line into argument array
  char **arguments = malloc(numArgs * sizeof(char *));
  int i = 0;
  while(line) {
    arguments[i] = strsep(&line, " ");
    i++;
  }
  return arguments;
}

char **inputToArgs() {
  char *input = read_input();
  return parse_args(input);
}

int main() {
  char **args = inputToArgs();
  printf("args[0]: [%s]\n", args[2]);

  return 0;
}