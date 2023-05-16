#include "main.h"

/**
 * bin - print integers into binary
 * @list: list of arguments
 * Return: count of printed arguments
 */

unsigned int bin(va_list list)
{
	unsigned int n, i;
	unsigned int counter = 0;
	char h;
	int non_zero_printed = 0;

	n = va_arg(list, unsigned int);

	for (i = 1 << 31; i > 0; i = i / 2)
	{
		if (n & i)
		{
			h = '1';
			write(1, &h, 1);
			counter++;
			non_zero_printed = 1;
		}
		else
		{
			if (non_zero_printed)
			{
			h = '0';
			write(1, &h, 1);
			counter++;
			}
		}
	}
	if (!non_zero_printed)
	{
		h = '0';
		write(1, &h, 1);
		counter++;
	}
	return (counter);
}
