#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "headers.h"


int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  while (true) {
    // Uncomment this block to pass the first stage
    printf("$ ");
    // Wait for user input
    char input[100];
    fgets(input, 100, stdin);
    int end = strcspn(input, "\r\n");
    input[end] = '\0';
    int status = handleExit(strdup(input));
    if ( status >= 0) {
      exit(status);
    }
    printf("%s: command not found\n", input);
  }
  return 0;
}
