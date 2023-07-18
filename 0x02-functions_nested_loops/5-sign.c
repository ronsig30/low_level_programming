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
		_putchar(43);
		return (1);
	}
	else if (n < 0)
	{
		_putchar(45);
		return (-1);
	}
	else
	{
		_putchar(48);
		return (0);
	}
}
