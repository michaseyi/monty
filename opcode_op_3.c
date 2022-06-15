#include "monty.h"

/**
 * mod - Performs the mod operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void mod(stack_t **stack,  __attribute__((unused))unsigned int line_number)
{
	if (size < 2)
		exit_errors(MOD_ERR);
	else
	{
		if ((*stack)->n == 0)
			exit_errors(DIV_BY_ZERO);
		else
		{
			(*stack)->next->n %= (*stack)->n;
			delete_node_at_index(stack, 0);
		}
	}
}

/**
 * pstr - Performs the pstr operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void pstr(stack_t **stack,  __attribute__((unused))unsigned int line_number)
{
	stack_t *current = *stack;
	int temp;

	while (current != NULL)
	{
		temp = current->n;
		if (temp > 0 && temp <= 127)
			putchar(temp);
		else
			break;
		current = current->next;
	}
	putchar(10);
}

/**
 * pchar - Performs the pchar operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void pchar(stack_t **stack,  __attribute__((unused))unsigned int line_number)
{
	int temp;

	if (size == 0)
		exit_errors(PCHAR_ERR);
	temp = (*stack)->n;
	if (temp >= 0 && temp <= 127)
	{
		putchar(temp);
		putchar(10);
	}
	else
		exit_errors(PCHAR_OUT_OF_RANGE);
}

/**
 * stack - Change operation mode to stack
 * @stack_: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void stack(__attribute__((unused))stack_t **stack_,  __attribute__((unused))
unsigned int line_number)
{
	mode = "stack";
}
/**
 * queue - Change operation mode to queue
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void queue(__attribute__((unused))stack_t **stack,  __attribute__((unused))
unsigned int line_number)
{
	mode = "queue";
}
