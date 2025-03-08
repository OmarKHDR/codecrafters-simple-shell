#include "headers.h"


int handle_exit(char *code_str) {
	if (isdigit(*code_str)) {
		return (int)(*code_str) - (int)('0');
	}
	return -1;
}

void my_exit(char *code_str) {
	if (code_str) {
		int code = handle_exit(code_str);
		exit(code);
	} else {
		exit(-1);
	}
}