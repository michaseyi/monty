#ifndef MONTY
#define MONTY
#define MALLOC_FAIL -2
#define USAGE_ERR 0
#define OPEN_FILE_ERR 1
#define INVALID_OP 2
#define MALLOC_ERR 3
#define PUSH_ERR 4
#define PINT_ERR 5
#define POP_ERR 6
#define SWAP_ERR 7
#define ADD_ERR 8
#define SUB_ERR 9
#define DIV_ERR 10
#define DIV_BY_ZERO 11
#define MUL_ERR 12
#define MOD_ERR 13
#define PCHAR_OUT_OF_RANGE 14
#define PCHAR_ERR 15

#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Mode of operation */
char *mode;

/* Line number */
unsigned int line;

/* File fd */
int fd;

/* Linked list head */
stack_t *head;

/* Input val */
char **input;

size_t size;

/* Filename */
char *filename;
/* Opcodes */
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* Util functions */
stack_t *add_node_start(stack_t **head, const int n);
stack_t *add_node_end(stack_t **head, const int n);
int delete_node_at_index(stack_t **head, unsigned int index);
void free_stack(stack_t *head);

/* Input operations */
int _getline(char **buffer, int *len, int fd);
void process_input(char *buffer);
char **_split(char *str, char delim);
size_t len(char **str_arr);
/* Memory operations */
char *_memcpy2(char *dest, char *src, unsigned int n);
void *_realloc1(void *ptr, unsigned int old_size, unsigned int new_size);
void *_realloc2(char **ptr, unsigned int old_size, unsigned int new_size);
void free_double_ptr(char **ptr, int len);
void free_double_ptr2(char **ptr);
char **_memcpy(char **dest, char **src, unsigned int n);

void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number);
void exit_errors(int type);
void clean_up(void);
int is_number(char *str);
void exit_errors_2(int type);
int check_comment(char *buffer);
#endif /* MONTY */
