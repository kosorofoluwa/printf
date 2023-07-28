#include "main.h"

/**
 * udecimal_printer - Print function that converts an integer to unsigned decimal and prints it.
 * @arg: The argument to be printed.
 *
 * Return: The printed length of characters.
 */
int udecimal_printer(va_list arg)
{
	int num = va_arg(arg, int);
	int len = 0, num_copy, i;
	char *str = NULL;
	unsigned long int val = 0, power = 1;

	if (num == 0)
	{
		putchar('0');
		return (1);
	}
	if (num < 0)
		len = 32;
	else
	{
		num_copy = num;
		if (num_copy == 0)
			len++;
		while (num_copy > 0)
		{
			num_copy /= 2;
			len++;
		}
	}

	str = binary_printer_helper(str, len, num);

	for (i = len - 1; i >= 0; i--)
	{
		val += (int)(str[i] - 48) * power;
		power *= 2;
	}
	len = print_ud(0, val);
	free(str);
	return (len);
}

/**
 * print_ud - Helper function for udecimal_printer that prints the unsigned decimal value.
 * @len: Printed length.
 * @val: The value to be printed.
 *
 * Return: The printed length of characters.
 */
int print_ud(int len, unsigned long int val)
{
	if (val == 0)
		return (0);
	len = 1 + print_ud(len, val / 10);
	putchar((val % 10) + '0');
	return (len);
}
