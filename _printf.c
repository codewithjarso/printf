#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - function produces output according to format
 * @format: is the formatin which output will be produced
 * Return: count
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			            if (*++format == 'c')
            {
                count += write(1, (char[]){va_arg(args, int)}, 1);
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                count += write(1, str, strlen(str));
            }
            else if (*format == '%')
            {
                count += write(1, "%", 1);
            }
		    else if (*format == 'x' || *format == 'X' || *format == 'u' || *format == 'p' || *format == 'o')
{
    unsigned int num = va_arg(args, unsigned int);
    unsigned int temp = num;
    int digit_count = 0;
    while (temp != 0)
    {
        temp /= 10;
        digit_count++;
    }
    while (digit_count > 0)
    {
        unsigned int digit = num % 10;
        if (*format == 'x')
        {
            char c = (digit < 10) ? digit + '0' : digit - 10 + 'a';
            write(1, &c, 1);
        }
        else if (*format == 'X')
        {
            char c = (digit < 10) ? digit + '0' : digit - 10 + 'A';
            write(1, &c, 1);
        }
        else if (*format == 'u' || *format == 'o')
        {
            char c = digit + '0';
            write(1, &c, 1);
        }
        else if (*format == 'p')
        {
            if (digit < 10)
            {
                char c = digit + '0';
                write(1, &c, 1);
            }
            else
            {
                char c = digit + 'A' - 10;
                write(1, &c, 1);
            }
        }
        num /= 10;
        digit_count--;
    }
}
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                char num_str[12];
                int digit_count = 0;
                if (num < 0)
                {
                    count += write(1, "-", 1);
                    num = -num;
                }
                if (num == 0)
                {
                    count += write(1, "0", 1);
                }
                else
                {
                    while (num != 0)
                    {
                        num_str[digit_count++] = (num % 10) + '0';
                        num /= 10;
                    }
                    for (int i = digit_count - 1; i >= 0; i--)
                    {
                        count += write(1, &num_str[i], 1);
                    }
                }
            }
            else
            {
                count += write(1, format - 1, 1);
                count += write(1, format, 1);
            }
        }
        format++;
    }
    va_end(args);
    return count;
}
