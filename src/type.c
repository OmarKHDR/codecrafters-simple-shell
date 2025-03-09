#include "headers.h"

void my_type(char *name) {
	char *str = strchr(strdup(name), ' ');
	if (str) {
		str = strtok(strdup(str), " ");
		if (!str) return;
		Command *command = (Command *) malloc(sizeof(Command *));
		command = get_command(str);
		if(command) {
			printf("%s\n", command->info);
			return;
		} 
		char *result = find_path(str);
		if (result) {
			printf("%s is %s\n", str, result);
			return;
		} else {
			printf("%s: not found\n", str);
		}
	}
}

char *find_path(char *str) {
	char *path = strdup(getenv("PATH"));
	char *token = strtok(path, ":");
	while(token) {
		int len = strlen(token) + strlen(str) + 2;
		char *try = malloc(sizeof(char) * len);
		snprintf(try, len, "%s/%s", token, str);
		if (!access(try, X_OK)) {
			free(path);
			return try;
		}
		free(try);
		token = strtok(NULL, ":");
	}
	free(path);
	return NULL;
}