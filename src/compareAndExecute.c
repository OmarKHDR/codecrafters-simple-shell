#include "headers.h"


int compare_and_execute(char *command) {
	char *token = strtok(strdup(command), " ");
	if (!strcmp(token, "exit")) {
		token = strtok(NULL, " ");
		my_exit(token);
	} else if (!strcmp(token, "echo")) {
		token = strtok(NULL, " ");
		my_echo(strdup(command));
	} else {
		printf("%s: command not found\n", command);
	}

	return 0;
}