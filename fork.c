#include "main.h"

/**
 * handle_child_completion - Waits for the child process to complete.
 * @pid: the process ID of the child process.
 */
void handle_child_completion(pid_t pid)
{
	/* Wait for the child process to complete */
	int status;
	if (waitpid(pid, &status, 0) == -1)
	{
		exit_with_error("waitpid error");
	}
}
