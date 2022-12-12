#include "main.h"
/**
 * tokenizer - separates a string into tokens
 * @input: string to tokenize
 * Return: array with saved tokens
 */
char **tokenizer(char *input)
{
	char **argv;
	char *token;
	int  ntokens = 0;
	int i;

	for (i = 0; input[i]; i++)/* Count the number of tokens in the input string */
	{
		if (input[i] == ' ' || input[i] == '\n') /* Increment the number of tokens */
		ntokens++;
	}
	ntokens++;
	argv = malloc(sizeof(char *) * ntokens);/* Memory for the array of tokens */
	if (!argv)/* If memory allocation fails */
	{
		perror("Error\n");
		return (NULL);
	}
	token = strtok(input, LIMIT);/* Split the input string into tokens */
	for (i = 0; token != NULL; i++)/* Save each token to the array */
	{
		argv[i] = token;/* Save the token to the array */
		token = strtok(NULL, LIMIT);/* Get the next token */
	}
	argv[i] = NULL;/* Set the last element of the array to NULL */
	return (argv); /* Return the array of tokens */
}
