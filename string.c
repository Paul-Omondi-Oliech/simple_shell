#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length is to be checked
 * Return: integer length of the string
 */
int _strlen(char *s)
{
	int j = 0;

	if (!s)
		return (0);

	while (*s++)
		j++;
	return (j);
}

/**
 * _strcmp - performs comparison between two strangs.
 * @s1: the first string
 * @s2: the second string
 * Return: a negative if s1 < s2 and
 * a positive if s1 > s2 or zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if a pencil starts with a haystack
 * @haystack: string to be searched
 * @pencil: the substring to be found
 * Return: address of the next char of the haystack or NULL
 */
char *starts_with(const char *haystack, const char *pencil)
{
	while (*pencil)
		if (*pencil++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 * Return: a pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
