#include "main.h"

/**
 * main - Entry
 * Return: 0
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	int i = 0;
	char *arg[1024];

	while (1)
	{
		write(1, "$ ", 2);

		if ((getline(&buffer, &bufsize, stdin)) == -1)
			break;

		char * token = strtok(buffer, " ");
		
		while (token != NULL)
		{
			arg[i++] = token;
			token = strtok(NULL, " ");
		}
		return (forkwaitexecve(arg)); 
	}
	free(buffer);
}

/**
 * fork+wait+execve - Duplicate, execute and wait
 * Return: 0
 */

int forkwaitexecve(char **argv)
{
	pid_t child; //define un proceso
	int status; //estado de un proceso
	int execution; //variable equivalente a execve

	child = fork(); //proceso para duplicar
		
	if (child == -1) //comprueba caso de error
	{
		perror ("Error:");
		return (1); //1 en caso de error
	}
	else if (child == 0) //si el hijo es exitoso
	{
		if ((execution = execve(argv[0], argv, NULL)) == -1)
		{
			perror ("Error:"); //en caso de que la ejecución falle
			exit(-1);
		}
	}
	else
		wait (&status);
	return (0);
}
