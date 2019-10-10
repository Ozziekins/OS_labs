#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ten_MB 10485760

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		int *ptr = malloc(ten_MB);
		memset(ptr, 0, ten_MB);
		sleep(1);
		//free(ptr);
	}

	return 0;
}

/* after running the program in background with vmstat 1
*  It was noticed that si and so are always 0 as shown in
*  e2.txt file. */