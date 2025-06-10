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
int hash_str(char *str);
int execute(char* split[]);

int main() {
  printf("diddy$ ");
  char *input = "foo";
  char *exit_str = "exit";

  while (strcmp(input, "exit\n") != 0) {
    input = checkinput();

    processinput(input);
    printf("diddy$ ");
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
  } else {
    printf("bruh\n");
  }
  char *p = strtok(in_str, " ");
  int spaces = 0;
  for (int i = 0; i < strlen(in_str); i++) {
    if (*(in_str + i) == ' ') {
      spaces++;
    }
  }
  int i = 0;
  char *split[spaces];
  while (p != NULL) {
    split[i++] = p;
    p = strtok(NULL, " ");
  }
  if (*(split[0] + strlen(split[0] - 1)) == '\n'){
    *(split[0] + strlen(split[0] - 1)) = '\0';  
  }
  execute(split);
}

int hash_str(char *str) {
  int hash = 0;
  for (int i = 0; i < strlen(str) - 1; i++) {
    hash += (i + 1) * (int)(*(str + i));
    printf("%i\n", hash);
  }
  return hash;
}

int execute(char* split[]) {
   
  pid_t id;
  if ((id = fork()) != 0) {
    wait(&id);
  }
  else {
    execv(split[0], NULL);
    printf("esti de bs");
    exit(0);
  }
  return 0;
}
