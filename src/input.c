/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** custom gnl for matchstick
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/matchstick.h"

char *input(void)
{
	char *buffer = malloc(sizeof(char) * 2);
	char *res = malloc(sizeof(char) * 2);
	int check;

	res[0] = '\0';
	res[1] = '\0';
	while (buffer[0] != '\n') {
		buffer[0] = '\0';
		check = read(0, buffer, 1);
		buffer[1] = '\0';
		if (buffer[0] != '\n')
			res = my_strcat(res, buffer);
		else if (res[0] == '\0')
			return (buffer);
		if (check == 0)
			return (NULL);
	}
	free(buffer);
	return (res);
}
