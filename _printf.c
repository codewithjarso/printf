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
			switch (*++format)
			{
				case 'c':
					count += write(1, (char[]){va_arg(args, int)}, 1);
					break;
				case 's':
					{
						char *str = va_arg(args, char *);
						
						count += write(1, str, strlen(str));
						break;
					}
					case 'd':
                                        {
                                                int num = va_arg(args, int);
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
                                                        int rev = 0;
                                                        while (num != 0)
                                                        {
                                                                rev = rev * 10 + num % 10;
                                                                num /= 10;
                                                        }
                                                        while (rev != 0)
                                                        {
                                                                count += write(1, &"0123456789"[rev % 10], 1);
                                                                rev /= 10;
                                                        }
                                                }
                                        }
                                        break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, format - 1, 1);
					count += write(1, format, 1);
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
