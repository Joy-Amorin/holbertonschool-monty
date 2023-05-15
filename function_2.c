#include "monty.h"
/**
 * _pint - function that print a top of stack only
 * @stack: pointer to linked list stack
 * @line_number: line opcode number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		return;
	}

	printf("%d\n", (*stack)->n);
}

/**
 * _pint - function that print a top of stack only
 * @stack: pointer to linked list stack
 * @line_number: line opcode number
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		return;
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
