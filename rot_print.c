#include "main.h"
/**
 * rot13_printer - Print function that prints a string using ROT13 encoding.
 * @args: The arguments to be printed.
 *
 * Return: The printed length of characters.
 */
int rot13_printer(va_list args)
{
	int i, j, printed_length = 0;
	int k = 0;
	char *s = va_arg(args, char*);
	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		k = 0;
		for (j = 0; alpha[j] && !k; j++)
		{
			if (s[i] == alpha[j])
			{
				putchar(beta[j]);
				printed_length++;
				k = 1;
			}
		}
		if (!k)
		{
			putchar(s[i]);
			printed_length++;
		}
	}
	return (printed_length);
}
