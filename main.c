#include "monty.h"
/**
 * check_the_arg - check the argument
 * @args: number of arguments
 * @argv: array of arguments
 * Return: void
*/
stack_t *head = NULL;
int main(int args, char *argv[])
{
	check_the_arg(args, argv);
	check_open_file(argv);
	return (0);
}
