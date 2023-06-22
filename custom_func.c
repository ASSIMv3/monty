#include "monty.h"

/**
 * custom_realloc - Custom implementation of realloc function
 *
 * @ptr: Pointer to the original memory block
 * @o_size: Original size of the memory block
 * @n_size: New size to which the memory block should be reallocated
 *
 * Return: ptr to the new allocated memory | NULL
 */
void *custom_realloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	unsigned int idx = 0;
	void *new_alloc;
	char *dest;
	char *src;

	if (n_size == o_size && ptr)
		return (ptr);
	if (!n_size && ptr)
	{
		free(ptr);
		return (NULL);
	}
	new_alloc = malloc(n_size);
	if (!new_alloc)
		return (NULL);
	if (!ptr)
		return (new_alloc);
	dest = new_alloc;
	src = ptr;
	while (idx < o_size && idx < n_size)
	{
		*dest++ = *src++;
		idx++;
	}

	free(ptr);
	return (new_alloc);
}
