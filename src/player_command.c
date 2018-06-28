/*
** EPITECH PROJECT, 2018
** player command
** File description:
** ask player command
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/matchstick.h"

int ask_line(int nb_line, char **board)
{
	char *line = "Line: ";
	char *command;
	int check = 1;

	while (check == 1) {
		my_putstr(line);
		//command = get_next_line(0);
		command = input();
		if (!command)
			return (0);
		check = error_line(command, nb_line, board);
	}
	return (my_getnbr(command));
}

int ask_matches(char **board, int max, int line)
{
	char *matches = "Matches: ";
	char *command;
	int check = 1;

	my_putstr(matches);
	//command = get_next_line(0);
	command = input();
	if (!command)
		return (0);
	check = error_matches(command, board, max, line);
	if (check == 1)
		return (199);
	return (my_getnbr(command));
}
