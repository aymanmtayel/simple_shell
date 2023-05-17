#include "main.h"

/**
 *_strcmp - compare two strings
 *@s1: string 1
 *@s2: string 2
 *Return: the Difference
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
