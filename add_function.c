#include "shell.h"

/**
 * print_cd_1 - Prints error when cd argument is invalid.
 * @vars: vars parameter to be included
 * Return: return nothing and print an apropriate message.
 */
void print_cd_1(vars_t *vars)
{
	print_str("-bash: cd: ", 1);
	print_str(vars->array_tokens[1], 1);
	print_str(": invalid option", 0);
	print_str("cd: usage: cd [-] [--]", 0);
}

/**
 * print_cd_2 - Prints error message when cd argument does not exist.
 * @vars: The parameter to included
 * Return: return nothing and print a message.
 */
void print_cd_2(vars_t *vars)
{
	print_str("-bash: cd: ", 1);
	print_str(vars->array_tokens[1], 1);
	print_str(": Not a directory", 0);
}
