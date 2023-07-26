#include "main.h"

/**
 * print_char - prints a ASCII character
 * @arg: argument to be printed
 *
 * Return: count of characters
 */
int print_char(va_list arg)
{
	putchar(va_arg(arg, int));
	return (1);
}

/**
 * print_str - prints a string
 * @arg: argument to be printed
 *
 * Return: count of characters
 */
int print_str(va_list arg)
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
 * Return: count of characters
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
 * print_mod - prints modulus
 * @arg: argument to be printed
 *
 * Return: count of characters
 */
int print_mod(va_list arg)
{
	(void)arg;

	putchar('%');

	return (1);
}
