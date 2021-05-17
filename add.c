#include "monty.h"

/**
 * _add - function add two integer
 * @stack: Stack list
 * @line_number: Number of the line
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	stack_t *node_1 = NULL;
	stack_t *node_2 = NULL;
	int sum = 0;

	if (!h)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		cleanmemory();
		exit(EXIT_FAILURE);
	}
	node_1 = h;
	node_2 = h->next;

	sum = node_1->n + node_2->n;
	node_2->n = sum;
	/* removes the top element of the stack.*/
	pop(stack, line_number);
}
