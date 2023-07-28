#include "main.h"

/**
 * chara_print - Print function that handles printing an ASCII character.
 * @arg: The argument to be printed.
 *
 * Return: The printed length of characters (always 1).
 */
int chara_print(va_list arg)
{
	putchar(va_arg(arg, int));
	return (1);
}

/**
 * str_printer - Print function that handles printing a string.
 * @arg: The argument to be printed.
 *
 * Return: The printed length of characters.
 */
int str_printer(va_list arg)
{
	char *string = va_arg(arg, char *);
	int i;

	if (!string)
		string = "(null)";

	for (i = 0; string[i]; i++)
		putchar(string[i]);

	return (i);
}

/**
 * print_ustr - prints a string
 * @arg: argument to be printed
 *
 * Return: printed_length of characters
 */
int print_ustr(va_list arg)
{
	char *string = va_arg(arg, char *);
	char hex[2];
	int i, ascii, len = 0;

	if (!string)
		string = "(null)";

	for (i = 0; string[i]; i++)
	{
		ascii = string[i];
		if (ascii < 32 || ascii >= 127)
		{
			putchar('\\');
			putchar('x');
			hex[0] = "0123456789ABCDEF"[(unsigned char)string[i] >> 4];
			hex[1] = "0123456789ABCDEF"[(unsigned char)string[i] & 0x0F];
			putchar(hex[0]);
			putchar(hex[1]);
			len += 4;
		}
		else
		{
			putchar(string[i]);
			len++;
		}
	}
	return (len);
}

/**
 * mod_printer - prints modulus
 * @arg: argument to be printed
 *
 * Return: printed_length of characters
 */
int mod_printer(va_list arg)
{
	(void)arg;

	putchar('%');

	return (1);
}
