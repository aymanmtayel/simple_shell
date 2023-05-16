#include "main.h"

#define MAX_INPUT_LENGTH 1024

int main(void)
{
	char input[MAX_INPUT_LENGTH];
	int len = 0;

    while (1)
    {
	    write(STDOUT_FILENO, "#cisfun$ ", 9);
	    len = read(STDIN_FILENO, input, MAX_INPUT_LENGTH);
	    if (len == -1)
	    {
		    exit_with_error("read error");
	    }
	    else if (len == 0)
	    {
		    break;
	    }
	    else
	    {
		    input[len - 1] = '\0';
	    }
	    if (!is_valid_executable(input))
	    {
		    perror("error_msg");
		    continue;
	    }
	    execute_command(input);
    }
    return 0;
}
