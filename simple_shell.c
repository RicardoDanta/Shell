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
	char **arg, *token = NULL;

	while (1)
	{
		write(1, "$ ", 2);

	if (getline(&buffer, &bufsize, stdin) == -1)
		break;

		token = strtok(buffer, "\n");
		token = strtok(buffer, " ");

	while (token != NULL)
	{
		arg[i] = token;

		if (arg == NULL)
		{
			free(arg);
			free(token);
			free(buffer);
			return (0);
		}
		token = strtok(NULL, " ");
		i++;
	}

	forkwaitexecve(arg);

	}
	free(buffer);
	return (0);
}

/**
 * forkwaitexecve - Duplicate, execute and wait
 * @argv: arguments
 * Return: 0
 */

int forkwaitexecve(char **argv)
{
	pid_t child; /** define un proceso */
	int status = 0; /** estado de un proceso */

	child = fork(); /** proceso para duplicar */

		if (child == -1) /** comprueba caso de error */
		{
			perror("Error:");
			return (1); /** en caso de error */
		}
		else if (child == 0) /** si el hijo es exitoso */
		{
			execve(argv[0], argv, NULL);
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:"); /** en caso de que la ejecución falle */
				exit(-1);
			}
			free(argv);
		}
		else
			wait(&status);
		return (status);
}
