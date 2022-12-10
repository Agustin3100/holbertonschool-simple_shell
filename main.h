#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
char *read_line(void);
int exec(char **argv);
char *gpath(char **cmd);
int exitt(void);
char *build(char *token, char *value);
char *getpath(char *cmd);
extern char** environ;
int geterror (char argv[]);
char *_getenv(const char *name);
int _strlen(char *s);
int printstr(char *);
#endif
