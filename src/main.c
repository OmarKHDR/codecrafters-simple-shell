#include "headers.h"


int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
  register_commands();
  while (true) {
    // Uncomment this block to pass the first stage
    printf("$ ");
    // Wait for user input
    char input[100];
    fgets(input, 100, stdin);
    int end = strcspn(input, "\r\n");
    input[end] = '\0';
    compare_and_execute(strdup(input));
  }
  return 0;
}
