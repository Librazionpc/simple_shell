#include <stdio.h>
#include "main.h"
/**
 * rot13 - Function for cipher encoding letter
 *
 * @wrd: Funtion the message from C
 *
 * Return: The encoded message or unencoded
 */
char *rot13(char *wrd)
{
	int a, b;
	char chr1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char chr2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvqxyzabcdefghijklm";
	char *out = wrd;

	for (a = 0; wrd[a] != '\0'; a++)
	{
		for (b = 0; b < 52; b++)
		{
			if (wrd[a] == chr1[b])
			{
				wrd[a] = chr2[b];
				break;
			}
		}
	}
	return (out);
}


