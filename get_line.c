#include "main.h"

/**
 * get_line - uses getline to take input from the user
 *
 * Return: input from the user
 */

char *get_line(void)
{
	char *input;
	size_t n;
	int nr;

	n = 0;
	input = NULL;

	nr = getline(&input, &n, stdin);

	if (nr == -1)
	{
		printf("Closed\n");
		free(input);
		exit(EXIT_SUCCESS);
	}

	return (input);
}
