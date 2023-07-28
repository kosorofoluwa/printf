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
} replace_specifier;

int chara_print(va_list arg);
int mod_printer(va_list arg);
int print_void(va_list arg);
int print_float(va_list arg);
int str_printer(va_list arg);
int _printf(const char *format, ...);
int int_printer(va_list arg);
int binary_printer(va_list arg);
int int_helper(unsigned int val);
int binary_len(int num);
int udecimal_printer(va_list arg);
char *binary_printer_helper(char *str, int len, int num);
int udecimal_printer(va_list arg);
int print_ud(int, unsigned long int);
int octal_printer(va_list arg);
int print_ustr(va_list arg);
int print_pointer(va_list arg);
int printf_HEX(va_list arg);
int printf_hex(va_list arg);
int printf_oct(va_list arg);
int rot13_printer(va_list args);
int printf_hex_aux(unsigned long int num);
int printf_HEX_aux(unsigned int num);
int rev_string(char *s);
int srev_printer(va_list args);


#endif
