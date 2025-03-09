#include "headers.h"


int handle_exit(char *code_str) {
	if (isdigit(*code_str)) {
		return (int)(*code_str) - (int)('0');
	}
	return -1;
}

void my_exit(char *command) {
	char *code_str = strchr(strdup(command), ' ');
	int code = -1;
	if (code_str) {
		code = handle_exit(code_str+1);
	} 
	exit(code);
}