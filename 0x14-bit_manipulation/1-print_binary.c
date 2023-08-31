#include "main.h"

/**
 * print_binary - Prints binary (decimal number)
 * @n: Number to print in binary
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current;
	int num_bits = sizeof(n) * 8;

	for (i = num_bits - 1; i >= 0; i--)
	{
		current = n >> i;

		if (current & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
