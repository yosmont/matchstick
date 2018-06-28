/*
** EPITECH PROJECT, 2018
** main
** File description:
** function main
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/matchstick.h"

void help(int output)
{
	write(output,"command:\t./matchstick nb_line nb_matche_max\n\n", 45);
	write(output,"description:\tmake a board with nb_line line for", 47);
	write(output," a matchstick game vs a AI, nb_matche_max is the", 48);
	write(output," number of matche you can pick every turn\n", 42);
}

void error_with_help(int ac)
{
	switch(ac) {
	case 1:
		write(2,"Error: enter a size and a number of matche max\n",47);
		help(2);
		break;
	case 2:
		write(2,"Error: enter a number of matche max\n",36);
		help(2);
		break;
	default:
		help(2);
	}
}

int main(int ac, char **av, char **env)
{
	char **board;
	int max = 0;
	int nb_line = 0;
	int wol = 0;

	if (ac < 3 || (av[1][0] == '-' && av[1][1] == 'h')) {
		error_with_help(ac);
		return (84);
	}
	nb_line = my_getnbr(av[1]);
	if (nb_line <= 1 || nb_line >= 100)
		return (84);
	srandom(getpid());
	max = my_getnbr(av[2]);
	board = create_game_board(nb_line);
	display_board(board, nb_line);
	my_putchar('\n');
	wol = gameloop(board, nb_line, max);
	if (wol == 1) {
		my_putstr("I lost... snif... but I'll get you next time!!\n");
		return (1);
	} else if (wol == 2) {
		my_putstr("You lost, too bad...\n");
		return (2);
	}
	return (0);
}
