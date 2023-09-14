#include "list.h"
#include "multithreading.h"
#include "list.h"

/**
* prime_factors -  factorizes a number into a list of prime factors
* @s: number to factor
* Return: list of factors
*/
list_t *prime_factors(char const *s)
{
	list_t *list = NULL;
	unsigned long num = strtoul(s, NULL, 10), *prime = NULL, i;

	list = malloc(sizeof(list_t));
	list_init(list);

	while (num % 2 == 0)
	{
		prime = malloc(sizeof(unsigned long));
		*prime = 2;
		list_add(list, prime);
		num /= 2;
	}

	for (i = 3; i * i <= num; i++)
	{
		while (num % i == 0)
		{
			prime = malloc(sizeof(unsigned long));
			*prime = i;
			list_add(list, prime);
			num /= i;
		}
	}
	if (num > 2)
	{
		prime = malloc(sizeof(unsigned long));
		*prime = num;
		list_add(list, prime);
	}
	return (list);
}
