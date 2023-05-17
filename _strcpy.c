#include "main.h"

/**
 * _strcpy - copies a string to a buffer
 * @dest: the destination
 * @src: source string
 * Return: the buffer after coping
 */

char *_strcpy(char *dest, char *src)
{
	char *dest_start = dest;

	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}
