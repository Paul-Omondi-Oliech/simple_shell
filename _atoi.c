#include "shell.h"

/**
 * interactive - returns a true value if shell is in an interactive mode
 * @info: structure address
 * Return: 1 (interactive mode) 0 (not interactive)
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Function that checks if a character is a delimeter
 * @b: the character to check
 * @delim: delimeter string
 * Return: 1(true) and 0(false)
 */
int is_delim(char b, char *delim)
{
	while (*delim)
		if (*delim++ == b)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabets
 * @j: The character to be inputed
 * Return: 1 (for alphabets) 0 (non alphabets)
 */

int _isalpha(int j)
{
	if ((j >= 'a' && j <= 'z') || (j >= 'A' && j <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - String to integer converter
 * @s: the string to be converted
 * Return 0 (for no string converted),otherwise return the output.
 */

int _atoi(char *s)
{
	int j, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (j = 0; s[j] != '\0' && flag != 2; j++)
	{
		if (s[j] == '-')
			sign *= -1;

		if (s[j] >= '0' && s[j] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
