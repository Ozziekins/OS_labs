/* a C program that runs for 10 seconds.
Every second it:
– allocates 10 MB of memory
– fills it with zeros
– prints memory usage with getrusage() function
– sleeps for 1 second */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

#define ten_MB 10485760

int main()
{
	struct rusage r_usage;
	for (int i = 0; i < 10; ++i)
	{
		int *ptr = malloc(ten_MB);
		memset(ptr, 0, ten_MB);
		getrusage(RUSAGE_SELF, &r_usage);
    	printf("Memory usage in time %d is %ld\n",i, r_usage.ru_maxrss);
		sleep(1);
		free(ptr);
	}

	return 0;
}