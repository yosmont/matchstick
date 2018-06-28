/*
** EPITECH PROJECT, 2018
** wol check
** File description:
** win or loose check
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/matchstick.h"

int check_emptyness(char **board, int nb_line, int player_turn)
{
	for (int i = 0; i < (nb_line + 2); i++)
		for (int j = 0; board[i][j] != '\0'; j++)
			if (board[i][j] == '|') {
				my_putchar('\n');
				return (0);
			}
	return (player_turn);
}
