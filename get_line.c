#include "main.h"
/**
 * get_line -function that reads a line from stdin
 * Return: the line read from stdin
 */
char *get_line(void)
{
	char *input;
	size_t n;
	int nr;

	n = 0;/* size of the buffer */
	input = NULL;/* buffer to store the input */
	nr = getline(&input, &n, stdin); /* get the input from the user */
	if (nr == -1)/* if the user presses ctrl + d */
	{
		free(input);/* free the buffer */
		exit(EXIT_SUCCESS);/* exit the program */
	}

	return (input);/* return the input */
}
