#include "shell.h"

/**
 * funct_ctrlD - function that allows the use of CTRL + D as a means of
 *               shutting down the shell
 * @string: passed argument(s)
 * @read: the size of saved string
 * @stad_exit: static variable integer
 * Return: returns 0 on success, otherwise 1
 */

int funct_ctrlD(char *string, ssize_t read, int *stad_exit)
{
	int a = 0;
	if (read == EOF && isatty(STDIN_FILENO) == 0)
	{
		free(string);
		exit(*stad_exit);
	}
	if (read == EOF && isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(string);
		exit(*stad_exit);
	}
	if (_strcmp(string, "\n") == 0)
	{
		*stad_exit = 0;
		return (127);
	}
	while (string[i] != '\n')
	{
		if (string[i] != ' ' && string[i] != '\t')
			return (0);
		++i;
	}
	*stad_exit = 0;
	return (127);
}

