#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - Function that create a dog log book
 *
 * @name: Fetches the name of the dog
 * @age: Fetches the age of the dog
 * @owner: Fetches the owner name
 *
 * Return: The the newdog log
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *log_book;
	char *_name, *_owner;
	int len_name, len_owner, i;

	if (name == NULL || owner == NULL)
		return (NULL);
	len_name = strlen(name);
	len_owner = strlen(owner);
	log_book = malloc(sizeof(dog_t));
	if (log_book == NULL)
	{
		free(log_book);
		return (NULL);
	}
	_name = malloc(len_name + 1);
	if (_name == NULL)
	{
		free(_name);
		return (NULL);
	}
	for (i = 0 ; name[i]; i++)
		_name[i] = name[i];
	_name[i] = '\0';
	_owner = malloc(len_owner + 1);
	if (_owner == NULL)
	{
		free(_owner);
		return (NULL);
	}

	for (i = 0; owner[i]; i++)
		_owner[i] = owner[i];
	_owner[i] = '\0';
	log_book->name = _name;
	log_book->age = age;
	log_book->owner = _owner;
	return (log_book);
}
