#include "monty.h"

/**
 * add - Performs the add operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void add(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (size < 2)
		exit_errors(ADD_ERR);
	else
	{
		(*stack)->next->n += (*stack)->n;
		delete_node_at_index(stack, 0);
	}
}

/**
 * nop - Does nothing
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void nop(__attribute__((unused)) stack_t **stack, __attribute__((unused))
unsigned int line_number)
{
	/* Does Nothing */
}

/**
 * sub - Performs the sub operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void sub(stack_t **stack,  __attribute__((unused))unsigned int line_number)
{
	if (size < 2)
		exit_errors(SUB_ERR);
	else
	{
		(*stack)->next->n -= (*stack)->n;
		delete_node_at_index(stack, 0);
	}
}

/**
 * divide - Performs the div operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void divide(stack_t **stack,  __attribute__((unused))unsigned int line_number)
{
	if (size < 2)
		exit_errors(DIV_ERR);
	else
	{
		if ((*stack)->n == 0)
			exit_errors(DIV_BY_ZERO);
		else
		{
			(*stack)->next->n /= (*stack)->n;
			delete_node_at_index(stack, 0);
		}
	}
}

/**
 * mul - Performs the mul operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void mul(stack_t **stack,  __attribute__((unused))unsigned int line_number)
{
	if (size < 2)
		exit_errors(MUL_ERR);
	else
	{
		(*stack)->next->n *= (*stack)->n;
		delete_node_at_index(stack, 0);
	}
}
