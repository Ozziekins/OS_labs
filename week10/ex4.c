#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define COUNT 555

typedef struct record
{
	ino_t i_node;
	int count;
	char names[COUNT][COUNT];
} file;

int main()
{	
	struct stat buff;
	struct dirent *dir;
	file storage[COUNT];
 
    DIR *direc = opendir("./tmp"); 
  
    if (direc == NULL)
    { 
        printf("Directory couldn't be opened." ); 
        return 0; 
    }

    for (int i = 0; i < COUNT; ++i)
    {
    	storage[i].i_node = 0;
    	storage[i].count = 0;
    	memset(storage[i].names, 0, COUNT*COUNT);
    }
    	
    while ((dir = readdir(direc)) != NULL){
    	char s[COUNT] = "tmp/";
    	strcat(s, dir->d_name);
    	stat(s, &buff);

    	if (buff.st_nlink >= 2)
    	{
    		for (int i = 0; i < COUNT; ++i)
    		{
    		 	if (buff.st_ino == storage[i].i_node)
    		 	{
    		 		strcpy(storage[i].names[storage[i].count], dir->d_name);
    		 		storage[i].count++;
    		 		break;
    		 	}

    		 	if (storage[i].i_node == 0)
    		 	{
    		 		storage[i].i_node = buff.st_ino;
    		 		strcpy(storage[i].names[storage[i].count], dir->d_name);
    		 		storage[i].count++;
    		 		break;
    		 	}
    		}
    	}
    }

    for (int i = 0; 0 == storage[i].count; ++i)
    {
    	printf("For inode %lu we have:\n", storage[i].i_node);
    	for (int j = 0; j < storage[i].count; ++j)
    	{
    		printf("%d). %s\n", j+1, storage[i].names[j]);
    	}
    }

    closedir(direc);

	return 0;
}