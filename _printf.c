#include "main.h"
#include <stdarg.h>

/**
 * _printf - function that produces output in respect to fmt.
 * @format: ls of types of arg passed to the function.
 *
 * Return: no of char printed excluding the NULL byte
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int (*link)(va_list);
	unsigned int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				_putchar(37);
				count++;
				i = i + 1;
			}
			else
			{
				link = format_checker(&format[i + 1]);
				if (link != NULL)
				{
				i = i + 1;
				count += link(ap);
				}
				else
					return (-1);
			}
		}
		else
		{
			_putchar (format[i]);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
