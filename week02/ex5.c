#include <stdio.h>

void full_tri(int *x){

	for (int i = 1; i <= *x; ++i)
	{
		for (int j = 1; j <= *x - i; ++j)
		{
			printf(" ");
		}
			for (int k = 0; k < 2*i - 1; ++k)
			{
				printf("*");
			}
		printf("\n");
	}
}

void half_tri(int *y){
	for (int i = 1; i <= *y; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
}

void rectangle(int *z){
	for (int i = 0; i < *z; ++i)
	{
		for (int j = 0; j < *z; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	int n;
	sscanf(argv[1], "%d", &n);

	full_tri(&n);

	printf("\n");

	rectangle(&n);

	printf("\n");

	half_tri(&n);


	return 0;
}