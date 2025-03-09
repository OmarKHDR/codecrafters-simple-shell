#include "headers.h"
#include <sys/wait.h>

void execute(char * command, char *path){
    char *args[100];  // Array to hold command arguments
    int i = 0;
    char *token = strtok(command, " ");
    while (token != NULL && i < 99) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    execvp(path, args);
    perror("execvp failed");
    exit(1);
}


int compare_and_execute(char *str) {
	char *token = strtok(strdup(str), " ");
	if(token) {
		Command *command = get_command(token);
		if (command) {
			command->func(str);
		} else {
			char *path = find_path(token);
			if (path) {
				int pid = fork();
				if (pid == 0) {
					execute(str, path);
				} else if (pid < 0) {
					printf("failure\n");
				} else if (pid > 0) {
					wait(NULL);
				}
			} else {
				printf("%s: command not found\n", token);
			}
		}
	}
	return 0;
}