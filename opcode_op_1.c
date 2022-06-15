#include "monty.h"

/**
 * pall - Performs the pall operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void pall(stack_t **stack,  __attribute__((unused))unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * push - Performs the push operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int val;
	stack_t *res;

	if (len(input) < 2 || !is_number(input[1]))
		exit_errors(PUSH_ERR);
	val = atoi(input[1]);
	if (!strcmp("stack", mode))
		res = add_node_start(stack, val);
	else
		res = add_node_end(stack, val);
	if (res == NULL)
		exit_errors(MALLOC_ERR);
}

/**
 * pint - Performs the pint operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void pint(stack_t **stack,  __attribute__((unused))unsigned int line_number)
{
	if ((*stack) != NULL)
		printf("%d\n", (*stack)->n);
	else
		exit_errors(PINT_ERR);
}

/**
 * pop - Performs the pop operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void pop(stack_t **stack,  __attribute__((unused))unsigned int line_number)
{
	if (delete_node_at_index(stack, 0) == -1)
		exit_errors(POP_ERR);
}

/**
 * swap - Performs the swap operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void swap(stack_t **stack,  __attribute__((unused))unsigned int line_number)
{
	int temp;

	if (size < 2)
		exit_errors(SWAP_ERR);
	else
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
}
