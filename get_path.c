#include "main.h"
/**
 * get_path - Checks if given command has a valid directory
 * @cmd: tokenized string
 * Return: 0 (success)
 */
int get_path(char **cmd)
{
	char *path, *token, *binpath;
	struct stat buf;

	path = getenv("PATH");/* Get the value of the PATH environment variable */
	token = strtok(path, ":");/* Tokenize the PATH variable */
	while (token != NULL) /* Loop through the directories in PATH */
	{
		binpath = build(*cmd, token);/* Build the full path for the command */
		if (stat(binpath, &buf) == 0)/* Check if the command exists */
		{
			*cmd = strdup(binpath);/* Replace the command with the full path */
			break;
			return (0);
		}
		free(binpath);/* Free the memory and continue looping */
		binpath = NULL;
		token = strtok(NULL, ":");/* Get the next directory in PATH */
	}
	free(binpath);/* Free the memory allocated to binpath */
	return (1);/* Return 1 if the command is not found */
}

/**
 * build - Appends a slash to make a full directory for stat function
 * @command: Required command
 * @directory: Directory Conatining Command
 * Return: Complete directory
 */
char *build(char *command, char *directory)
{
	char *fpath;
	size_t len;

	len = _strlen(directory) + _strlen(command) + 2;
	fpath = malloc(sizeof(char) * len);/* Allocate memory for the full path */
	if (fpath == NULL)
	{
		free(fpath);
		return (NULL);
	}
	memset(fpath, 0, len);/* Initialize the memory to 0 */
	fpath = _strcat(fpath, directory);/* Append the directory to the full path */
	fpath = _strcat(fpath, "/");/* Append a slash to the full path */
	fpath = _strcat(fpath, command);/* Append the command to the full path */

	return (fpath);/* Return the full path */
}
