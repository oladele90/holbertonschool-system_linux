#ifndef LAPS_H
#define LAPS_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct list_t
{
	size_t car;
	int lap;
	struct list_t *next;
} car_list;

void check_id(car_list **head, size_t id);
void free_list(car_list *head);
void print_list(car_list **head);
car_list *add_nodeint(car_list **head, const int car, int lap);
void race_state(int *id, size_t size);

#endif
