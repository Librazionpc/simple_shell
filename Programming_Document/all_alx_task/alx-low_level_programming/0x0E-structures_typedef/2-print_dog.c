#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Funtion that print info of a dog log
 *
 * @d: Fetches the address of the struct
 *
 */

void print_dog(struct dog *d)
{
	if ((d->name) == NULL)
		d->name = "(nill)";
	if ((d->age) == 0)
		d->age = 0;
	if ((d->owner) == NULL)
		d->owner = "(nill)";
	printf("Name: %s\nAge: %f\nOwner: %s\n", d->name, d->age, d->owner);
}
