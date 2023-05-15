#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination to copy the string to
 *@src: Source string
 *@n: Amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j, k;
	char *s = dest;

	j = 0;
	while (src[j] != '\0' && j < n - 1)
	{
		dest[j] = src[j];
		j++;
	}
	if (j < n)
	{
		k = j;
		while (j < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}
/**
 **_strncat - concatenates two strings
 *@dest: the first string(deststination)
 *@src: Second string(to be concatenated)
 *@n: Amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int j, k;
	char *s = dest;

	j = 0;
	k = 0;
	while (dest[j] != '\0')
		j++;
	while (src[k] != '\0' && k < n)
	{
		dest[j] = src[k];
		j++;
		k++;
	}
	if (k < n)
		dest[j] = '\0';
	return (s);
}
/**
 **_strchr - locates a character in the string
 *@s: the string to be parsed
 *@c: the character to be located
 *Return: (s), a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
