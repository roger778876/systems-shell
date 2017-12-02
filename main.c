#include <stdio.h>
#include <stdlib.h>
#include "input.c"
#include "execute.c"

int main() {
  execute(read_input());
  
  return 0;
}