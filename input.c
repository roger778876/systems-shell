#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **parse_args() {
  char input[256] = "hello this is";
  char *line = input; 
  // fgets(line, 256, stdin);
  char **arguments = malloc(20 * sizeof(char *));
  int i = 0;
  while(line) {
    arguments[i] = strsep(&line, " ");
    i++;
  }
  return arguments;
}

int main() {
  char **args = parse_args();
  printf("%s\n", args[1]);

  return 0;
}
