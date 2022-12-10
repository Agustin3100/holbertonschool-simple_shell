#include "main.h"
int main(int ac, char **argv)
{
    char *buff = NULL, *buffcpy = NULL, *token = NULL;
    const char *limit = " \n";
    size_t n = 0;
    ssize_t nr;
    int ntokens = 0, i = 0;
    char **argvcpy;
    while (1)
    {
        printstr("O_o $: ");
        nr = getline(&buff, &n, stdin);
        if (nr == -1)
        {
            printstr("\n");
            return (-1);
        }
        if (strcmp(buff, "exit") == 0)
        {
            printf("Exit\n");
            return (-1);
        }
		pid_t pid = fork();
		if (pid != 0)
        {
           	wait(NULL);
       	}
        else
        {
            buffcpy = malloc(sizeof(char) * nr);
            if (!buffcpy)
            {
                free(buff);
                return (-1);
            }
            strcpy(buffcpy, buff);
            token = strtok(buff, limit);   
            while (token != NULL)
            {
                ntokens++;
                token = strtok(NULL, limit);
            }
            ntokens++;
            argvcpy = malloc(sizeof(char *) * ntokens);
            if (!argvcpy)
            {
                free(buff);
                free(buffcpy);
                return (-1);
            }

            token = strtok(buffcpy, limit);
            while (token != NULL)
            {
                argvcpy[i] = token;
                token = strtok(NULL, limit);
                i++;
            }
			exec(argvcpy);
        }
    }
	free(argv);
	free(argvcpy);
    free(buff);
    free(buffcpy);
    return (0);
}