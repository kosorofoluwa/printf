#include "main.h"

/**
 * _printf - function that handles formatted output.
 * @format: The character string containing the format specifier.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int i = 0, j, str_len = 0, flag = 0, array_len;
	replace_specifier format_funcs[] = {
		{'c', chara_print},
		{'s', str_printer},
		{'%', mod_printer},
		{'i', int_printer},
		{'d', int_printer},
		{'b', binary_printer},
		{'u', udecimal_printer},
		{'S', print_ustr},
		{'p', print_pointer},
		{"%o", printf_oct},
		{"%x", printf_hex},
		{"%X", printf_HEX},
		{"%R", rot13_printer},
		{"%r", srev_printer},
		
	};
	/* check for format = NULL OR format = "%" */
	if (format == NULL || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);
	va_start(arg, format);
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
