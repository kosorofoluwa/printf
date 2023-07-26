#include "main.h"

/**
 * _printf - print function
 * @format: is a character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, j, str_len = 0, flag = 0, array_len;
	prt format_funcs[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_mod},
		{'i', print_int},
		{'d', print_int},
		{'b', print_binary},
		{'u', print_udecimal},
		{'S', print_ustr},
		{'p', print_pointer}
	};
	/* check for format = NULL OR format = "%" */
	if (format == NULL || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%') /* if plain string */
			putchar(format[i]), str_len++;
		else
		{
			j = 0, i++;
			array_len = sizeof(format_funcs) / sizeof(format_funcs[0]);
			while (j < array_len)
			{
				if (format[i] == format_funcs[j].symbol)
				{
					str_len += format_funcs[j].print(list);
					flag = 1; /* indicates it was found */
					break;
				} j++;
			}
			if (flag == 0) /* if it wasn't found, print '%' as string */
				putchar(format[--i]), str_len++;
		} i++;
	}
	va_end(list);
	return (str_len);
}
