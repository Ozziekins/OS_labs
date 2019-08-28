#include <stdio.h>
#include <string.h>

int main()
{
	char c[555], r[555];
	int count;

	printf("Please enter a string below:\n");
	fgets(c, 555, stdin);
	count = strlen(c) - 1;
	
	for (int i = 0; i < strlen(c); ++i)
	{
		r[i] = c[count];
		count--;
	}

	printf("The reversed string is: %s\n", r);

	return 0;
}