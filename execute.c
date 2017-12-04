#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

void change_dir(char **command) {
  if (chdir(command[1])) {
    printf("%s\n", strerror(errno));
  }
}

void exit_program() {
  kill(getpid(), SIGKILL);
}

void execute(char **command) {
  if (!strcmp(command[0], "cd")) {
    change_dir(command);
  }

  else if (!strcmp(command[0], "exit")) {
    exit_program();
  }

  else {
    int parent = fork();
    if (parent) {
      int status;
      wait(&status);
    }

    if (!parent) {
      for (int i = 0; command[i]; i++) {
        if (!strcmp(command[i], "<")) {
          int fd = open(command[i + 1], O_RDONLY);
          // printf("fd: %d\n", fd);
          dup2(fd, 0);
          command[i] = NULL;
          i++;
        }
        else if (!strcmp(command[i], ">")) {
          int fd = open(command[i + 1], O_WRONLY | O_CREAT, 0644);
          // printf("fd: %d\n", fd);
          dup2(fd, 1);
          command[i] = NULL;
          i++;
        }
      }
      if (execvp(command[0], command)) {
        printf("%s\n", strerror(errno));
        exit(EXIT_FAILURE);
      }
    }
  }
}


/*
int main() {
  execute(read_input());
  return 0;
}
*/