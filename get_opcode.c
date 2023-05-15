#include "monty.h"

/**
 * get_opcode - get opcode function
 * @token: name
 *
 * Return: the function or NULL.
 */
void (*get_opcode(char *token))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL},
	};

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(token, ops[i].opcode) == 0)
			return (ops[i].f);
	}
	return (ops[i].f);
}
/**
 * main - main function
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	void (*f)(stack_t **stack, unsigned int line_num);

	FILE *file = NULL;
	char *buffer = NULL, *token = NULL;
	size_t bufsize = 0;
	stack_t *stack = NULL;
	int i = 0;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (!file)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (getline(&buffer, &bufsize, file) != -1)
	{
		i++;
		token = strtok(buffer, " \t\n");
		if (token == NULL || strcmp(token, "nop") == 0 || strcmp(token, "\n") == 0)
			continue;
		f = get_opcode(token);
		if (!f)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", i, token);
			exit(EXIT_FAILURE);
		}
		f(&stack, i);
	}
	free(buffer);
	fclose(file);
	free_stack(stack);
	return (0); }
