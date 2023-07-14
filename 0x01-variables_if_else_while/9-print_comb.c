#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int number = 0;

	while (number < 10)
	{
		putchar((number % 10) + '0');
	}
	if (number != 9)
	{
		putchar(',');
		putchar(' ');
	}
	number++;
	putchar('\n');
	return (0);
}







