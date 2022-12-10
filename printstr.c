#include "main.h"
int printstr(char * str)
{
	int i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}