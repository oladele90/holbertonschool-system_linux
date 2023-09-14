#include "multithreading.h"

pthread_mutex_t lock;
void begin(void) __attribute__((constructor));
void end(void) __attribute__((destructor));
/**
 * tprintf - prints formatted string
 * @format: string to print
 * Return: 0
*/
void begin(void)
{
	pthread_mutex_init(&lock, NULL);
}

void end(void)
{
	pthread_mutex_destroy(&lock);
}
int tprintf(char const *format, ...)
{
	pthread_t tid = pthread_self();
	va_list args;

	pthread_mutex_lock(&lock);
	va_start(args, format);
	printf("[%lu]", tid);
	vprintf(args, format);
	va_end(args);
	pthread_mutex_unlock(&lock);
	return (0);
}
