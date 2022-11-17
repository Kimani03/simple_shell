#include "shell.h"

/**
 * main - entry point for the prgram (shell)
 * @argc: number of arguments
 * @argv: arguments entered into the command line
 * @env: environmental variable
 * Return: returns 0 on success, 1 on failure (error)
 */

int main(int argc, char **argv, char **env)
{
	(void)argc, (void)**argv;
	
	shell_loop(env);
	return (EXIT_SUCCESS);
}

