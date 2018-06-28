/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** rework29
*/

#include <stdlib.h>
#include "../include/matchstick.h"

char *my_strdup(char *src)
{
	char *dest;
	int i = 0;
	int len;

	for (len = 0; src[len] != '\0'; len++);
	dest = malloc(sizeof(char) * (len + 1));
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;

	}
	dest[i] = '\0';

	return (dest);
}

int my_strlen(char *str)
{
	int len = 0;

	for (len; str[len] != '\0'; len++);
	return (len);
}

char	*my_strcat(char *dest, char *src)
{
	int len = my_strlen(dest);
	int tmp = 0;
	char *res = malloc(sizeof(char) * (len + my_strlen(src) + 1));

	for (int i = 0; i < len; i++)
		res[i] = dest[i];
		free(dest);
	while (src[tmp] != '\0') {
		res[len] = src[tmp];
		len++;
		tmp++;
	}
	res[len] = '\0';
	dest = my_strdup(res);
	free(res);
	return (dest);
}
