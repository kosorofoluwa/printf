#include "main.h"

/**
 * print_pointer- Print function that handles printing a pointer address in hexadecimal format.
 * @arg: The argument to be printed.
 *
 * Return: The printed length of characters.
 */
int print_pointer(va_list arg)
{
	unsigned long val;
	int i, hex_digit;
	char *str = "(nil)";

	val = (unsigned long)va_arg(arg, void *);
	if (val)
	{
		putchar('0');
		putchar('x');
		for (i = 11; i >= 0; i--)
		{
			hex_digit = (val >> (i * 4)) & 0xf;
			putchar("0123456789abcdef"[hex_digit]);
		}
		return (14);
	}
	for (; *str; str++)
		putchar(*str);
	return (5);
}
