#include "main.h"
/**
 * _strlen - prints the lenght of a string
 * @s: char pointer for example
 *
 * Description: updates value of pointer
 * Return: value 0 (success)
 */
int _strlen(char *s)
{
	int lt = 0;

	while (*s)
	{
		lt++;

		s = s + 1;
	}
	return (lt);
}
/**
 * *_strcat - concatenate the strings
 * @dest: pointer
 * @src: pointer
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int n;

	for (i = 0 ; dest[i] != '\0' ; i++)
		;
	for (n = 0 ; src[n] != '\0' ; n++)
	{
		dest[i] = src[n];
		i++;
	}
	return (dest);
}
/**
 * _strcmp - compare a string
 * @s1: pointer for example
 * @s2: pointer for example
 *
 * Description: compares two strings
 * Return: value 0 (success)
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] - s2[i] == 0 && s1[i] == '\0'; i++)
		;
	return (s1[i] - s2[i]);
}
