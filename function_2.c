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

/**
 * _swap - function that swap a top of and second top from stack
 * @stack: pointer to linked list stack
 * @line_number: line opcode number
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return;
	}

	int tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

