#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/* creating my String datatype */
typedef char* String;

int main()
{
	char command[555];	//array to store the command after it has been read

	/* loop to take in commands until exit */
	for (; ;)
	{
		gets(command);

		/* condition to exit the loop if comman is exit */
		String exitCommand = "exit";
		if (strcmp(command,exitCommand) == 0)
		{
			return 0;
		}

		/* array to hold token after strtok splits command */
		char *arry[555];
		int j = 0;

		/* splitting the command into tokens */
		char *token = strtok(command, " ");
		while(token != NULL)
		{
			arry[j] = token;
    		token = strtok(NULL, " ");
    		++j;
		}

		/* assigning last element of the array to be 0 */
		arry[j] = 0;
		int pid = fork();

		/* conditions based on the result of fork() */
		if (pid == -1)
    	{
        	perror("Error forking...\n");
        	exit(1);
        }
		if(pid == 0) {
       	 	execvp(arry[0], arry);
       	 	exit(0);
    	}
	}

	return 0;
}