#include "monty.h"
/**
 * rotr_opcode - rotates the stack to the bottom
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void rotr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	(*stack)->n = recursion(temp, (*stack)->n);
}

int recursion(stack_t *temp, int top)
{
	int replace;

	if (!temp->next)
	{
		replace = temp->n;
		temp->n = top;
		return replace;
	}

	temp = temp->next;
	return recursion(temp, top);
}
