#include "shell.h"

/**
 * _path - works by looking for the PATH in the environment
 * @args: arguments that have been saved on getline
 * @argv: passed arguments
 * @env: variables of the environment
 * #stad_exit: the exit command
 * Return: returns 0 on success
 *
 */

int _path(char *args, char **argv, char **env, int *stad_exit)
{
	int i;
	char *tmp, *izq, *der;
	char *copy, *envcpy;

	for (i = 0; env[i] != NULL; i++)
	{
		envcpy = _strdup(env[i]);
		izq = strtok(envcpy, "=\t");
		tmp = strtok(NULL, "=\t");

		if (_strdup(izq, "PATH") == 0)
		{
			der = strtok(tmp, ":\t");
			while (der)
			{
				copy = print_path(der, args);
				if (access(copy, X_OK) == 0)
				{
					if (fork() == 0)
						execve(copy, argv, NULL);
					else
						wait(NULL);
					*stad_exit = 2;
					free(copy);
					free(envcpy);
					return 0;
				}
				der = strtok(NULL, ":\t");
				free(copy);
			}
		}
		free(envcpy);
	}
	return (2);
}

/**
 * print_path - this function makes a copy of, and prints, PATH
 * @der: tokens that have been saved
 * @args: arguments
 * Return: returns a character variable with copy of PATH
 */

char *print_path(char *der, char *args)
{
	char *tokens, *copy;
	int tkn_len, len;

	token = der;
	tkn_len = _strlen(token);
	len = _strlen(args);
	copy = malloc((tkn_len + len + 2) * sizeof(char));

	if (copy == NULL)
		return (NULL);
	copy[0] = '\0';
	_strncat(copy, der);
	_strncat(copy, "/");
	_strncat(copy, args);
	_strncat(copy, "\0");
	return (copy);
}
