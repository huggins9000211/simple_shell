#include "holberton.h"

int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')

	{
		length++;
	}

	return (length);
}
int isNothing(char *string)
{
	int empty = 1;
	int i = 0;

	while (string[i] != '\n')
	{
		if (string[i] != ' ')
		{
			empty = 0;
		}
		i ++;
	}
	return (empty);

}
char *getpath()
{
	extern char **environ;
	int i = 0;
	while (environ[i])
	{

		if ((environ[i][0] == 'P') && (environ[i][1] == 'A') && (environ[i][2] == 'T') && (environ[i][3] == 'H') && (environ[i][4] == '='))
		{
			return (environ[i]);
		}
		i++;
	}
	return (NULL);
}
void printEnv()
{
	extern char **environ;
	int i = 0;
	while (environ[i])
	{
		putstring(environ[i]);
		putstring("\n");
		i++;
	}
}
