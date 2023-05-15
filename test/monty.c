#include "monty.h"

/**
 * main - function for monty program
 * @ac: num of arguments
 * @of: opcode file
 * Return: Always 0
 */

int main(int ac, char **of)
{
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	opfile(of[1], &stack);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
