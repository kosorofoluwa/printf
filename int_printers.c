#include "main.h"

/**
 * print_int - prints an integer
 * @arg: argument to be printed
 *
 * Return: 0
 */
int print_int(va_list arg)
{
	int value = va_arg(arg, int);
	unsigned int neg_value;

	if (value < 0)
	{
		putchar('-');
		/* to take care of large unsigned int values */
		neg_value = value * -1;
		return (1 + int_helper(neg_value));
	}
	return (int_helper(value));
}

/**
 * int_helper - helper function
 * @value: argument to be printed
 *
 * Return: chars printed
 */
int int_helper(unsigned int value)
{
	unsigned int a = value, count = 0;

	if (value < 9)
	{
		putchar((a % 10) + '0');
		return (1);
	}
	count = 1 + int_helper(value / 10);

	putchar((a % 10) + '0');
	return (count);
}
