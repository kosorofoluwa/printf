#include "main.h"

/**
 * printf_oct - Print function that prints an octal number.
 * @arg: The argument to be printed.
 *
 * Return: The printed length of characters.
 */
int printf_oct(va_list arg)
{
	int i;
	int *array;
	int printed_length = 0;
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int temp = num;

	while (num / 8 != 0)
	{
		num /= 8;
		printed_length++;
	}
	printed_length++;
	array = malloc(printed_length * sizeof(int));

	for (i = 0; i < printed_length; i++)
	{
		array[i] = temp % 8;
		temp /= 8;
	}
	for (i = printed_length - 1; i >= 0; i--)
	{
		_putchar(array[i] + '0');
	}
	free(array);
	return (printed_length);
}
