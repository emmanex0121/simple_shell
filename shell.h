#ifndef SHELL_H
#define SEHLL_H

#define MAX_COMMAND_LENGTH 100
#define MAX_NUMBER_OF_PARAMS 10


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
void parseCmd(char* cmd, char** params);
int executeCmd(char** params);
extern char **environ;
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

#endif
