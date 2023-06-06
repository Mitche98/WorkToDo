#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * dog_t *new_dog - function that creates a new dog
 * @name: pointer to name
 * @age: age of dog
 * @owner: pointer to owner
 *
 * Return: 0 (success), otherwise NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int tm, rf, k;
	dog_t *dog;

	if (name == NULL || owner == NULL)
		return (NULL);
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);
	for (tm = 0; name[tm]; tm++)
		;
	tm++;
	dog->name = malloc(tm * sizeof(char));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	for (k = 0; k < tm; k++)
		dog->name[k] = name[k];
	dog->age = age;
	for (rf = 0; owner[rf]; rf++)
		;
	rf++;
	dog->owner = malloc(rf * sizeof(char));
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	for (k = 0; k < rf; k++)
		dog->owner[k] = owner[k];
	return (dog);
}
