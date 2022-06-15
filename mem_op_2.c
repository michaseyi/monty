#include "monty.h"

/**
 * _memcpy - copies memory from src to destination(double pointer)
 * @dest: destination
 * @src: source
 * @n: amount to copy
 * Return: address of the destination
 */

char **_memcpy(char **dest, char **src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
