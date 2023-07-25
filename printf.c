#include "main.h"

/**
 * _printf - function that prints formatted output
 * @format: output format
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int print_char = 0;
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(arg_list, int);

				write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(arg_list, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
			}
			else if (*format == '%')
				write(1, format, 1);
		}
		else
			write(1, format, 1);
		print_char++;
		format++;
	}
	va_end(arg_list);
	return (print_char);
}
