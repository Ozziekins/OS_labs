#include <stdio.h>

#define COUNT 21

int main()
{
	int byte_count = 20;
    char string[COUNT];
    FILE *fp;
    fp = fopen("/dev/random", "rb");
    fread(&string, 1, byte_count, fp);

    FILE *file;
    file = fopen("ex1.txt", "w");
    fprintf(file, "%s", string);
    fclose(file);
    fclose(fp);

	return 0;
}