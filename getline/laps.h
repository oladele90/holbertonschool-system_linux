#ifndef LAPS_H
#define LAPS_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct list_t {
    int car;
    int lap;
    struct list_t *next;
} car_list;

void free_list(car_list *head);
void print_list(car_list **head);
car_list *add_nodeint(car_list **head, const int car, int lap);
void race_state(int *id, size_t size);

#endif