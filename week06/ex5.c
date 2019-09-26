#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
	pid_t p;

	/* forks child */
	p = fork();

	if (p != 0)
	{
		/* waits for 10secs */
		sleep(10);
		kill(p, SIGTERM);
		printf("Parent killed child :(\n");
	} else
	{
		//signal(SIGTERM, kill_child);
		while(1)
		{
			/* prints I'm alive every second */
			printf("I'm alive\n");
			sleep(1);
		}
	}

	return 0;
}