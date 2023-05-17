#include "main.h"

/**
 *
 *
 *
 */

char *read_line(void)
{
	char *line = NULL;
	size_t size = 0;
	getline(&line, &size, stdin);
	return line;
}
