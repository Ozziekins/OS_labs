#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define count 555

int main()
{
	char text_one[count] = "Hello there :)";
	char text_two[count] = "";

	int fd[2];
	 
	if (pipe(fd) < 0)
	{
		exit(1);
	}

	/* receive the text from the first string */
	write(fd[1], text_one, count);
	/* transfer the text into the empty string */
	read(fd[0], text_two, count);

	/* print out both strings */
	printf("%s\n", text_one);
	printf("%s\n", text_two);

	return 0;
}