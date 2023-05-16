#include "main.h"

/**
 * print_unint - prints unsigned integers
 * @list: list of arguments
 * Return: Return no of charcters printed
 */

unsigned int print_unint(va_list list)
{
	unsigned int digit = 1;
	unsigned int n, num;
	int i = 0;
	char holder;

	n = va_arg(list, unsigned int);
	num = n;

	while (num / 10)
	{
		digit *= 10;
		num /= 10;
	}
	while (digit)
	{
		holder = ((n / digit) + '0');
		write(1, &holder, 1);
		n %= digit;
		digit /= 10;
		i++;
	}
	return (i);
}
