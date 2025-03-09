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
			char *token = strtok(path, ":");
			while(token) {
				int len = strlen(token) + strlen(str) + 2;
				char *try = malloc(sizeof(char) * len);
				snprintf(try, len, "%s/%s", token, str);
				if (!access(try, X_OK)) {
					printf("%s is %s\n", str, try);
					free(try);
					free(command);
					free(path);
					return;
				}
				free(try);
				token = strtok(NULL, ":");
			}
			printf("%s: not found\n", str);
			free(command);
			free(path);
		}
	}
}