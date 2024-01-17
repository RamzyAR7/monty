#include "monty.h"
/**
 * check_the_arg - check the argument
 * @args: number of arguments
 * Return: void
*/
void check_the_arg(int args)
{
	if (args != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * check_open_file - check open file
 * @argv: array of arguments
 * Return: void
*/
void check_open_file(char *argv[])
{
	char line[bufsize];
	size_t num_line = 0;

	char *chank;
	FILE *fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		num_line++;
		chank = strtok(line, " \t\n");
		if (chank != NULL)
		{
			check_on_chank(chank, num_line);
		}
	}
	fclose(fp);
}
/**
 * check_on_chank - check on chank
 * @chank: chank
 * @num_line: number of line
 * Return: void
*/
void check_on_chank(char *chank, int num_line)
{
	int i, idx = 0;
	instruction_t arr[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{"nop", nop_opcode},
		{NULL, NULL}};

	for (i = 0; arr[i].opcode; i++)
	{
		if (strcmp(chank, arr[i].opcode) == 0)
		{
			idx = 1;
			arr[i].f(&head, (unsigned int)num_line);
		}
	}
	if (idx == 0)
	{
		printf("L%d: unknown instruction %s\n", num_line, chank);
		exit(EXIT_FAILURE);
	}
}
