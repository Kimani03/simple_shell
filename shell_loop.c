#include "shell.h"

/**
 * shell_Loop - functions with loops that run the shell
 * @env: the environment variable
 * Return: the status of the process - 1 when in error
 */

int shell_loop(char **env)
{
	char *args = NULL;

	do
	{
		args = _readCmd(env);
	}
	while (1 == 1)
		;
	free(args);
	return (0);
}

