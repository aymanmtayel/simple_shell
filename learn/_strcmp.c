#include "main.h"

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: seconde string
 * Return: difference between the two strings
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
