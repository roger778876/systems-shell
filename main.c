#include <stdio.h>
#include <stdlib.h>
#include "execute.c"

int main() {
  while (1) {
    struct cmds_array commands = read_input();
    int num_cmds = commands.num_cmds;
    int i = 0;
    while (num_cmds) {
      execute(commands.cmds[i]);
      num_cmds--;
      i++;
    }
  }
  
  return 0;
}