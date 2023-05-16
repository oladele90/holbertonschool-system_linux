#include "laps.h"

void race_state(int *id, size_t size)
{
    static car_list *new;
    if (new == NULL)
    {
        size_t i;
        for (i = 0; i < size; i++)
        {
            add_nodeint(&new, id[i], 0);
            printf("%d %d \n", new->car, new->lap);
        }
    }
}



car_list *add_nodeint(car_list **head, const int car, int lap)
{
	car_list *front;


	front = malloc(sizeof(car_list));
	if (!front)
	{
		free(front);
		return (NULL);
	}
	front->car = car;
    front->lap = lap;
	front->next = *head;
	*head = front;
	return (front);
}