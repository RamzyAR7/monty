#include "monty.h"
/**
 * nop_opcode - opcode nop
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void nop_opcode(stack_t **stack, unsigned int line_number)
{
	(void)**stack;
	(void)line_number;
}
/**
 * free_stack - free stack
 * @stack: stack
 * Return: void
*/
void free_stack(stack_t *stack)
{
	stack_t *tmp = stack;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
