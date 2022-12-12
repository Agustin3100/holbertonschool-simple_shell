#include "main.h"
/**
 * execute - executes command with fork if command exists
 * @argv: array of arguments
 * @input: input from getline
 * Return: 0 (success)
 */
int execute(char **argv, char *input)
{
	int status;/* status of child process */
	pid_t child;/* child process */

	if (*argv == NULL)/* If there are no arguments, return 1 */
		return (1);
	child = fork();/* create child process */
	if (child == -1)/* if fork fails, print error and return 1 */
	{
		perror("Error\n");
		return (1);
	}
	if (child == 0)/* child process */
	{
		if (strncmp(*argv, "./", 2) != 0)/*If command does not start with ./ */
		{
			get_path(argv);/* Get path for command */
		}
		if (execve(*argv, argv, environ) == -1)/* If command does not exist */
		{
			perror(*argv);
			free(input);
			free(argv);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS); /* return 0 if command is executed */
	}
	wait(&status);/*wait for child process to finish*/

	return (1);
}
