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

enum commands { cd = 299, ls = 338, pwd = 650, cat = 641, gcc = 598 };
int main() {
  printf("diddy$ ");
  char *input = "foo";
  char *exit_str = "exit";

  while (strcmp(input, "exit") != 0) {
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
  switch (hash_str(split[0])) {
    case cd:
      printf("cd");
      break;
    case ls:
      printf("ls");
      break;
    case pwd:
      printf("pwd");
      break;
    case cat:
      printf("cat");
      break;
    case gcc:
      printf("gcc");
      break;
    default:
      printf("NOOOO");
      break;
  }
}
int hash_str(char *str) {
  int hash = 0;
  for (int i = 0; i < strlen(str) - 1; i++) {
    hash += (i + 1) * (int)(*(str + i));
    printf("%i\n", hash);
  }
  return hash;
}

