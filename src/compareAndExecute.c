#include "headers.h"


int compare_and_execute(char *str) {
	char *token = strtok(strdup(str), " ");
	if(token) {
		Command *command = (Command *) malloc(sizeof(Command *));
		command = get_command(token);
		if (command) {
			command->func(str);
		} else {
			printf("%s: command not found\n", token);
		}
	}

	return 0;
}