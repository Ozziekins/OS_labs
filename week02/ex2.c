#include <stdio.h>
#include <string.h>

int main()
{
	/* declare the array to contain the strings */
	char c[555], r[555];
	int count;

	/* prompt fo ruser input */
	printf("Please enter a string below:\n");
	fgets(c, 555, stdin);
	count = strlen(c) - 1;
	
	/* reverses the string and puts into another array */
	for (int i = 0; i < strlen(c); ++i)
	{
		r[i] = c[count];
		count--;
	}

	/* prints out the reversed string */
	printf("The reversed string is: %s\n", r);

	return 0;
}
