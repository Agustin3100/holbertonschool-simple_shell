#ifndef MAIN_H
#define MAIN_H
#define  _GNU_SOURCE
#define LIMIT "\n\t\r\a " /* Limiters for strtok */
#define EXIT_FAILURE    1       /* Failing exit status.  */
#define EXIT_SUCCESS    0       /* Successful exit status.  */
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
char *get_line(void);
char *build(char *token, char *value);
int get_path(char **cmd);
extern char**(environ);
int geterror(char argv[]);
char *_getenv(const char *name);
int _strlen(char *s);
int printstr(char *);
int execute(char **argv, char *input);
char **tokenizer(char *input);
char *_getenv(const char *name);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
#endif
