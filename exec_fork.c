#include "shell.h"

/**
 * forkExec - function that executes the commands that are passed
 * @args: commands that are passed into the command line
 * @status: receives status as TRUE or FALSE
 * @count: this variable counts the number of commands that are passed
 * @stnd_exit: an integer static
 * Return: returns no value (void)
 */

void forkExec(int status, char **args, int *count, itn *stnd_exit)
{
	if (status == 2)
	{
		if (access(args[0], F_OK) == 0)
		{
			if (fork() == 0)
				execve(args[0], args, NULL);
			else
				wait(NULL);
			*stnd_exit = 0;
		}
		if (access(args[0], F_OK) !0)
		{
			print_string("sh: ");
			print_count(count);
			print_string(": ");
			perror(args[0]);
			*stnd_exit = 127;
		}

		if (access(args[0], F_OK) == 0 && access(args[0], X_OK) != 0)
		{
			print_string("sh: ");
			print_count(count);
			print_string(": ");
			perror(args[0]);
			*stnd_exit = 126
		}
		if (access(args[0], F_OK | R_OK | X_OK) == -1)
			free(args), arggs = NULL;
	}
	free(args);
}

/**
 * printCount - function that counts and prints the number of passed commands
 * @count: integer with the counter of the passed commands
 * Return: returns no value (void)
 */

void printCount(int *count)
{
	int i, n, cont = 0, len = 0;
	unsigned int base = 1, max, a;
:
	n = *count;
	max = n;
	a = max;
	do {
		a /= 10;
		++len;
	} while (a != 0)
	;
	cont += len;
	for (i = 0; i < len - 1; i++)
		base *= 10;
	_putchar('0' + (max / base));
	if (len > 1)
	{
		for (i = 0; i < len - 2; i++)
		{
			base /= 10;
			a = max / base;
			_putchar('0' + a %10);
		}
		_putchar('0' + (max % 10));
	}
}

/**
 * _putchar - prototype putchar function
 * @c: character that is passed to the function
 * Return: returns 0 on success; otherwise 1 on error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
