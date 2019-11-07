#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define COUNT 5555

int main(int argc, char const *argv[])
{

	char buff[COUNT];

	int n = argc;
	int nums[COUNT];
	if (n > 1 && argv[1] == "-a")
	{
		/*check that files are giving in arguments */
		for (int i = 1; i < n; ++i)
		{
			bool existing = open((argv[i+1]), O_RDONLY) != -1;

			if (open((argv[i+1]), O_RDONLY) != -1)
			{
				printf("Error in opening the file '%s.txt'\n", argv[i+1]);
			}

			/*check if the file exists in order to just append or create a new file*/
			if (existing)
			{
				nums[i] = open(argv[i+1], O_RDWR | O_APPEND, (mode_t)0666);
			} else
			{
				nums[i] = open(argv[i+1], O_RDWR | O_CREAT, (mode_t)0666);
			}
		}
	}
	
	int w;

	while((w = read(0, buff, COUNT)) != 0)
	{
		/*write stdout*/
		write(1, buff, w);

		/*write to each of the listed files and then close */
		for (int i = 1; i < n; ++i)
		{
			write(nums[i], buff, w);
			close(nums[i]);
		}
	}

	return 0;
}