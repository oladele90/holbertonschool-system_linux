#include "list.h"
#include "multithreading.h"

list_t *prime_factors(char const *s)
{
    unsigned long num = atoi(s), prime = 2;
    list_t *list = NULL;
    list_init(list);

    while (num != 0)
    {
        if ((num % prime) == 0)
        {
            list_add(list, (void *)prime);
            num = (num / prime);
        }
        else 
            find_next_prime((prime + 1), num);
    }
    print_lists(list->head);
    return (list);

}

unsigned long find_next_prime(unsigned long prime, unsigned long num)
{
    unsigned long i;
    
    for (; prime != num; prime++)
    {
        for (i = 2; i < prime; i++)
        {
            if ((prime % i) == 0)
                break;
        }
        if (i == prime)
            return (prime);
        prime++;
    }
    return (0);
}