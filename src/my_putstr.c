/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** my putstr
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

void my_putstr(char *str)
{
	int len = 0;

	for (len; str[len] != '\0'; len++);
	write(1, str, len);
}
