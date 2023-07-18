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
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar(0);
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
