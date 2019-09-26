#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/* function to intercept the SIGINT signal */
void sigint_notifier(int sig_num)
{
	char c;

	printf("Do you really want to interrupt?\ny or n?\n");

	c = getchar();

	if (c == 'y')
	{
		exit(0);
	} else
	{
		printf("NOTIFICATION: (Ctrl+C) is being intercepted!!!\n");
		fflush(stdout);
	}
}

int main()
{
	/* system call to handle the signal */
	signal(SIGINT, sigint_notifier);

	/* loop infinitely */
	while(1)
	{
	}

	return 0;
}