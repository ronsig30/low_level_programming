#include "main.h"
/**
 * print_sign - Entry point
 * @n: is the int to be cheked
 * Return: 0 if n is zero or + if is greater or -  less
 */
int print_sign(int n)
{
	if (n > 0)
	{
		return ('+');
	}
	else if (n < 0)
	{
		return ('-');
	}
	else
	{
		return (0);
	}
}
