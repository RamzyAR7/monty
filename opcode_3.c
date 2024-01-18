#include "monty.h"
/**
 * rotr_opcode - rotates the stack to the bottom
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void rotr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;

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
	else
	{
		fprintf(stderr, "L%d: can't rotr an empty stack\n", line_number);
		if (*stack)
		{
			free_stack(*stack);
		}
		exit(EXIT_FAILURE);
	}
}
