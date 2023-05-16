#include "main.h"

/**
 *print_octal - prints number on base of 8 (octal)
 *@list: list of arguments
 *Return: number of printed characters
 */

int print_octal(va_list list)
{
	unsigned int digit, n, num;
	int i;
	char holder;

	digit = 1;
	n = va_arg(list, unsigned int);
	num = n;
	i = 0;

	while (n / 8)
	{
		digit *= 8;
		n /= 8;
	}
	while (digit)
	{
		holder = (num / digit) + '0';
		write(1, &holder, 1);
		num %= digit;
		digit /= 8;
		i++;
	}
	return (i);
}
