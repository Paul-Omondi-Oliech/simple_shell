#include "shell.h"

/**
 * check_for_builtins - checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function or NULL
 */
void (*check_for_builtins(vars_t *vars))(vars_t *vars)
{
	unsigned int j;
	builtins_t check[] = {
		{"exit", new_exit},
		{"env", _env},
		{"setenv", new_setenv},
		{"unsetenv", new_unsetenv},
		{"help", new_help},
		{"cd", new_cd},
		{"history", read_textfile},

		{NULL, NULL}};

	for (j = 0; check[j].f != NULL; j++)
	{

		if (_strcmpr(vars->array_tokens[0], check[j].name) == 0)
			break;
	}
	if (check[j].f != NULL)
		check[j].f(vars);
	return (check[j].f);
}

/**
 * new_exit - exit program
 * @vars: variables
 * Return: nothing
 */
void new_exit(vars_t *vars)
{

	int status;

	if (_strcmpr(vars->array_tokens[0], "exit") ==
			0 &&
		vars->array_tokens[1] != NULL)

	{

		status = _atoi(vars->array_tokens[1]);

		if (status == -1)
		{
			vars->status = 2;
			prints_error_msg(vars, ": Illegal number: ");
			print_message(vars->array_tokens[1]);
			print_message("\n");
			return;
		}
		vars->status = status;
	}
	free(vars->commands);
	free(vars->array_tokens);
	free_env(vars->env);
	free(vars->buffer);
	exit(vars->status);
}

/**
 * _env - prints the current environment
 * @vars: struct of variables
 * Return: nothing
 */
void _env(vars_t *vars)
{
	unsigned int j;

	for (j = 0; vars->env[j]; j++)
	{
		_puts(vars->env[j]);
		_puts("\n");
	}
	vars->status = 0;
}
