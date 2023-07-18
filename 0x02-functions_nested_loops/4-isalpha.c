#include "main.h"
/**
 * _isalpha - Checkes if a character is lower or upper
 * @c: is the char to be checked
 * Return: 1 if c i lower or upper, otherwise returns 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
