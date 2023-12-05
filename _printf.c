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
