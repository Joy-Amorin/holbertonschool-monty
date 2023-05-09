#include "monty.h"
/**
 * push - push an element to the stack
 *  @stack: double linked list
 *  @line_number: number of the current line
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL, *tmp = *stack;
	int num = 0;
	char *numstr = NULL;

	numstr = strtok(NULL, " \t\n");
	if (!numstr || isNumber(numstr) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(numstr);
	new = malloc(sizeof(stack_t));
	if (!new)
		return;
	new->n = num;
	new->next = NULL;

	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
	else
	{
		*stack = new;
		new->prev = NULL;
	}
}

/**
 * pall - prints the values on the stack
 * @stack: double linked list
 * @line_number: number of the current line
 *
 */

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
		return;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
