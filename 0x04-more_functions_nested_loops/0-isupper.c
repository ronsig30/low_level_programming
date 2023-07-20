#include "main.h"
/*
 * _isupper - checks if the input character c is an upper
 *
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
}
