#include <stdio.h>
#include <stdarg.h>
#include <unistd.h> // For the write function

int _printf(const char *format, ...);
void print_char(char ch);
void print_string(const char *str);

int main(void)
{
    _printf("Hello, %s! The character is: %c and %% is a percent sign.\n", "User", 'X');
    return 0;
}

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int printed_characters = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                {
                    char ch = (char)va_arg(args, int);
                    print_char(ch);
                    printed_characters++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char*);
                    print_string(str);
                    printed_characters += strlen(str);
                    break;
                }
                case '%':
                    print_char('%');
                    printed_characters++;
                    break;
                default:
                    break;
            }
        }
        else
        {
            print_char(*format);
            printed_characters++;
        }
        format++;
    }

    va_end(args);
    return printed_characters;
}

void print_char(char ch)
{
    char buffer[1];
    buffer[0] = ch;
    write(1, buffer, 1);
}

void print_string(const char *str)
{
    while (*str != '\0')
    {
        print_char(*str);
        str++;
    }
}
