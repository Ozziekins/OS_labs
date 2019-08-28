#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int f;
	float g;
	double h;

	printf("On my computer\n");
	printf("Size of integer is: %lu and maximum is: %lu\n", sizeof(f), sizeof(INT_MAX));
	printf("Size of float is: %lu and maximum is: %lu\n", sizeof(g), sizeof(FLT_MAX));
	printf("Size of double is: %lu and maximum is: %lu\n", sizeof(h), sizeof(DBL_MAX));

	return 0;
}