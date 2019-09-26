#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	int fd[2];
	pid_t p, q;
	int status = 0;

	if (pipe(fd) < 0)
	{
		exit(1);
	}

	/* create child process one */
	p = fork();

	if (p > 0)
	{
		/* create child process two */
		q = fork();
		if (q == 0)
		{
			//child two
		}
		else
		{
			/* sending 2nd child's pid to first */
			write(fd[1], &q, sizeof(pid_t));
			/* wait */
			waitpid(q, &status, 0);
		}
	}
	else
	{
		// child one
		pid_t pid_s;
		read(fd[0], &pid_s, sizeof(pid_t));
		/* waits a couple of seconds and sends SIGSTOP to the second child */
		sleep(3);
		kill(pid_s, SIGSTOP);
	}

	return 0;
}