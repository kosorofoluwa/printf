#include "main.h"

/**
 * printf_hex - Print function that prints an hexadecimal number.
 * @arg: The argument to be printed.
 *
 * Return: The printed length of characters.
 */
int printf_hex(va_list arg)
{
	int i;
	int *array;
	int printed_length = 0;
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		printed_length++;
	}
	printed_length++;
	array = malloc(printed_length * sizeof(int));

	for (i = 0; i < printed_length; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = printed_length - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		putchar(array[i] + '0');
	}
	free(array);
	return (printed_length);
}
