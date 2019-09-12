#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(void)
{
	for (int i = 0; i < 3; ++i)
	{
		fork();
		sleep(5);
	}
	
}

/* program was also ran while calling fork() 5 times */