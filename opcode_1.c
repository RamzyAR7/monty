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
