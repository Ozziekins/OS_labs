#include <stdio.h>

void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a, b;

	printf("Enter first integer: ");
	scanf("%d", &a);
	printf("\nEnter second integer: ");
	scanf("%d", &b);

	printf("\nBefore swaping a = %d, b = %d\n", a, b);

	swap(&a, &b);

	printf("After swapping a = %d, b = %d\n", a, b);
	
	return 0;
}