#include "shell.h"

/**
 * built_in - comparison between argv passed and the commands that are built-in
 * @string: the pointer with the saved line
 * @argv: arguments passed
 * @enviro: variables of the environment
 * @exi_t: an integer
 */

void built_in(char *string, char **argv, char **enviro, int *exi_t)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		free(string);
		exit(*exi_t);
	}
	if (_strcmp(argv[0], "enviro") == 0)
		printenv(enviro, exi_t);
}

