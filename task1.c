#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include "main.h"
/**
 * _printf - print a formatted string
 * @format: format the string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count;
va_start(args, format);
count = 0;
while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
printf("%d", num);
count++;
}
else
{
printf("Error: unsupported format specifier\n");
return (-1);
}
}
else
{
printf("%c", *format);
count++;
}
format++;
}
va_end(args);
return (count);
}
