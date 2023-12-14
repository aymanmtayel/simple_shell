#include "main.h"

/**
 * stringcompare - compare between strings
 * @str1: 1st string
 * @str2: 2nd string
 * Return: 0 if they are equal, otherwise if defferent
 */

int stringcomapre(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(const unsigned char *)str1 - *(const unsigned char *)str2);
}
