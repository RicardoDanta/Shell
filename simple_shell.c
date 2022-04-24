#include "main.h"

/**
 * main - Entry
 * Return: 0
 */

int main(void)
{
	char *buffer;
	size_t bufsize = 1024;
	size_t characters;
	
	while (1)
	{
		write(1, "$ ", 2);

		if ((characters = getline(&buffer, &bufsize, stdin)) == -1)
			break;

		char * token = strtok(buffer, " ");
		
		while (token != NULL)
		{
			
			token = strtok(NULL, " ");
		}
	}

}

/**
 * fork+wait+execve - Duplicate, execute and wait
 * Return: 0
 */

int forkwaitexecve(void)
{
	pid_t child; //define un proceso
	int status; //estado de un proceso
	int execution; //variable equivalente a execve
	char **argv;

	child = fork(); //proceso para duplicar
		
	if (child == -1) //comprueba caso de error
	{
		perror ("Error:");
		return (1); //1 en caso de error
	}
	else if (child == 0) //si el hijo es exitoso
	{
		if ((execution = execve(argv[0], argv, NULL)) == -1)
			perror ("Error:"); //en caso de que la ejecución falle
		else
			execution; //si la misma es exitosa
	}
	else
		wait (&status);
	return (0);
}
