#include "headers.h"

void my_cd(char *command) {
	char *path = strchr(command, ' ');
	if (path) {
		path = path + 1;
		if (path) {
			char *realPath = path;
			if (path[0] == '~') {
				char *home = getenv("HOME");
				char *homedup = strdup(home);
				realPath = strdup(strcat(homedup, path+1));
			}
			if (strlen(path) >=2 && path[1] == '~') {
				char *home = getenv("HOME");
				char *homedup = strdup(home);
				realPath = strdup(strcat(homedup, path+2));
			}
			int status = chdir(realPath);
			if (status) {
				printf("cd: %s: ", realPath);
				fflush(stdout);
				perror("");
			}
			free(realPath);
		}
	}
}