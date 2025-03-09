#include "headers.h"
Command *hash_table[hashsize] = {NULL};

unsigned int hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    }

    return hash % 100;  // Table size = 100
}

void insert_command(char *name, void (*func)(char *), char *info) {
	Command *command = (Command *)malloc(sizeof(Command));
	unsigned int index = hash(strdup(name));
	command->name = strdup(name);
	command->func = func;
	command->info = info;
	command->next = hash_table[index];
	hash_table[index] = command;
}

Command *get_command(char *name) {
	unsigned int index = hash(strdup(name));
	Command *mycommand = hash_table[index];
	while(mycommand && strcmp(mycommand->name, name)) {
		mycommand = mycommand->next;
	}
	return mycommand;
}
