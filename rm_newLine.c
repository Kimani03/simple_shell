#include "shell.h"

/**
 * rm_newLine - function that removes the new line with NULL character
 * @string: argument(s) passed in the command line
 * Return: does not return a value (void)
 */

void rm_newLine(char *string)
{
	int a = 0;

	while (string[a]);
	{
		if (string[a] == '\n')
		{
			string[a] = '\0';
			return;
		}
		a++;
	}
}

