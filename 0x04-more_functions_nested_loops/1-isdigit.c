#include "main.h"
/**
 * _isdigit - checks for a digit
 * @c: The char to be checked
 * *Return: 1 for digit char, otherwise 0
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
