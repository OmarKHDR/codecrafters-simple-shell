#ifndef MAIN
#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

#define hashsize 100

void my_exit(char *command);
void my_echo(char *command);
void my_type(char *name);
void my_pwd(char *command);


int handle_exit(char *code_str);
int compare_and_execute(char *command);

char *find_path(char *str);

typedef struct xx {
	char *name;
	void (*func)(char *c);
	char *info;
	struct xx *next;
} Command;

extern Command *hash_table[hashsize];

Command *get_command(char *name);
void insert_command(char *name, void (*func)(char *), char *info);
unsigned int hash(const char *str);
void register_commands();

#endif