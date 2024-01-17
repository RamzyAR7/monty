#include "monty.h"
/**
 * add_opcode - adds the top two elements of the stack
 * @stack: stack
 * @line_number: line number
*/
void add_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack && (*stack)->next)
	{
		((*stack)->next)->n = (*stack)->n + ((*stack)->next)->n;
		*stack = (*stack)->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		if (!(*stack))
		{
			free_stack(*stack);
		}
		exit(EXIT_FAILURE);
	}
}
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
