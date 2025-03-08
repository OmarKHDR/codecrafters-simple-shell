#include "headers.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int handleExit(char *command) {
	char *tok = strtok(command, " ");
	if (!strncmp(tok, "exit", 4)) {
		tok = strtok(NULL, " ");
		if (isdigit(*tok)) {
			return (int)(*tok) - (int)('0');
		}
	}
	return -1;
}
