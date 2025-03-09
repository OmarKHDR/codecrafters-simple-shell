#include "headers.h"

void my_pwd(char *command) {
	char path[100];
	if (getcwd(path, sizeof(path)) != NULL) {
		printf("%s\n", path);
	}
}
