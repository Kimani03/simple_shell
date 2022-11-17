#include "shell.h"

/**
 * _readCmd - function that reads a line from the standard input
 * @env: argument passed
 * Description: first work by printing the command prompt then read command
 *              from the standard input
 * Return: returns a pointer containing the string passed to the command line
 */

char *_readCmd(char **env)
{
	char *string = NULL;
	size_t bufSize = 0;
	char **args = NULL;
	ssize_t read = 0;
	int a = 0, status, num_arg;
	static int count, stad_exit;

	if (signal(SIGINT, sighandler) == SIG_ERR)
		perror("error:\n");
	while (1 == 1)
	{
		if (isatty(STDIN_FILENO) == 1)
			sim_printShell("shell$ ");
		read = getline(&string, &bufsize, stdin);
		++count;
		if (func_ctrlD(string, read, &stad_exit) == 127)
			continue;
		rm_newLine(string);
		args = _parser(string);
		for (a = 0; args[a]; a++)
			num_arg++;

		built_in(string, args, env, &stad_exit);
		status = _path(args[0], args, env, &stad_exit);
		forkExec(status, args, &count, &stad_exit);
		{
			fflush(stdin);
		}
	}
	free(string);
	return (0);
}

