#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	printf("Size of a char: %d byte(s)\n", (unsigned int)sizeof(char));
	printf("Size of an int: %d byte(s)\n", (unsigned int)sizeof(int));
	printf("Size of long int: %d byte(s)\n", (unsigned int)sizeof(long int));
	printf("Size of a long long int: %lu byte(s)\n",sizeof(long long int));
	printf("Size of a float: %d byte(s)\n", (unsigned int)sizeof(float));
	return (0);
}
