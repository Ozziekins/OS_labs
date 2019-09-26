#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define count 555

int main()
{
	char text_one[count] = "Hello there :)";
	char text_two[count] = "";

	int fd[2], p_id, n;
	 
	if (pipe(fd) < 0)
	{
		exit(1);
	}

	if ((p_id = fork()) > 0)
	{
		/* write the text from the first string to the pipe */
		write(fd[1], text_one, count);
	}else
	{
		/* read the text from the pipe into the empty string */
		while((n = read(fd[0], text_two, count)) > 0)
		{
			printf("%s\n", text_two);
		}
		if (n != 0)
		{
			exit(2);
		}
	}

	/* print out both strings */
	printf("%s\n", text_one);

	return 0;
}