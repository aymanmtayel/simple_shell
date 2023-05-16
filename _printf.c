#include "main.h"
/**
 * _printf- prints formated string
 * @format: the formated string
 *
 * Return: length of string printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int written = 0;
	const char *p;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);
	p = format;
	while (*p != '\0')
	{
		if (*p == '%')
		{
			++p;
			if (*p == 'c')
				written += print_char(ap);
			else if (*p == 's')
				written += print_string(ap);
			else if (*p == '%')
				written += write(1, p, 1);
			else if ((*p == 'd') || (*p == 'i'))
				written += print_int(ap);
			else if (*p == 'b')
				written += bin(ap);
			else if (*p == 'u')
				written += print_unint(ap);
			else if (*p == 'o')
				written += print_octal(ap);
			else
			{
				written += write(1, "%", 1);
				written += write(1, p, 1);
			}

		}
		else
			written += write(1, p, 1);
		p++;
	}
	va_end(ap);
	return (written);
}
