#include "multithreading.h"

static pthread_mutex_t lock;
void begin(void) __attribute__((constructor));
void end(void) __attribute__((destructor));

/**
* begin - initialize lock
*/
void begin(void)
{
	pthread_mutex_init(&lock, NULL);
}

/**
* end - destroy lock
*/
void end(void)
{
	pthread_mutex_destroy(&lock);
}

/**
 * tprintf - prints formatted string
 * @format: string to print
 * Return: 0
*/
int tprintf(char const *format, ...)
{
	pthread_t tid = pthread_self();
	va_list args;

	pthread_mutex_lock(&lock);
	va_start(args, format);
	printf("[%lu] ", tid);
	vprintf(format, args);
	va_end(args);
	pthread_mutex_unlock(&lock);
	return (0);
}
