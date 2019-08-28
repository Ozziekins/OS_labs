#include <stdio.h>

/* the swap function */
void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	/* declare variables */
	int a, b;

	/* prompts user for input */
	printf("Enter first integer: ");
	scanf("%d", &a);
	printf("\nEnter second integer: ");
	scanf("%d", &b);

	printf("\nBefore swaping a = %d, b = %d\n", a, b);

	/* call the swap function */
	swap(&a, &b);

	printf("After swapping a = %d, b = %d\n", a, b);
	
	return 0;
}
