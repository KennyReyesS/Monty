#include "monty.h"

/**
 * push - Check if is integer or and execute the function
 * @num: Integer like char.
 * Return: 0
 */

void push(char *num)
{
	if (num == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", tools.line_number);
		cleanmemory();
		exit(EXIT_FAILURE);
	}

	checkNum(num);
	pushInteger(atoi(num));
}

/**
 * checkNum - checks if a string is a valid number
 * @num: The string to check
 */

void checkNum(char *num)
{
	int i = 0;

	if (num[0] == '-')
		i++;

	for (; num[i]; ++i)
	{
		if (!isdigit(num[i]))
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
				tools.line_number);
			cleanmemory();
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pushInteger - pushes an element to the top of the stack
 * @n: Integer to be pushed
 */

void pushInteger(int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	/*stack_t *tmp = tools.stack;*/

	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		cleanmemory();
		exit(EXIT_FAILURE);
	}

	new->n = n;

	if (!tools.stack)
	{
		new->next = NULL;
		new->prev = NULL;
		tools.stack = new;
	}
	else
	{
		new->next = tools.stack;
		new->prev = NULL;
		tools.stack->prev = new;
		tools.stack = new;
	}
}

/**
 * pall - prints the values on the stack, starting from the top of the stack.
 * description: in assigned mode pall print the stack stored
 * @stack: pointer to the head of the stack.
 * @line_number: The line number
 * Return: 0
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	(void)(line_number);
	if (!*stack)
		return;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
