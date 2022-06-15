#include "monty.h"

/**
 * exit_errors - Creates exit errors
 * @type: Type of the error to be created
 * Return: void
 */
void exit_errors(int type)
{
	switch (type)
	{
	case USAGE_ERR:
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		break;
	case OPEN_FILE_ERR:
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		break;
	case INVALID_OP:
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line, input[0]);
		break;
	case MALLOC_ERR:
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		break;
	case PUSH_ERR:
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line);
		break;
	case POP_ERR:
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line);
		break;
	case PINT_ERR:
		dprintf(STDERR_FILENO, "L%d: can't pint an empty stack\n", line);
		break;
	case SWAP_ERR:
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line);
		break;
	case ADD_ERR:
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line);
		break;
	}
	exit_errors_2(type);
	clean_up();
}

/**
 * clean_up - Performs a clean up on allocated memory and exits the program
 * Return: void
 */

void clean_up(void)
{
	free_double_ptr2(input);
	free_stack(head);
	close(fd);
	exit(EXIT_FAILURE);
}

/**
 * exit_errors_2 - Creates exit errors
 * @type: Type of the error to be created
 * Return: void
 */
void exit_errors_2(int type)
{
	switch (type)
	{
	case SUB_ERR:
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line);
		break;
	case DIV_ERR:
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line);
		break;
	case DIV_BY_ZERO:
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line);
		break;
	case MUL_ERR:
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line);
		break;
	case MOD_ERR:
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line);
		break;
	case PCHAR_ERR:
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack too short\n", line);
		break;
	case PCHAR_OUT_OF_RANGE:
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line);
		break;
	}
	clean_up();
}
