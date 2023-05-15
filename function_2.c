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
