#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
/**
 * get_path - checks if given command has a valid directory
 * @cmd: tokenized string
 *
 * Return: 0 (success)
 */
int get_path(char **cmd)
{
	char *path, *token, *binpath;
	struct stat buf;

	path = getenv("PATH");
	token = strtok(path, ":");
	while (token != NULL)
	{
		binpath = build(*cmd, token);
		if (stat(binpath, &buf) == 0)
		{
			*cmd = strdup(binpath);
			break;
			return (0);
		}
		free(binpath);
		binpath = NULL;
		token = strtok(NULL, ":");

	}
free(binpath);
return (1);

}
/**
 * build - appends a slash to make a full directory for stat function
 * @command: Required command
 * @directory: Directory Conatining Command
 *
 * Return: Complete directory
 */
char *build(char *command, char *directory)
{
	char *fpath;
	size_t len;

	len = _strlen(directory) + _strlen(command) + 2;
	fpath = malloc(sizeof(char) * len);
	if (fpath == NULL)
	{
		free(fpath);
		return (NULL);
	}

	memset(fpath, 0, len);

	fpath = _strcat(fpath, directory);
	fpath = _strcat(fpath, "/");
	fpath = _strcat(fpath, command);

	return (fpath);
}
