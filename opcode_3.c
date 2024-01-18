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
	int number;

	(void)line_number;
	if (*stack && (*stack)->next)
	{
		while (temp->next)
		{
			temp = temp->next;
		}
		number = temp->n;
		while (temp->prev)
		{
			temp->n = (temp->prev)->n;
			temp = temp->prev;
		}
		temp->n = number;
	}
}
