#include "holberton.h"
int isBuiltin(char *command)
{
	if ((command[0] == 'e') && (command[1] == 'x') && (command[2] == 'i') && (command[3] == 't') && (command[4] == '\0'))
	{
		return(1);
	}
	else if (command[0] == 'e' && command[1] == 'n' && command[2] == 'v' && command[3] == '\0')
	{
		printEnv();
		return(2);
	}
	return(0);
}
char *getLocation(char *daPath, char *command, char *name)
{
	char **pathList;

	int y = 0;
	printf("%s\n", command);
	if (access(command, X_OK) == 0)
	{
		return (_strdup(command));
	}

	pathList = _strtok(daPath, ':');

	while (pathList[y])
	{
		char *temp;
		temp = _strcat("/", command);
		temp = _strcatf2(pathList[y], temp);

		if (access(temp, X_OK) == 0)
		{
			freeDP(pathList);
			return (temp);
		}
		y++;
		free(temp);
	}
	freeDP(pathList);
	perror(name);
	return (NULL);
}
int exacute(char **input, char *name)
{
	extern char** environ;
	pid_t pid;
	char *command = input[0];
	char *daPath = getpath();
	char *location = getLocation(daPath, command, name);
	if (location)
	{
		pid = fork();

		if (pid < 0)
		{
			perror(name);
		}
		if (pid > 0)
		{
			wait(NULL);
		}
		if (pid == 0)
		{
			if(execve(location, input, environ) == -1)
				perror(name);
		}
	}
	free (location);
	return (1);
}


void handle_sigint()
{
	putstring("\n$ ");
}
int main(int argc, char **argv)
{
	char *name = argv[0];
	int chars = 1;
	char *string = NULL;
	size_t inSize = 1;
	UNUSED(argc);
	signal(SIGINT, handle_sigint);
	while (chars > 0)
	{
		if (isatty(STDIN_FILENO))
			putstring("$ ");
		chars = getline(&string, &inSize, stdin);
		if (chars == -1)
			break;
		if (isNothing(string))
			continue;
		if (chars)
		{
			char *command;
			int buildInCode;
			char **result = _strtok(string, ' ');
			command = result[0];
			buildInCode = isBuiltin(command);
			if (buildInCode == 1)
			{
				freeDP(result);
				free(string);
				exit(1);
			}
			else if (buildInCode == 0)
				exacute(result, name);
			freeDP(result);
		}
	}
	free (string);
	exit(1);
}
