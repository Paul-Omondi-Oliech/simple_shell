#include "shell.h"

/**
 * is_chain - tests if the current character in the buffer is a chain delimeter
 * @info: the parameter structure
 * @buf: the character buffer
 * @p: the address of the current position in the buffer
 * Return: 1 if it is a chain delimeter and 0 if not
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t n = *p;

	if (buf[n] == '|' && buf[n + 1] == '|')
	{
		buf[n] = 0;
		n++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[n] == '&' && buf[n + 1] == '&')
	{
		buf[n] = 0;
		n++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[n] == ';')
	{
		buf[n] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = n;
	return (1);
}

/**
 * check_chain - checks if there is continued chaining based on the last status
 * @info: the parameter structure
 * @buf: the character buffer
 * @p: the address of the current position in the buffer
 * @j: starting position in the buffer
 * @len: the length of the buffer
 * Return: nothing
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t j, size_t len)
{
	size_t n = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[j] = 0;
			n = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[j] = 0;
			n = len;
		}
	}

	*p = n;
}

/**
 * replace_alias - replaces an alias in the tokenized string
 * @info: the parameter structure
 * Return: 1 if an alias is replaced and 0 if not
 */
int replace_alias(info_t *info)
{
	int j;
	list_t *node;
	char *p;

	for (j = 0; j < 10; j++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @info: the parameter structure
 * Return: 1 if the vars is replaced and 0 if not
 */
int replace_vars(info_t *info)
{
	int j = 0;
	list_t *node;

	for (j = 0; info->argv[j]; j++)
	{
		if (info->argv[j][0] != '$' || !info->argv[j][1])
			continue;

		if (!_strcmp(info->argv[j], "$?"))
		{
			replace_string(&(info->argv[j]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[j], "$$"))
		{
			replace_string(&(info->argv[j]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[j][1], '=');
		if (node)
		{
			replace_string(&(info->argv[j]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[j], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces a string
 * @old: the address of the old string
 * @new: the new string
 *
 * Return: 1 if the string is replaced and 0 if not
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
