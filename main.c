#include "main.h"


int main(int ac, char **argv)
{
    char *buff = NULL, *buffcpy = NULL, *token = NULL, **argvcpy;
    const char *limit = " \n";
    size_t n = 0;
    ssize_t nr;
    int ntokens = 0, i = 0;
    pid_t pid;

    while (1)
    {
        printf("O_o $: "); // Prompt
        nr = getline(&buff, &n, stdin);
        if (nr == -1)
        {
            printf("\n");
            return (-1);
        }
        buffcpy = strdup(buff);
        token = strtok(buffcpy, limit);
        while (token != NULL)
        {
            ntokens++;
            token = strtok(NULL, limit);
        }
        free(buffcpy);
        buffcpy = strdup(buff);
        argvcpy = malloc((ntokens + 1) * sizeof(char *));
        token = strtok(buffcpy, limit);
        while (token != NULL)
        {
            argvcpy[i] = strdup(token);
            i++;
            token = strtok(NULL, limit);
        }
        argvcpy[i] = NULL;
        free(buffcpy);

        if (strcmp(argvcpy[0], "exit") == 0)
        {
            free(buff);
            free(argvcpy);
            return (0);
        }
        /* Create a new child process */
        pid = fork();
        if (pid == -1)
        {
            /* Error al crear el proceso hijo */
            perror("Error al crear el proceso hijo");
            return (-1);
        }
        else if (pid == 0)
        {
          	/* Execute the command in the child process */
            if (exec(argvcpy) == 0)
            {
                free(buff);
                free(argvcpy);
                return (0);
						}
						else
						{
								perror("Error al ejecutar el comando");
								free(buff);
								free(argvcpy);
								return (-1);
						}
				}
				else
				{
					/* This code is executed in the parent process */
					/* Wait for the child process to terminate */
						wait(NULL);
				}
		}
		return (0);
}