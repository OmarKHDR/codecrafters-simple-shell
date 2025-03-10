#include "headers.h"

void register_commands() {
	insert_command("exit", my_exit, strdup("exit is a shell builtin"));
	insert_command("echo", my_echo, strdup("echo is a shell builtin"));
	insert_command("type", my_type, strdup("type is a shell builtin"));
	insert_command("pwd", my_pwd, strdup("pwd is a shell builtin"));
	insert_command("cd", my_cd, strdup("cd is a shell builtin"));
}
