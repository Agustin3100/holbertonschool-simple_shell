#include "main.h"
char *getpath(char *cmd)
{
    char *path, *value, *binpath;
    struct stat buf;
    char *binpath_copy;

    path = getenv("PATH");
    value = strtok(path, ":");
    while (value != NULL)
    {
        binpath = malloc(sizeof(char) * (strlen(value) + strlen(cmd)) + 2);
        if (binpath == NULL)
        {
            return (NULL);
        }

        binpath_copy = binpath;

        binpath_copy = strcat(binpath_copy, value);
        binpath_copy = strcat(binpath_copy, "/");
        binpath_copy = strcat(binpath_copy, cmd);

        if (stat(binpath_copy, &buf) == 0)
        {
            cmd = strdup(binpath_copy);
            break;
        }
        value = strtok(NULL, ":");
    }
    free(binpath_copy);
    return (cmd);
}
