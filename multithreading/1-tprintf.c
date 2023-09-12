#include "multithreading.h"

/**
 * tprintf - prints formatted string
 * @format: string to print
 * Return: 0
*/
int tprintf(char const *format, ...)
{
	pthread_t tid = pthread_self();

	printf("[%lu] %s", tid, format);
	return (0);
}
