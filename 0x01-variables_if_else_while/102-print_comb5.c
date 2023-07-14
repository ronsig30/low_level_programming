#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Succes)
 */
int main(void)
{
	int firstDigit = 0;

	while (firstDigit < 9)
	{
		int secondDigit = firstDigit + 1;

		while (secondDigit < 10)
		{
			putchar(firstDigit + '0');
			putchar(secondDigit + '0');
			if (firstDigit != 8 || secondDigit != 9)
			{
				putchar(',');
				putchar(' ');
			}
			secondDigit++;
		}
		firstDigit++;
	}
	putchar('\n');
	return (0);
}
