#include "main.h"
/*
 * _isupper - Prints uppercase
 * @c: uppercase
 * Return: 1 if upper, otherwise 0
 */
int _isupper(int c)
{
	if (c >= 65 && c  <= 90)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
