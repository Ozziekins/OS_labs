#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

/* function to declare all signal handlers */
void sig_handler(int sig_num)
{
	if (sig_num == SIGKILL)
	{
		printf("NOTIFICATION: SIGKILL is being intercepted!\n");
	} else if (sig_num == SIGSTOP)
	{
		printf("NOTIFICATION: SIGSTOP is being intercepted!\n");
	} else if (sig_num == SIGUSR1)
	{
		printf("NOTIFICATION: SIGUSR1 is being intercepted!\n");
	}
}

int main()
{
	/* conditions to catch the signals */
	if (signal(SIGKILL, sig_handler) == SIG_ERR)
	{
		printf("Can't catch SIGKILL :(\n");
	}
	if (signal(SIGSTOP, sig_handler) == SIG_ERR)
	{
		printf("Can't catch SIGSTOP :(\n");
	}
	if (signal(SIGUSR1, sig_handler) == SIG_ERR)
	{
		printf("Can't catch SIGUSR1 :(\n");
	}

	/* loop infintely */
	while(1)
	{
	}

	return 0;
}