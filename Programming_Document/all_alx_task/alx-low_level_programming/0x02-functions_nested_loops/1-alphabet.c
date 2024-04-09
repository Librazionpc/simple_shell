#include <stdio.h>
/**
 * print_alphabet - Function that prints the alphabet,
 * in lowercase, followed by a new line.
 *
 * Return: Always 0
 */
void print_alphabet(void)
{
	char a;

	for (a = 'a'; a <= 'z'; a++)
	{
		putchar(a);
	}
putchar('\n');
}
