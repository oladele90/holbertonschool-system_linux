#include "multithreading.h"

void *thread_entry(void *arg)
{
    printf("%s\n", (char *)arg);
    pthread_exit (NULL);
    return(0);
}