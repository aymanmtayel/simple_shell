#include "main.h"

/**
 *print_int - print integers
 *@list: list of arguments
 *Return: counter
 *
 */

int print_int(va_list list)
{
	int n = va_arg(list, int);
	int num, last = n % 10, digit, exp = 1;
	int  i = 1;
	char min = '-';
	char holder;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		write(1, &min, 1);
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			holder = digit + '0';
			write(1, &holder, 1);
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	holder = last + '0';
	write(1, &holder, 1);

	return (i);
}
