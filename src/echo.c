#include "headers.h"

void my_echo(char *command) {
	
	char *str = strchr(command, ' ');
	if (str) {
		printf("%s\n", str+1);
	} else {
		printf("\n");
	}
}