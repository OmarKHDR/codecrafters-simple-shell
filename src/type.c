#include "headers.h"

void my_type(char *name) {
	char *str = strchr(strdup(name), ' ');
	str = strtok(strdup(str), " ");
	if (str) {
		Command *command = (Command *) malloc(sizeof(Command *));
		command = get_command(str);
		if(command) {
			printf("%s\n", command->info);
		} else {
			char *path = strdup(getenv("PATH"));
			char *token = strtok(strdup(path), ":");
			while(token) {
				char *try = strcat(strdup(token),strcat(strdup("/"), str));
				if (!access(try, X_OK)) {
					printf("%s is %s\n", str, try);
					return;
				}
				//printf("%s ------failed\n", try);
				token = strtok(NULL, ":");
			}
			printf("%s: not found\n", str);
		}
	}
}