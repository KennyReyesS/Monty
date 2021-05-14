#include "monty.h"

/**
 * cleanmemory - free a stack
 * Return: 0
 */

void cleanmemory(void)
{
	stack_t *tmp;

	while (tools.stack)
	{
		tmp = tools.stack->next;
		free(tools.stack);
		tools.stack = tmp;
	}
	fclose(tools.file);
}
