#include "shell.h"
/**
 * _eputs - prints an inputed string
 * @str: the string to print
 * Return: void(nothing)
 */
void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}
/**
 * _eputchar - writes the character c to stderr
 * @b: The character to be printed on the stdoutput
 * Return: 1 on success
 * On error, return -1, and an errno is set appropriately.
 */
int _eputchar(char b)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (b == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (b != BUF_FLUSH)
		buf[j++] = b;
	return (1);
}
/**
 * _putfd - writes the character c to a given file descriptor
 * @b: The character to print
 * @fd: The filedescriptor to be writen to
 * Return: 1 on success
 * On error, return -1 and an errno is set appropriately.
 */
int _putfd(char b, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (b == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (b != BUF_FLUSH)
		buf[j++] = b;
	return (1);
}
/**
 * _putsfd - prints an inputed string
 * @str: the string to print
 * @fd: the filedescriptor to be writen to
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += _putfd(*str++, fd);
	}
	return (j);
}
