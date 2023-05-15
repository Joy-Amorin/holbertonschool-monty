#include "monty.h"

/**
 * stack_free - function that free the stack
 * @head: head of the list
 */
void stack_free(stack_t *head)
{
	stack_t *now = head, *next = NULL;

	while (now != NULL)
	{
		next = now->next;
		free(now);
		now = next;
	}
}
