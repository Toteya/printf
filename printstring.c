#include "main.h"

/**
 * printstring - Prints a string to stdout
 * @s: The string to be printed
 *
 * Return: If successful, number of character printed. Otherwise return -1.
 */
int printstring(char *s)
{
	int i = 0;

	if (!s)
		return (-1);
	while (*s != '\0')
	{
		pchar(*s);
		i++;
		s++;
	}
	return (i);
}
