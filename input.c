#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define GREEN_TEXT "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

char **read_input() {
  // getting current working directory
  char cwd[256];
  getcwd(cwd, sizeof(cwd));

  // getting input
  printf(GREEN_TEXT "%s$ " COLOR_RESET, cwd);
  char input[256];
  fgets(input, 256, stdin); // 256 bytes
  // printf("received input: [%s]\n", input);

  // creating new string array with exact size
  char lineArray[strlen(input)];
  strcpy(lineArray, input);

  // removing last newline character
  lineArray[strlen(lineArray) - 1] = 0;
  char *line = strdup(lineArray); // putting the new version into "line"
  // printf("lineArray: [%s]\n", lineArray);

  // counting # of args
  char *lineC = lineArray;
  int numArgs = 0;
  while (lineC) {
    strsep(&lineC, " ");
    numArgs++;
  }
  // printf("numArgs: %d\n", numArgs);

  // separating line into argument array
  char **arguments = malloc((numArgs + 1) * sizeof(char *)); // +1 to make room for NULL
  int i = 0;
  while (line) {
    arguments[i] = strsep(&line, " ");
    i++;
  }
  arguments[i] = 0; // ending NULL
  return arguments;
}

/*
int main() {
  char **args = read_input();
  printf("args[0]: [%s]\n", args[0]);
  printf("args[1]: [%s]\n", args[1]);
  printf("args[2]: [%s]\n", args[2]);
  return 0;
}
*/