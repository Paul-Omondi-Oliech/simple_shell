#include "shell.h"

/**
 * **strtow - splits a string into words. The repeated delimiters are ignored
 * @str: string to be inputed
 * @d: delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int j, k, m, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (j = 0; str[j] != '\0'; j++)
		if (!is_delim(str[j], d) && (is_delim(str[j + 1], d) || !str[j + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (j = 0, k = 0; k < numwords; k++)
	{
		while (is_delim(str[j], d))
			j++;
		m = 0;
		while (!is_delim(str[j + m], d) && str[j + m])
			m++;
		s[k] = malloc((m + 1) * sizeof(char));
		if (!s[k])
		{
			for (m = 0; m < k; m++)
				free(s[m]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < m; n++)
			s[k][n] = str[j++];
		s[k][n] = 0;
	}
	s[k] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: string to be inputed
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int j, k, m, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (j = 0; str[j] != '\0'; j++)
		if ((str[j] != d && str[j + 1] == d) ||
				    (str[j] != d && !str[j + 1]) || str[j + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (j = 0, k = 0; k < numwords; k++)
	{
		while (str[j] == d && str[j] != d)
			j++;
		k = 0;
		while (str[j + m] != d && str[j + m] && str[j + m] != d)
			m++;
		s[k] = malloc((m + 1) * sizeof(char));
		if (!s[k])
		{
			for (m = 0; m < k; m++)
				free(s[m]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < m; n++)
			s[k][n] = str[j++];
		s[k][n] = 0;
	}
	s[k] = NULL;
	return (s);
}
