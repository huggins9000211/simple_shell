#include "holberton.h"

char **_strtok(char *str, char delim)
{
	char **result;
	int numTokens;
	char *temp, *temp2, *temp3;
	int i = 0, x = 0;
	temp = NULL;
	numTokens = getNumTokens(str, delim) + 2;
	result = malloc(sizeof(char*) * numTokens);
	while (str[i] != '\0')
	{
		char currentString[2] = "\0";
		currentString[0] = str[i];
		if (str[i] == delim)
		{
			if (temp)
			{
				temp = NULL;
			}
		}
		else
		{
			if (!temp)
			{
				temp = currentString;
				temp3 = _strdup(temp);
			}
			else
			{
				temp2 = currentString;
				temp3 = _strcatf1(temp3, temp2);
			}
			if ((str[i + 1] == delim) || (str[i + 1] == '\n'))
			{
				result[x] = temp3;
				x++;
				temp = NULL;
			}
		}
		i++;
	}
	free(temp3);
	result[x] = NULL;
	return(result);
}

int getNumTokens(char *str, char delim)
{
	int i = 0;
	int count = 0;
	char *temp3 = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == delim)
		{
			if (temp3)
			{

				temp3 = NULL;
			}
		}
		else
		{
			if (((str[i + 1] == delim) || (str[i + 1] == '\n')) && temp3)
			{
				count ++;
				temp3 = NULL;
			}
			else
			{
				temp3 = " ";
			}
		}
		i++;
	}

	return(count);
}
char *_strdup(char *string)
{
	char *result;

	int ii = 0;

	result = malloc(_strlen(string) + 1);
	if (result == NULL)
	{
		return(NULL);
	}



	while (string[ii] != '\0')
	{
		result[ii] = string[ii];
		ii++;
	}
	result[ii] = '\0';
	return (result);
}
void freeDP(char **dp)
{
	int i;

	i = 0;
	while (dp[i] != NULL)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}
