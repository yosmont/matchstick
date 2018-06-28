/*
** EPITECH PROJECT, 2018
** board
** File description:
** function who make and update the board
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/matchstick.h"

char *star_line_vs_force_of_evil(int last_line)
{
	char *line = malloc(sizeof(char) * (last_line + 2));

	for (int i = 0; i < (last_line + 2); i++)
		line[i] = '*';
	return (line);
}

char **create_game_board(int nb_line)
{
	int space = nb_line - 1;
	int line_len = 1;
	char **board = malloc(sizeof(char *) * (nb_line + 2));

	board[0] = star_line_vs_force_of_evil((nb_line * 2) - 1);
	for (int i = 1; i < (nb_line + 1); i++) {
		board[i] = malloc(sizeof(char) * ((nb_line * 2) + 1));
		board[i][0] = '*';
		for (int j = 1; j < (space + 1); j++)
			board[i][j] = ' ';
		for (int j = space + 1; j < ((space + 1) + line_len); j++)
			board[i][j] = '|';
		for (int j = (space + 1 + line_len); j < (nb_line * 2); j++)
			board[i][j] = ' ';
		board[i][nb_line * 2] = '*';
		space = space - 1;
		line_len = line_len + 2;
	}
	board[nb_line + 1] = star_line_vs_force_of_evil((nb_line * 2) - 1);
	return (board);
}

char **update_game_board(int line, int nb_matches, char **board)
{
	int walker = 1;

	for (walker; board[line][walker] == ' '; walker++);
	for (walker; board[line][walker] == '|'; walker++);
	walker--;
	for (int i = 0; i < nb_matches; i++, walker--)
		board[line][walker] = ' ';
	return (board);
}
