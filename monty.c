#include "monty.h"

/**
 * main - Entry point
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *buffer = NULL;
	int length = 0, read_val, can_proceed = 1;

	head = NULL, input = NULL, mode = "stack", size = 0, line = 0;
	if (argc != 2)
		exit_errors(USAGE_ERR);
	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_errors(OPEN_FILE_ERR);
	while (can_proceed)
	{
		read_val = _getline(&buffer, &length, fd);
		line++;
		if (read_val == MALLOC_FAIL)
			exit_errors(MALLOC_ERR);
		else if (read_val == EOF)
			can_proceed = 0;
		if (length > 0)
			process_input(buffer);
	}
	close(fd);
	free_stack(head);
	return (EXIT_SUCCESS);
}

/**
 * check_comment - Checks for comments in the input buffer
 * @buffer: Input buffer
 * Return: 1 if comment else 0
 */

int check_comment(char *buffer)
{
	int i = 0;

	while (buffer[i] && buffer[i] == ' ')
		i++;
	if (buffer[i] == '#' || buffer[i] == 0)
		return (1);
	return (0);
}

/**
 * process_input - Process each line gotten from the input file and calls
 * the appropriate function to handle them
 * @buffer: Input buffer
 * Return: void
 */

void process_input(char *buffer)
{
	char **split_val;
	void (*f)(stack_t **stack, unsigned int line_number);

	if (check_comment(buffer))
	{
		free(buffer);
		return;
	}
	split_val = _split(buffer, ' ');
	free(buffer);
	if (split_val == NULL)
		exit_errors(MALLOC_ERR);
	input = split_val;
	f = get_func(split_val[0]);
	if (f == NULL)
		exit_errors(INVALID_OP);
	f(&head, line);
	input = NULL;
	free_double_ptr2(split_val);
}

/**
 * get_func - Gets the appropriate function to handle an input command
 * @opcode: Input opcode
 * Return: Returns the right function to handle the opcode or NULL if no
 * function matches the opcode
 */
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instructions[] = {{"push", push}, {"rotr", rotr},
	{"sub", sub}, {"pchar", pchar}, {"rotl", rotl}, {"mod", mod},
	{"pstr", pstr}, {"mul", mul}, {"div", divide}, {"nop", nop},
	 {"add", add}, {"pall", pall}, {"pop", pop}, {"pint", pint},
	  {"stack", stack}, {"queue", queue}, {"swap", swap}, {NULL, NULL}};

	while (instructions[i].opcode)
	{
		if (!strcmp(instructions[i].opcode, opcode))
			break;
		i++;
	}
	return (instructions[i].f);
}
