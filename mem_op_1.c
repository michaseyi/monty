#include "monty.h"

/**
 * _realloc1 - Allocates memory from old_size to new_size
 * @ptr: pointer to hold address of allocated memory
 * @old_size: old_size
 * @new_size: new_size
 * Return: Address of allocated memory or NULL if it fails
 */

void *_realloc1(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;

	if (old_size == new_size)
		return (ptr);
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new = malloc(new_size);
		if (new == NULL)
			return (NULL);
		else
			return ((void *)new);
	}
	new = malloc(new_size);
	if (new == NULL)
		return (NULL);
	_memcpy2(new, ptr, old_size);
	free(ptr);
	return (new);
}

/**
 * _memcpy2 - copies memory from src to destination
 * @dest: destination
 * @src: source
 * @n: amount to copy
 * Return: address of the destination
 */
char *_memcpy2(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * free_double_ptr- frees  memory allocated to a double pointer
 * @ptr: Pointer to address to be freed
 * @len: Number of inner elements
 * Return: void
 */

void free_double_ptr(char **ptr, int len)
{
	int i;

	if (len == 0)
		return;
	for (i = 0; i < len; i++)
		free(ptr[i]);
	free(ptr);
}

/**
 * _realloc2 - Allocates memory from old_size to new_size
 * @ptr: pointer to hold address of allocated memory
 * @old_size: old_size
 * @new_size: new_size
 * Return: Address of allocated memory or NULL if it fails
 */

void *_realloc2(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **new;

	if (old_size == new_size)
		return (ptr);
	if (ptr != NULL && new_size == 0)
	{
		free_double_ptr(ptr, old_size / sizeof(char *));
		return (NULL);
	}
	if (ptr == NULL)
	{
		new = malloc(new_size);
		if (new == NULL)
			return (NULL);
		else
			return ((void *)new);
	}
	new = malloc(new_size);
	if (new == NULL)
	{
		free_double_ptr(ptr, old_size / sizeof(char *));
		return (NULL);
	}
	_memcpy(new, ptr, old_size / sizeof(char *));
	free(ptr);
	return (new);
}

/**
 * free_double_ptr2 - frees  memory allocated to a double pointer that is
 * NULL terminated
 * @ptr: Pointer to address to be freed
 * Return: void
 */

void free_double_ptr2(char **ptr)
{
	int i = 0;

	if (ptr == NULL)
		return;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

