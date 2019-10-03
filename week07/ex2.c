#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int *array;
	/* prompts user to enter N */
	printf("Please enter an integer for N: ");
	scanf("%d", &N);

	/* For loop to fill the array with incrememntal values */
	array = (int *)calloc(N, sizeof(int));
	for (int i = 0; i < N; ++i)
	{
		*(array + i) = i;
	}

	/* prints the array */
	for (int i = 0; i < N; ++i)
	{
		printf("%d\n", *(array + i));
	}

	/* deallocates the memory*/
	free(array);

	return 0;
}