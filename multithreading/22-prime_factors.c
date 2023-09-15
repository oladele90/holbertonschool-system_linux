#include "multithreading.h"
#include "list.h"

/**
* create_task - creates a thread task
* @entry:  is a pointer to the entry function of the task
* @param: parameter that will later be passed to the entry function
*Return: pointer to the created task structure
*/

task_t *create_task(task_entry_t entry, void *param)
{
	task_t *task;

	task = calloc(1, sizeof(task_t));
	task->status = PENDING;
	task->param = param;
	task->entry = entry;
	task->result = NULL;
	pthread_mutex_init(&task->lock, NULL);
	return (task);

}

/**
* destroy_task - clears & destroys task struct
* @task: task struct
* Return: none
*/

void destroy_task(task_t *task)
{
	if (task->result != NULL)
	{
		list_destroy(task->result, free);
		free(task->result);
		task->result = NULL;
		free(task);
	}
}

/**
* exec_tasks - executes task
* @tasks: list of tasks to execute
* Return: none
*/

void *exec_tasks(list_t const *tasks)
{
	task_t *task = NULL;
	node_t *node = NULL;
	int i = 0;

	node = tasks->head;
	while (node)
	{
		task = node->content;

		if (pthread_mutex_trylock(&task->lock))
			continue;
		if (task->status == PENDING)
		{
			task->status = STARTED;
			tprintf("[%02d] Started\n", i);
			task->result = task->entry(task->param);
			tprintf("[%02d] Success\n", i);
			if (task->result == NULL)
				task->status = FAILURE;
			else
				task->status = SUCCESS;
		}
		pthread_mutex_unlock(&task->lock);
		node = (node_t *) node->next;
		i++;
	}
	return (NULL);
}
