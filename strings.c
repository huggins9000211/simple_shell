#include "holberton.h"
char *_strcat(char *s1, char *s2)
{
	char *result;
	int totalLength;
	int i = 0;
	int counter = 0;

	if (s1 == NULL)
	{
		return (s2);
	}
	if (_strlen(s1) == 0)
	{

		return (s2);
	}

	totalLength = _strlen(s1) + _strlen(s2);
	result = malloc(totalLength + 1);


	while (s1[i] != '\0')
	{
		result[counter] = s1[i];
		counter++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		result[counter] = s2[i];
		counter++;
		i++;
        }

	result[counter] = '\0';
	return (result);
}
char *_strcatf1(char *s1, char *s2)
{
	char *result;
	int totalLength;
	int i = 0;
	int counter = 0;

	if (s1 == NULL)
	{
		return (s2);
	}

	totalLength = _strlen(s1) + _strlen(s2);

	result = malloc(totalLength + 1);


	while (s1[i] != '\0')
	{
		result[counter] = s1[i];
		counter++;
		i++;
	}
	free(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		result[counter] = s2[i];
		counter++;
		i++;
        }

	result[counter] = '\0';
	return (result);
}
char *_strcatf2(char *s1, char *s2)
{
	char *result;
	int totalLength;
	int i = 0;
	int counter = 0;

	if (s1 == NULL)
	{
		return (s2);
	}

	totalLength = _strlen(s1) + _strlen(s2);

	result = malloc(totalLength + 1);


	while (s1[i] != '\0')
	{
		result[counter] = s1[i];
		counter++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		result[counter] = s2[i];
		counter++;
		i++;
        }
	free(s2);
	result[counter] = '\0';
	return (result);
}

int putstring(char *in)
{
	int i;
	int result;
	i = _strlen(in);

	result = write(1, in, i);
	/*
	flush(1);
	*/
	return result;

}
