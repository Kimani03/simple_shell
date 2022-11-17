#include "shell.h"

/**
 * _strlen - function that returns length of a string
 * @@s: string in question
 * Return: returns length of a string
 */

int _strlen(char *s)
{
	int a = 0;

	while (s[a] != '\0')
		a++;
	return (a);
}

/**
 * _strcpy - copies string from the source to the destination, and also
 *           includes termination of the null byte
 * @dest: destination where string will be copied to
 * @src: string to be copied from the source
 * Return: returns a pointer to the destination
 */

char *_strcpy(char *dest, char *src)
{
	int a = 0;

	while (a <= _strlen(src))
	{
		dest[a] = src[a];
		a++;
	}
	return (dest);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: destination of the character string
 * @src: source of the character string
 * Return: returns pointer to rhe resulting destination of the string
 */

char *_strcat(char *dest, char *src)
{
	int len = _strlen(dest);
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[len + a] = src[a];
	dest[len + a] = '\0';
	return (dest);
}

/**
 * _strcmp - function that makes a comparison between 2 strings
 * @s1: char string 1
 * @s2: char string 2
 *
 * Return: returns an int </=/> 0 if s1 found to be less than, to march to 
 *         or greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	int a = 0;

	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] != s2[a])
			return ((int) s1[a] - s2[a]);
		a++;
	}
	return (0);
}

/**
 * _strdup - function that returns pointer to a newly allocated memory space
 * @str: character
 * Return: returns pointer to a new string that is a duplicate of the string
 */

char *_strdup(char *str)
{
	int a, b = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		b++;
	ptr = malloc(sizeof(char) * b + 1);
	if (ptr == NULL)
		return (NULL);
	for (a = 0; a < b; a++)
		ptr[a] = str[a];
	ptr[b] = '\0';
	return (ptr);
}

