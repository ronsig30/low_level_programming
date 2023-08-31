#include "main.h"

/**
 * get_bit - prints the value of a bit of an index
 * @n: number to search
 * @index: index of bit
 *
 * Return: value of the bit at index index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;
	int bit_val;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);


	mask = 1UL << index;
	bit_val = (n & mask) ? 1 : 0;

	return (bit_val);
}
