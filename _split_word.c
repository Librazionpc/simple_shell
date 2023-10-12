#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
 
int count_words(char *string, char dil)
{
	int no_of_words = 0;

	if (string == NULL || strlen(string) == 0)
		return (0);
	if (*string != dil)
		no_of_words++;
	while (*string != '\0')
	{
		if (*string == dil && *(string + 1) != dil)
			no_of_words++;
		string++;
	}
	return (no_of_words);
}

int lenght_of_word(char *string, char dil)
{
	int lenght = 0;

	if (string == NULL)
		return (lenght);
	while (*string != dil && *string != '\0')
	{
		lenght++;
		string++;
	}
	return (lenght);
}

char *copy_word_to_buffer(char **string, int lenght, char dil)
{
	int i = 0;

	char *buffer = (char *)malloc(sizeof(char) * (lenght + 1));

	while (**string != dil && **string != '\0')
	{
		*(buffer + i) = **string;
		i++;
		*string += 1;
	}
	buffer[i] = '\0';
	return (buffer);
}

char **split_to_string(char *string, char dil)
{
	char **string_array, *buffer;
	int number_of_words, i = 0, index = 0;
	int lenght_of_words;

	if (string == NULL || *string == '\0')
		return (NULL);
	number_of_words = count_words(string, dil);
	if (number_of_words == 0)
		return (NULL);
	string_array = (char **)malloc(sizeof(char *) * (number_of_words + 1));
	if (string_array == NULL)
		return (NULL);
	while (*string != '\0')
	{
		if ((*string == dil && *(string + 1) != dil && *(string + 1) != '\0')
					|| (index == 0 && string[index] != dil))
		{
			if (*string == dil)
				string++;
			lenght_of_words = lenght_of_word(string, dil);
			buffer = copy_word_to_buffer(&string, lenght_of_words, dil);
			string_array[i] = buffer;
			i++;
		}
		else
			string++;
		index++;
	}
	string_array[i] = NULL;
	return (string_array);
}

void free_array_of_strings(char **array_of_strings)
{
	int i = 0;
	while (array_of_strings[i] != NULL)
	{
		printf("free memory\n");
		free(array_of_strings[i]);
		i++;
	}
	free(array_of_strings);
}

