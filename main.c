#include <fcntl.h>     // open, close (for redirection)
#include <signal.h>    // signal handling
#include <stdio.h>     // printf, fgets, etc.
#include <stdlib.h>    // malloc, free, exit
#include <string.h>    // strtok, strcmp, strcpy
#include <sys/types.h> // pid_t and other types
#include <sys/wait.h>  // wait, waitpid
#include <unistd.h>    // fork, exec, chdir, getcwd

#define SIZE_IN 50

char *checkinput();
void processinput(char *in_str);
int execute(char* split[]);

int main() {
  char *input = "foo";

  while (strcmp(input, "exit") != 0) {
    printf("HAL$ ");
    input = checkinput();

    processinput(input);
  }
}
char *checkinput() {
  char *buffer = malloc(SIZE_IN);
  fgets(buffer, SIZE_IN, stdin);

  return buffer;
}

void processinput(char *in_str) {
  if (*in_str == '\n') {
    printf("bru\n");
    return;
  } 
  in_str[strlen(in_str) - 1] = '\0';
  int spaces = 0;
  for (int i = 0; i < strlen(in_str); i++) {
    if (*(in_str + i) == ' ') {
      spaces++;
    }
  }
  char *p = strtok(in_str, " ");

  if (spaces == 0) {
    char *args[2];
    args[0] = in_str;
    args[1] = NULL;
    execute(args);
  }
  else {
    int i = 0;
    char *split[spaces];
    while (p != NULL) {
      split[i++] = p;
      p = strtok(NULL, " ");
    }
    split[i] = NULL;
    execute(split);
  }
}

int execute(char* args[]) {
  pid_t id;
  if ((id = fork()) != 0) {
    wait(&id);
  }
  else {
    execvp(args[0], args);
    exit(0); 
  } 
  return 0;
}
