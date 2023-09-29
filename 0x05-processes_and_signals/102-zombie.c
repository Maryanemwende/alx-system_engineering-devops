#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * infinite_while - creates an infinite while loop
 * Return: 0 (Success)
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - program that creates 5 zombie processes
 *
 * Return: 0 (Success)
 */
int main(void)
{
	char times = 0;
	pid_t pid;

	while (times < 5)
	{
		pid = fork();
		if (pid > 0)
		{
			printf("Zombie process created, PID: %d\n", pid);
			sleep(1);
			times++;
		}
		else
		{
			exit(0);
		}
	}
	infinite_while();
	return (EXIT_SUCCESS);
}
