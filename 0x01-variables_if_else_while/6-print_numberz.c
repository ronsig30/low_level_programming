#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;
	int count = 0;

	while (i < 10)
	{
		count++;
		i++;
	}
	putchar(count + '0');
	putchar('\n');
	return (0);
}
