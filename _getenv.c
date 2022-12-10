#include "main.h"
char *_getenv(const char *name)
{
	int i = 0;
	char *pathspace, *path, *tok;
	
    if(name == NULL)
	{
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		pathspace = malloc(sizeof(environ[i] + 2));
		if (!pathspace)
		{
			return (NULL);
		}
		path = strdup(name);
		tok = strtok(path, "=");
		if(strcmp(path, tok) == 0) 
		{
			tok = strtok(NULL, "=");
			break;
		}
	}
	free(pathspace);
	return (path);
}