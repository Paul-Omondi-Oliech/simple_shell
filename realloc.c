#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: a pointer to the memory area
 * @c: the byte to be filled with *s
 * @n: amount of bytes to be filled
 * Return: (s) a pointer to the memory area
 */
char *_memset(char *s, char c, unsigned int n)
{
	unsigned int j;

	for (j = 0; j < n; j++)
		s[j] = c;
	return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: the string of strings
 */
void ffree(char **pp)
{
	char **m = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(m);
}

/**
 * _realloc - reallocates a block of memory to a file
 * @ptr: pointer to the previous block of memory allocated
 * @old_size: byte size of the previous block of memory
 * @new_size: byte size of the new block of memory
 * Return: pointer to the dealloccated block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
