/* An alternative approach for exercise 4 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

typedef char* String;

int main(void)
{
	char command[555];
	String exitCommand = "exit\n";
	while(fgets(command, 100, stdin))
	{
		if (strcmp(command,exitCommand) == 0)
		{
			return 0;
		}
		system(command);
	}
	return 0;
}
