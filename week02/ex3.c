#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* declares the height variable n and receives the number from the command line */
	int n;
	sscanf(argv[1], "%d", &n);

	/* prints out the triangle */
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n - i; ++j)
		{
			printf(" ");
		}
			for (int k = 0; k < 2*i - 1; ++k)
			{
				printf("*");
			}
		printf("\n");
	}

	return 0;
}
