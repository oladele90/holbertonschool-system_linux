#include <signal.h>
#include <stdio.h>

/**
* pid_exist - check if a pid exist
* @pid: process id
* Return: 1 or 0
*/
int pid_exist(pid_t pid)
{
	return ((kill(pid, 0) == 0) ? 1 : 0);
}
