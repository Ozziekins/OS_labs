#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	/* declare the variables */
	int f = 7;
	float g = 77.09;
	double h = 9778.54;

	int u = INT_MAX;
	int v = FLT_MAX;
	int w = DBL_MAX;

	/* print the sizes and values of each variable */
	printf("On my computer\n");
	printf("Value of integer is: %d and the size is: %lu\n", f, sizeof(f));
	printf("Value of float is: %f and the size: %lu\n", g, sizeof(g));
	printf("Value of double is: %lf and the size is: %lu\n", h, sizeof(h));
	printf("Value of maximum int is: %d and the size is: %lu\n", u, sizeof(u));
	printf("Value of maximum float is: %d and the size is: %lu\n", v, sizeof(v));
	printf("Value of maximum double is: %d and the size is: %lu\n", w, sizeof(w));

	return 0;
}