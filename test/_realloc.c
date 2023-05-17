#include "main.h"

/**
 * _realloc - Changes the size of a memory block
 * @ptr: The pointer to the memory block to resize
 * @old_size: The old size of the memory block
 * @new_size: The new size of the memory block
 * Return: A pointer to the resized memory block, or NULL if allocation fails
 */

void *_realloc(void *ptr, unsigned int old_size __attribute__((unused)), unsigned int new_size)
{
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = realloc(ptr, new_size);
	if (new_ptr == NULL)
	{
		perror("_realloc");
		return (NULL);
	}
	return (new_ptr);
}
