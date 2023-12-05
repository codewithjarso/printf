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
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format) {
        if (*format == '%') {
            format++; // Move past '%'
            switch (*format) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char*);
                    while (*str) {
                        write(1, str, 1);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    // Ignore unknown format specifiers
                    break;
            }
        } else {
            write(1, format, 1);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}
