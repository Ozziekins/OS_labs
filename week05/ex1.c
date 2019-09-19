#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <string.h>

/* thread function definition */
void *thread_func(void *args)
{
	pthread_t *id = (pthread_t*)args;
	printf("This is from thread function with id=%lu.\n", *id);
}

int main()
{
	int n;
	printf("Enter an integer for n:\n");
	scanf("%d", &n);

	/* creating thread id */

	for (int i = 0; i < n; ++i)
	{
		pthread_t thread_id;
		pthread_create(&thread_id, NULL, thread_func, &thread_id);
		printf("Created thread[%d] with thread_id[%lu]\n", i, thread_id);
	}

	//printf("This is from main function.\n");

/*	for (int i = 0; i < n; ++i)
	{
		pthread_join(thread_id, NULL);
		printf("Thread[%d] has exited.\n", i);
	}
  */  
	return 0;
}