#include "main.h"
int exec(char **argv)
{
    char *command = NULL, *command_path = NULL;
    char *command_path_copy;
    if (*argv == NULL)
    {
        return (1);
    }
    if (argv)
    {
        command = argv[0];
        command_path = getpath(command);
        command_path_copy = command_path;

        if (execve(command_path_copy, argv, environ) == -1)
        {
            printf("Error: not a command or directory\n");
		    free(command_path_copy);
			free(argv);
			exit(EXIT_FAILURE);
        }
    }
}
