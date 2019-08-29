#ifndef GRANDPARENT_H
#define GRANDPARENT_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#define UNUSED(x) (void)(x)
int isNothing(char *string);
char *_strcat(char *s1, char *s2);
char *_strcatf1(char *s1, char *s2);
char *_strcatf2(char *s1, char *s2);
char **_strtok(char *str, char delim);
int putstring(char *in);
int isNothing(char *string);
char *getpath();
void printEnv();
char *_strdup(char *string);
int getNumTokens(char *str, char delim);
char **_strtok(char *str, char delim);
int isBuiltin(char *command);
char *getLocation(char *daPath, char *command, char *name);
int exacute(char **input, char *name);
void handle_sigint();
int main(int argc, char **argv);
void freeDP(char **dp);
int _strlen(char *s);
#endif
