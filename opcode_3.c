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

/**
 * recursion - Recursive function to replace the top element of the stack.
 * @temp: Pointer to the current node in the stack.
 * @top: Value to replace the top element with.
 * Return: The value that was replaced.
 */
int recursion(stack_t *temp, int top)
{
	int replace;

	if (!temp->next)
	{
		replace = temp->n;
		temp->n = top;
		return (replace);
	}

	temp = temp->next;
	return (recursion(temp, top));
}
