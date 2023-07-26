#include "main.h"

/**
 * binary_len - finds the length of the resulting binary
 * @num: number to be converted to binary
 *
 * Return: length of the binary
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
 * print_binary - converts an integer to a binary
 * @arg: argument to be printed
 *
 * Return: count of characters
 */
int print_binary(va_list arg)
{
	int num = va_arg(arg, int), i;
	int len;
	char *str = NULL;

	len = binary_len(num);
	str = print_binary_helper(str, len, num);
	if (!str)
		return (0);

	for (i = len - 1; i >= 0; i--)
		putchar(str[len - i - 1]);

	free(str);
	return (len);
}

/**
 * print_binary_helper - helper function
 * @str: pointer that will contain the resulting binary string
 * @len: length of str
 * @num: number to be converted to binary
 *
 * Return: length of the binary
 */
char *print_binary_helper(char *str, int len, int num)
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
