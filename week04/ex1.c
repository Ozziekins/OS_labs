/* program that declares a variable n, forks a new process and prints “Hello
from parent [PID - n]” and “Hello from child [PID - n]” from parent and child
processes respectively. */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(void) {
	pid_t n;

	int m = fork();
	n = getpid();

	if (m == 0)
	{
		printf("Hello from child [PID - %d]\n", n);
	} else
	{ 
		printf("Hello from parent [PID - %d]\n", n);
	}


}