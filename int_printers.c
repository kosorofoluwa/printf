#include "main.h"

/**
 * int_printer - Print function that handles printing a signed integer.
 * @arg: The argument to be printed.
 *
 * Return: The printed length of characters.
 */
int int_printer(va_list arg)
{
	int val = va_arg(arg, int);
	unsigned int neg_val;

	if (val < 0)
	{
		putchar('-');
		/* to take care of large unsigned int vals */
		neg_val = val * -1;
		return (1 + int_helper(neg_val));
	}
	return (int_helper(val));
}

/**
 * int_helper - Helper function for int_printer that prints a positive integer.
 * @val: The argument to be printed.
 *
 * Return: The number of characters printed.
 */
int int_helper(unsigned int val)
{
	unsigned int a = val, printed_length = 0;

	if (val < 9)
	{
		putchar((a % 10) + '0');
		return (1);
	}
	printed_length = 1 + int_helper(val / 10);

	putchar((a % 10) + '0');
	return (printed_length);
}
