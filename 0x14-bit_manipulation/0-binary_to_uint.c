#include "main.h"
/**
 * binary_to_uint - Converts a binary number to an unsigned integer.
 * @b: Pointer to a binary string (0 and 1 chars)
 *
 * Return: The converted number, or 0 if there is an invalid
 * character in the string or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i = 0;

	if (b == NULL)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		result = result * 2 + (b[i] - '0');
		i++;
	}
	return (result);
}
