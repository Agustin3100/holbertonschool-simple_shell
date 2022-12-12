#include "main.h"
/**
 * main - Executes commands entered by the user
 * Return: 0 (success)
 */
int main(void)
{
	char **argv;
	char *input;
	int status = 0;

	while (1)
	{
		printf("$ ");/* Prompt the user for input */
		input = get_line();/* Get the input entered by the user */
		argv = tokenizer(input);/* Tokenize the input */

		if (_strcmp(input, "exit") == 0)/* If the user enters 'exit'*/
		{
			if (argv[1])
			{
				status = strtol(argv[1], NULL, 10);/* The exit status to an integer */
				free(argv);/* Free the allocated memory for input and argv */
				free(input);
				exit(status);/* Exit the program with the specified exit status */
			}
			free(input);/* Free the allocated memory for input and argv */
			free(argv);
			exit(EXIT_SUCCESS);/* Exit the program with the specified exit status */
		}
		execute(argv, input);/* Execute the command */
		free(input);/* Free the allocated memory for input and argv */
		free(argv);
	}
	return (0);/* Return 0 if the program exits successfully */
}
