#include "main.h"
#include <string.h>
#include <stdarg.h>
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
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			count += write(1, format, 1);
		} else
		{
			switch (*++format)
			{
				case 'c':
					count += write(1, (char)va_arg(args, int), 1);
					break;
				case 's': {
						  const char *str = va_arg(args, const char *);

					if (str == NULL)
						count += write(1, "(null)", 6);
					else
						count += write(1, str, strlen(str));
					break;
					} case '%':
					count += write(1, "%", 1);
					break;
				case '\0':
					return (-1);
				default:
					count += write(1, format - 1, 1);
					count += write(1, format, 1);
			}
		} format++;
	} va_end(args);
	return (count);
}
