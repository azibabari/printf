#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stddef.h>
/**
 * _printf - prints a formatted string to the standard output
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int i = 0, count = 0;

	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			switch (format[++i])
			{
			case 'c':
				putchar(va_arg(arg, int));
				count++;
				break;
			case 's':
				count += puts(va_arg(arg, char *));
				break;
			case '%':
				putchar('%');
				count++;
				break;
			default:
				putchar('%');
				count++;
				putchar(format[i]);
				count++;
				break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(arg);

	return (count);
}
