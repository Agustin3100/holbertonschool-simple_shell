#include "main.h"

/**
 * tokenizer - separates a string in parts based on a limiter
 * @input: string to tokenize
 *
 * Return: array with saved tokens
 */

char **tokenizer(char *input)
{
	char **argv;
	char *token;
	int  ntokens = 0;
	int i;

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ' ' || input[i] == '\n')
		ntokens++;
	}
	ntokens++;

	argv = malloc(sizeof(char *) * ntokens);

	if (!argv)
	{
		perror("Error\n");
		return (NULL);
	}

	token = strtok(input, LIMIT);

	i = 0;
	while (token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, LIMIT);
		i++;
	}

	argv[i] = NULL;
	return (argv);
}
