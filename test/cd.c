#include "main.h"

/**
 *
 *
 *
 *
 */

int cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cd: expected argument\n");
		return 0;
	}
	if (chdir(args[1]) != 0)
	{
		perror("cd");
		return 0;
	}
	free(args[0]);
	    free(args[1]);
	        free(args);
	return 1;
}
