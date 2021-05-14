#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct tools_s
{
	FILE *file;
	char *opcode;
	unsigned int line_number;
	stack_t *stack;
} tools_t;

extern tools_t tools;

void executeFun(char *opcode, unsigned int line_number);
void push(char *num);
void pushInteger(int n);
void checkNum(char *num);
void cleanmemory(void);
void pall(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int l);

#endif
