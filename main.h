#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

/**
 * struct print_format - format of char and func. povoider
 * @symbol: print specifier
 * @print: pointer to specifier function
 *
 */
typedef struct print_format
{
	char symbol;
	int (*print)(va_list arg);
} prt;

int print_char(va_list arg);
int print_mod(va_list arg);
int print_void(va_list arg);
int print_float(va_list arg);
int print_str(va_list arg);
int _printf(const char *format, ...);
int print_int(va_list arg);
int print_binary(va_list arg);
int int_helper(unsigned int value);
int binary_len(int num);
int print_udecimal(va_list arg);
char *print_binary_helper(char *str, int len, int num);
int print_udecimal(va_list arg);
int print_ud(int, unsigned long int);
int print_octal(va_list arg);
int print_ustr(va_list arg);
int print_pointer(va_list arg);

#endif
