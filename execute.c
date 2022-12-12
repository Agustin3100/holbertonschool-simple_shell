#include "main.h"

/**
 * execute - executes command with fork if command exists
 * @argv: tokenized argument
 * @input: input from the user
 *
 * Return: 0 (success)
 */

int execute(char **argv, char *input)
{

	int status;
	pid_t child;

	if (*argv == NULL)
		return (1);

	child = fork();

	if (child == -1)
	{
		perror("Error\n");
		return (1);
	}

	if (child == 0)
	{
		if (strncmp(*argv, "./", 2) != 0)
		{
			get_path(argv);
		}

		if (execve(*argv, argv, environ) == -1)
		{
			perror(*argv);
			free(input);
			free(argv);
			exit(EXIT_FAILURE);
		}

		return (EXIT_SUCCESS);
	}

	wait(&status);

	return (1);
}
