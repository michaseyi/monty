#include "monty.h"

/**
 * add_node_start - Adds a new node to the start of the list
 * @head: Pointer to the head of the list
 * @n: value of the new node to be added
 * Return: NULL if memory allocation fails else the address of the newly
 * created nod
 */

stack_t *add_node_start(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
	size++;
	return (new_node);
}

/**
 * add_node_end - Adds a new node to the end of the list
 * @head: Pointer to the head of the list
 * @n: value of the new node to be added
 * Return: NULL if memory allocation fails else the address of the newly
 * created nod
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *new_node, *current = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (current == NULL)
		*head = new_node;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
	size++;
	return (new_node);
}

/**
 * delete_node_at_index - Deletes a node at a given index from the list
 * @head: POinter to the head of the list
 * @index: The index of the node to be removed
 * Return: 1 if it removes the node successfully else -1
 */

int delete_node_at_index(stack_t **head, unsigned int index)
{
	stack_t *current;
	unsigned int i = 0;

	if (head == NULL)
		return (-1);
	current = *head;
	while (current != NULL && i != index)
	{
		i++;
		current = current->next;
	}
	if (current == NULL)
		return (-1);
	if (i == 0)
		*head = current->next;
	current->prev != NULL ? current->prev->next = current->next : NULL;
	current->next != NULL ? current->next->prev = current->prev : NULL;
	size--;
	free(current);
	return (1);
}

/**
 * free_stack - Frees the list
 * @head: Pointer to the head of the list
 * Return: void
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * _split - splits a string by the given delimiter
 * @str: Input string
 * @delim: delimiter
 * Return: An array of pointers or NULL if memory allocation fails to
 * input string is filled with only the delimiter
 */

char **_split(char *str, char delim)
{
	char **ret_val = NULL;
	int i = 0, len = 0, count;

	while (str[i])
	{
		if (str[i] == delim)
		{
			i++;
			continue;
		}
		count = 0;
		while (str[i] != delim && str[i] != 0)
		{
			i++;
			count++;
		}
ret_val = _realloc2(ret_val, sizeof(char *) * len, sizeof(char *) * (len + 1));
		if (ret_val == NULL)
			return (ret_val);
		ret_val[len] = malloc(sizeof(char) * (count + 1));
		if (ret_val[len] == NULL)
		{
			free_double_ptr(ret_val, len);
			return (NULL);
		}
		strncpy(ret_val[len], str + i - count, count);
		ret_val[len][count] = 0;
		len++;
	}
	if (len > 0)
	{
		ret_val = _realloc2(ret_val, sizeof(char *) * len,
								  sizeof(char *) * (len + 1));
		if (ret_val == NULL)
			return (ret_val);
		ret_val[len] = NULL;
	}
	return (ret_val);
}

