#include "monty.h"
/**
 * pint - print top value of stack
 * @stack: double linked list
 * @line_number: number of the current line
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (tmp->next)
		tmp = tmp->next;
	printf("%d\n", tmp->n);
}

/**
 * pop - deletes the current top of stack
 * @stack: doubly linked list
 * @line_number: number of the current line.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode, *remove;

	newnode = *stack;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (newnode->next == NULL)
	{
		free(newnode);
		*stack = NULL;
	}
	else
		while (newnode->next->next)
			newnode = newnode->next;
	remove = newnode->next;
	newnode->next = NULL;
	free(remove);
}

/**
 * swap - prints top stack value
 * @stack: double linked list
 * @line_number: number of current line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int t;
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (temp->next)
		temp = temp->next;
	if (temp->prev == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	t = temp->n;
	temp->n = temp->prev->n;
	temp->prev->n = t;
}

/**
 * add - prints the top value of the stack.
 * @stack: double linked list
 * @line_number: number of current line
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (temp->next->next)
		temp = temp->next;
	temp->n += temp->next->n;
	pop(stack, line_number);
}
