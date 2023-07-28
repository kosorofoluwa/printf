#include "main.h"

/**
 * srev_printer - Print function that prints a string in reverse.
 * @args: The arguments to be printed.
 *
 * Return: The printed length of characters.
 */
int srev_printer(va_list args)
{

	char *s = va_arg(args, char*);
	int i;
	int j = 0;

	if (s == NULL)
		s = "(null)";
	while (s[j] != '\0')
		j++;
	for (i = j - 1; i >= 0; i--)
		_putchar(s[i]);
	return (j);
}
