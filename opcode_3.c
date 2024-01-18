#include "monty.h"
/**
 * rotr_opcode - rotates the stack to the bottom
 * @stack: stack
 * @line_number: line number
 * Return: void
*/
void rotr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	while (tmp->next)
	{
		tmp = tmp->next;
	}

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;

	(*stack)->prev = tmp;
	*stack = tmp;
}
