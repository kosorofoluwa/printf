#include "main.h"

/**
 * binary_len - Finds the length of the resulting binary.
 * @num: The number to be converted to binary.
 *
 * Return: The length of the binary.
 */
int binary_len(int num)
{
	int len = 0;

	if (num < 0)
		len = 32;
	else
	{
		if (num == 0)
			len++;
		while (num > 0)
		{
			num /= 2;
			len++;
		}
	}
	return (len);
}
/**
 * binary_printer - Print function that converts an integer to binary and prints it.
 * @arg: The argument to be printed.
 *
 * Return: The printed length of characters.
 */
int binary_printer(va_list arg)
{
	int num = va_arg(arg, int), i;
	int len;
	char *str = NULL;

	len = binary_len(num);
	str = binary_printer_helper(str, len, num);
	if (!str)
		return (0);

	for (i = len - 1; i >= 0; i--)
		putchar(str[len - i - 1]);

	free(str);
	return (len);
}

/**
 * binary_printer_helper - Helper function for binary_printer that converts a number to a binary string.
 * @str: Pointer that will contain the resulting binary string.
 * @len: Length of str.
 * @num: Number to be converted to binary.
 *
 * Return: Pointer to the binary string.
 */
char *binary_printer_helper(char *str, int len, int num)
{
	int i, k;

	str = malloc(sizeof(char *) * len);
	if (!str)
		return (0);
	for (i = len - 1; i >= 0; i--)
	{
		k = num >> i;
		if (k & 1)
			str[len - i - 1] = '1';
		else
			str[len - i - 1] = '0';
	}
	return (str);
}
