#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - function produces output according to format
 * @format: is the formatin which output will be produced
 * Return: count
 */
int _printf(const char *format, ...) {
  int count = 0;
  va_list args;

  va_start(args, format);

  while (*format != '\0') {
    if (*format != '%') {
      count += write(1, format, 1);

    } else {
      format++;
      switch (*format) {
      case 'c': {
        char c = (char)va_arg(args, int);
        count += write(1, &c, 1);
        break;
      }
      case 's': {
        const char *str = va_arg(args, const char *);
        while (*str) {
          count += write(1, str, 1);
          str++;
      
        }
        break;
      }
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
  return count;
}
