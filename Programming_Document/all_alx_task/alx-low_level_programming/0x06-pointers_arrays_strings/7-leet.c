#include <stdio.h>
#include "main.h"
/**
 * leet - Function that changes some strings to integer
 *
 * @wrd: Fetches the argument
 *
 * Return: Returns the output
 */
char *leet(char *wrd)
{
	int a = 0, b;
	char subs[10] = {'4', '4', '3', '3', '0', '0', '7', '7', '1', '1'};
	char chr[10] = {'a', 'A', 'e', 'E', 'o', 'O', 't', 'T', 'l', 'L'};

	while (wrd[a])
	{
		for (b = 0; b < 10; b++)
			if (wrd[a] == chr[b])
				wrd[a] = subs[b];
		a++;
	}
	return (wrd);
}
