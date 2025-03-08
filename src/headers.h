#ifndef MAIN
#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void my_exit(char *code_str);
void my_echo(char *str);
int handle_exit(char *code_str);
int compare_and_execute(char *command);

#endif