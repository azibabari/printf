#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - prints a formatted string to the standard output
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int printed_chars = 0;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
char c = va_arg(args, int);
write(1, &c, 1);
printed_chars++;
}
else if (*format == 's')
{
char *s = va_arg(args, char *);
while (*s)
{
write(1, s, 1);
s++;
printed_chars++;
}
}
else if (*format == '%')
{
write(1, "%", 1);
printed_chars++;
}
}
else
{
write(1, format, 1);
printed_chars++;
}
format++;
}
va_end(args);

return (printed_chars);
}
