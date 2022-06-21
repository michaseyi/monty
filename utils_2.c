#include "monty.h"


/**
 * len - Gets the length of an array of pointers
 * @str_arr: Array of pointer
 * Return: the number of pointers in str_arr
 */

size_t len(char **str_arr)
{
	size_t i = 0;

	while (str_arr[i])
		i++;
	return (i);
}

/**
 * is_number - Checks whether a string is number
 * @str: input string
 * Return: 1 if it is a legit number else 0
 */

int is_number(char *str)
{
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
