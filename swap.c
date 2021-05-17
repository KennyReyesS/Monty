#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_number: The line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	int temp = 0;

	if (!h || !h->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		cleanmemory();
		exit(EXIT_FAILURE);
	}
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
