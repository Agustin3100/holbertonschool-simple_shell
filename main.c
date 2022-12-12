#include "main.h"

/**
 * main - executes programs from linux accroding to commands
 *
 * Return: 0 (success)
 */

int main(void)
{
	char **argv;

	char *input;

	int status = 0;

	while (1)
	{
		printf("$ ");

		input = get_line();
		argv = tokenizer(input);

		if (_strcmp(input, "exit") == 0)
		{
			if (argv[1])
			{
				status = strtol(argv[1], NULL, 10);
				free(argv);
				free(input);
				exit(status);
			}
			free(input);
			free(argv);
			exit(EXIT_SUCCESS);
		}

		execute(argv, input);

		free(input);
		free(argv);
	}

	return (0);
}
