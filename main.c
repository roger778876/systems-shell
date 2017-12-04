#include <stdio.h>
#include <stdlib.h>
#include "input.c"
#include "execute.c"

int main() {
  while (1) {
    execute(read_input());
  }
  
  return 0;
}