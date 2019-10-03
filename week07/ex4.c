#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* my own realloc() function using malloc() anf free() */
void *my_own_realloc(void *ptr1, size_t old_size, size_t size)
{
	void *ptr2 = NULL;
	if (ptr1 == NULL)
	{
		ptr2 = malloc(size);
	} else if ((size == 0) && (ptr1 != NULL))
	{
		free(ptr1);
	} else
	{
		ptr2 = malloc(size);
		if (size > old_size)
		{
			size = old_size;
		}
		memcpy(ptr2, ptr1, size);
		free(ptr1);
	}

	return ptr2;
}

int main()
{
	
	return 0;
}