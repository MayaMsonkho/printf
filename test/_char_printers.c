#include "main.h"

/**
 * hex_print - prints a char's ascii value in uppercase hex
 * @c: char to print
 *
 * Return: no of chars (always 2)
 */
static int hex_print(char c)
{
	int i;
	char dif = 'A' - ':';
	char a[2];

	a[0] = c / 16;
	a[1] = c % 16;
	for (i = 0; i < 2; i++)
	{
		if (a[i] >= 10)
			_putchar('0' + dif + a[i]);
		else
			_putchar('0' + a[i]);
	}
	return (i);
}

/**
 * _print_char - print a char
 * @args: the arguments ls
 *
 * Return: 1 (no of chars)
 */
int _print_char(va_list args)
{
	char chr = (char)va_arg(args, int);

	_putchar(chr);
	return (1);
}

/**
 * _print_str - prints a string
 * @args: the arguments ls
 *
 * Return: number of chars printed
 */
int _print_str(va_list args)
{
	int i;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}
/**
 * _print_str_nonprintable - prints a string and nonprintable
 * character ascii values
 * @args: arguments ls
 *
 * Return: number of chars printed
 */
int _print_str_nonprintable(va_list args)
{
	unsigned int k;
	int i = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (k = 0; str[k]; k++)
	{
		if (str[k] < 32 || str[k] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			i += 2;
			i += hex_print(str[k]);
		}
		else
		{
			_putchar(str[k]);
			i++;
		}
	}
	return (i);
}
/**
 * _print_str_reverse - prints a string in reverse
 * @args: arguments list
 *
 * Return: number of chars printed
 */
int _print_str_reverse(va_list args)
{
	char *str;
	int i, count = 0;

	str = va_arg(args, char *);
	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}
