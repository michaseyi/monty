#include "monty.h"

/**
 * rotl - Performs the rotl operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int temp;

	if (size == 0)
		return;
	temp = (*stack)->n;
	delete_node_at_index(stack, 0);
	add_node_end(stack, temp);
}
/**
 * rotr - Performs the rotr operation on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: curent line number
 * Return: void
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int temp;
	stack_t *current;

	if (size == 0)
		return;

	current = *stack;
	while (current->next != NULL)
		current = current->next;
	temp = current->n;
	delete_node_at_index(stack, size - 1);
	add_node_start(stack, temp);
}
