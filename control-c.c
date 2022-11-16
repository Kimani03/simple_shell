#include "shell.h"

/**
 * sign_handler - this function deals with keyboard interrupt signals
 * @signal: signal being handled
 */

void sign_handler(int signal)
{
	int sign_cmd = 0;

	if (signal == SIGINT && sign_cmd == 0)
		sim_printShell("\nshell$ ");
	else if
		sim_printShell("\n");
}

/**
 * sim_printShell - this function prints a message
 * @string: the string to be printed
 */

void sim_printShell(char *string)
{
	int len;

	len = _strlen(string);
	write(STDOUT_FILENO, string, len);
}

