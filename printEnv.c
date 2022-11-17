#include "shell.h"

/**
 * _printEnv - function that prints the environment
 * @env: the environment variable
 * @stad_exit: the exit command
 * Return: returns 0 on succes, otherwise 1 on failure(error)
 */

int _printEnv(char **env, int *stad_exit)
{
	unsigned int a;

	for (a = 0; env[a] != NULL; a++)
	{
		print_string(env[a]);
		write(STDOUT_FILENO, "\n", 1);
	}

	*stad_exit = 0;
	return (0);
}

/**
 * print_string - this function works by printing each line of the environment
 * @env: the environmantal variable passed from the print environment
 * Return: does not return a value (void)
 */

void print_string(char *env)
{
	int b;

	for (b = 0; env[b] != '\0'; b++)
		;
	write(STDOUT_FILENO, env, b);
}

