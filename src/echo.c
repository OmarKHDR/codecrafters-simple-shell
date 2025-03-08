#include "headers.h"

void my_echo(char *command) {
	
	char *str = strchr(command, ' ');
	if (*(str+1)) {
		printf("%s\n", str+1);
	} else {
		printf("\n");
	}
}