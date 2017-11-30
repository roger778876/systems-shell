#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char **parse_args(char *line) {
  int counter = 0;
  char line2[100];
  strcpy(line2, line);
  while (line){
    strsep(&line, " ");
    counter++;
  }
  printf("%d\n", counter);
  char **arguments = malloc(counter * sizeof(char *));
  int i = 0;
  char *line3 = line2;
  printf("line3: %s\n", line3 + 4);
  while(line3) {
    arguments[i] = strsep(&line3, " ");
    i++;
  }
  return arguments;
}

int main() {
  char *line;
  fgets(line, 256, stdin);
  char **args = parse_args(line);
  printf("Running '%s'\n", line);
  printf("[%s]\n", args[0]);

  return 0;
}
