#include <stdio.h>
#include "dog.h"

/**
 * init_dog - Function that create a struct for a dog log
 *
 * @d: Fetches the name of the dog
 * @name: Fetches the name of the dog
 * @age: Fetches the name of the dog
 * @owner: Fetches the name of the owner
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
