#include "main.h"

/**
 * print_int - prints an integer
 * @arg: argument to be printed
 *
 * Return: 0
 */
int print_pointer(va_list arg)
{
	unsigned long value;
	int i, hex_digit;
	char *str = "(nil)";
		
	value = (unsigned long)va_arg(arg, void *);
	if (value)
	{
		putchar('0');
		putchar('x');
		for (i = 11; i >= 0; i--)
		{
    			hex_digit = (value >> (i * 4)) & 0xf;
   			putchar("0123456789abcdef"[hex_digit]);
		}
		return (14);
	}
	for (; *str; str++)
		putchar(*str);
	return (5);
}
