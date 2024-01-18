#include "monty.h"
/**
 * div_opcode - divides the second top of the stack by the top of the stack
 * @stack: stack
 * @line_number: line number
*/
void div_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			if (stack)
			{
				free_stack(*stack);
			}
			exit(EXIT_FAILURE);
		}
		((*stack)->next)->n = ((*stack)->next)->n / (*stack)->n;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		if (*stack)
		{
			free_stack(*stack);
		}
		exit(EXIT_FAILURE);
	}
}
/**
 * mul_opcode - multiplies the second top of
 *  the stack with the top of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
*/
void mul_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack && (*stack)->next)
	{
		((*stack)->next)->n = (*stack)->n * ((*stack)->next)->n;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		if (*stack)
		{
			free_stack(*stack);
		}
		exit(EXIT_FAILURE);
	}
}
/**
 * mod_opcode - computes rest of division
 * @stack: stack
 * @line_number: line number
*/
void mod_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			if (*stack)
			{
				free_stack(*stack);
			}
			exit(EXIT_FAILURE);
		}
		((*stack)->next)->n = ((*stack)->next)->n % (*stack)->n;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		if (*stack)
		{
			free_stack(*stack);
		}
		exit(EXIT_FAILURE);
	}
}
