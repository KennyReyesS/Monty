#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to the head of the stack
 * @line_number: The line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (!h)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		cleanmemory();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", h->n);
}
