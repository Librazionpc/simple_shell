#ifndef _DOG_H_
#define _DOG_H_

/**
 * struct dog - structure for a basic dog
 *
 * @name: Feches the dog's name
 * @age: Fetches the dog's age
 * @owner: Fetches the owner name
 *
 * Description: data structure for a dog log file
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};
typedef struct dog dog_t;
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif
