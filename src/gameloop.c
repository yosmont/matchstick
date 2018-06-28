/*
** EPITECH PROJECT, 2018
** gameloop
** File description:
** gameloop of the game
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/matchstick.h"

void display_command(char *name, int line, int matches) {
	my_putstr(name);
	my_putstr(" removed ");
	my_putnbr(matches);
	my_putstr(" match(es) from line ");
	my_putnbr(line);
	my_putchar('\n');
}

void display_board(char **board, int nb_line)
{
	for (int i = 0; i < (nb_line + 2); i++) {
		my_putstr(board[i]);
		my_putchar('\n');
	}
}

int get_line_and_matche(int *line, char **board, int nb_line, int max)
{
	int matches = 199;

	while (matches == 199) {
		*line = ask_line(nb_line, board);
		if (*line == 0)
			return (0);
		matches = ask_matches(board, max, *line);
		if (matches == 0)
			return (0);
	}
	return (matches);
}

int gameloop(char **board, int nb_line, int max)
{
	int line = 0;
	int matches = 199;

	while (1) {
		my_putstr("Your turn:\n");
		matches = get_line_and_matche(&line, board, nb_line, max);
		if (matches == 0)
			return (0);
		display_command("Player", line, matches);
		board = update_game_board(line, matches, board);
		display_board(board, nb_line);
		if (check_emptyness(board, nb_line, 1) == 1)
			return (2);
		my_putstr("AI's turn...\n");
		board = ai_turn(board, line, nb_line, max);
		display_board(board, nb_line);
		if (check_emptyness(board, nb_line, 2) == 2)
			return (1);
	}
}
