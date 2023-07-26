#include "main.h"

/**
 * print_udecimal - converts an integer to unsigned decimal
 * @arg: argument to be printed
 *
 * Return: count of characters
 */
int print_udecimal(va_list arg)
{
	int num = va_arg(arg, int);
	int len = 0, num_copy, i;
	char *str = NULL;
	unsigned long int value = 0, power = 1;

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

	str = print_binary_helper(str, len, num);

	for (i = len - 1; i >= 0; i--)
	{
		value += (int)(str[i] - 48) * power;
		power *= 2;
	}
	len = print_ud(0, value);
	free(str);
	return (len);
}

/**
 * print_ud - prints the undigned decimal
 * @len: counter
 * @value: value
 *
 * Return: count of characters
 */
int print_ud(int len, unsigned long int value)
{
	if (value == 0)
		return (0);
	len = 1 + print_ud(len, value / 10);
	putchar((value % 10) + '0');
	return (len);
}
