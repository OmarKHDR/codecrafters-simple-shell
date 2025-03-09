#include "headers.h"
#include<unistd.h>

void my_type(char *name) {
	char *str = strchr(strdup(name), ' ');
	if (str) {
		str = strtok(strdup(str), " ");
		Command *command = (Command *) malloc(sizeof(Command *));
		command = get_command(str);
		if(command) {
			printf("%s\n", command->info);
		} else {
			printf("%s: not found\n", str);
		}
	}
}