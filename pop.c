#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: The line number.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (h == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		cleanmemory();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	free(h);
	if (*stack)
		(*stack)->prev = NULL;
}
