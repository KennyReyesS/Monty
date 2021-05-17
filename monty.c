#include "monty.h"

tools_t tools;
/**
 * main - Monty interpreter
 * Description: executes file scripts with built-in code
 * @argc: argument counter
 * @argv: argument values
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	FILE *file;
	char *opcode;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	tools.file = file;

	while ((getline(&line, &len, file)) != -1)
	{
		tools.line_number++;

		opcode = strtok(line, " \t\n");
		if (!opcode)
			continue;
		if (strcmp(opcode, "push") == 0)
			push(strtok(NULL, " \t\n"));
		else
			executeFun(opcode, tools.line_number);
	}
	free(line);
	cleanmemory();
	return (EXIT_SUCCESS);
}

/**
 * executeFun - check in the list if the command exist and execute function
 * @opcode: string of char.
 * @line_number: The line number.
 */

void executeFun(char *opcode, unsigned int line_number)
{
	int i;

	instruction_t funcs[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; funcs[i].opcode != NULL; i++)
	{
		if (strcmp(funcs[i].opcode, opcode) == 0)
		{
			funcs[i].f(&tools.stack, line_number);
			return;
		}
	}
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, opcode);
	cleanmemory();
	exit(EXIT_FAILURE);
}
