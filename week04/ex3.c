/* simplistic shell to read user input and be able to run a
command without parameters */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void main(void)
{
	char command[555];
	for (int i = 0; ; ++i)
	{
		scanf("%s", command);
		system(command);
	}

}