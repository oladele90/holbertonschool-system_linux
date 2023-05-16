#include "laps.h"

void race_state(int *id, size_t size)
{
    static car_list *new;

    if (size == 0)
    {
        free_list(new);
        return;
    }
    if (new == NULL)
    {
        size_t i;
        for (i = 0; i < size; i++)
        {
            add_nodeint(&new, id[i], 0);
            printf("Car %d joined the race\n", new->car);
        }
    }
    else
    {
        size_t i;
        for (i = 0; i < size; i++)
        {
            car_list *temp = new;
            while (temp)
            {
                if (id[i] == temp->car)
                {
                    temp->lap = temp->lap + 1;
                    temp = temp->next;
                    break;
                }
                else if ((id[i] != temp->car) && (temp->next == NULL))
                {
                    add_nodeint(&new, id[i], 0);
                    printf("Car %d joined the race\n", new->car);
                }
                temp = temp ->next;
            }
        }
    }
    printf("Race state:\n");
    print_list(&new);

}

void print_list(car_list **head)
{
    car_list *temp = *head;

    while (temp)
    {
        printf("Car %d [%d laps]\n", temp->car, temp->lap);
		temp = temp->next;
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

void free_list(car_list *head)
{
    car_list *temp;

    while (head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}