#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
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
			count += write(1, format, 1);
		} else
		{
			switch (*++format)
			{
				case 'c': {
						char c = (char)va_arg(args, int);

						count += write(1, &c, 1);
						break;
					}
				case 's': {
						  const char *str = va_arg(args, const char *);

					count += write(1, str, strlen(str));
						break;
					}
				case 'd':
				case 'i': {
						  int num = va_arg(args, int);
						  
						  char buffer[12];
						  int printed = snprintf(buffer, sizeof(buffer), "%d", num);
						  count += write(1, buffer, printed);
						  break;
					  }
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, "%", 1);
					count += write(1, format, 1);
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
