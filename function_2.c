#include "monty.h"
/**
 * _pall - function that print all elements of a function
 * @stack: pointer to linked list stack
 * @line_number: line opcode number
 */

void _pall(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *print_all = *stack;

	for (; print_all; print_all = print_all->next)
		printf("%d\n", print_all->n);
}

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
