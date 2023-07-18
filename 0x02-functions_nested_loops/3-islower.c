#include "main.h"
/**
 *  _islower - Checking characters in lower case
 * @c: is the char to be checked
 *  Return: 1 if c is lower, otherwise return 0
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
