/*
** EPITECH PROJECT, 2018
** ai
** File description:
** AI's turn...
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/matchstick.h"

int get_nb_matches(char **board, int line)
{
	int nb_matches = 0;

	for (int i = 1; board[line][i] != '*'; i++)
		if (board[line][i] == '|')
			nb_matches++;
	return (nb_matches);
}

char **update(int line, int matches, char **board)
{
	display_command("AI", line, matches);
	board = update_game_board(line, matches, board);
	return (board);
}

int found_line(char **board, int nb_line, int max)
{
	int check = 0;
	int tmp = 0;

	for (int i = 1; i < (nb_line + 1); i++) {
		tmp = get_nb_matches(board, i);
		if (tmp > 1 && tmp <= (max + 1))
			return (i);
	}
	return (0);
}

char **ai_turn_two(char **board, int nb_line, int max)
{
	int line = 0;
	int matches = 0;
	int check = 0;
	int tmp = 0;

	check = found_line(board, nb_line, max);
	if (check > 0) {
		line = check;
		tmp = get_nb_matches(board, check);
		matches = (tmp > max) ? max : (tmp - 1);
		return (update(line, ((matches == 0)? 1 : matches), board));
	}
	while (tmp == 0) {
		line = (int)((random() % nb_line) + 1);
		line = (line > nb_line)? line - 1 : line;
		line = (line == 0) ? 1 : line;
		tmp = get_nb_matches(board, line);
	}
	matches = (tmp > max)? max : tmp;
	return (update(line, matches, board));
}

char **ai_turn(char **board, int player_line, int nb_line, int max)
{
	int line = 0;
	int matches = 0;
	int check = 0;

	check = get_nb_matches(board, player_line);
	if (check > 0) {
		if (check > 1) {
			line = player_line;
			matches = (check <= (max + 1)) ? check - 1 : max;
		} else if (check == 1) {
			line = player_line;
			matches = 1;
		}
		return (update(line, matches, board));
	}
	return (ai_turn_two(board, nb_line, max));
}
