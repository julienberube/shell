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
  if (*in_str == *"") {
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
  char *split[spaces + 1];
  while (p != NULL) {
    split[i++] = p;
    p = strtok(NULL, " ");
  }
}
int hash_str(char *str) {
  int hash = 0;
  for (int i = 0; i < strlen(str); i++) {
    hash += (i + 1) * (int)(*(str + i));
    printf("%i\n", hash);
  }
  return hash;
}

