/*
** EPITECH PROJECT, 2018
** error command
** File description:
** check player command
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/matchstick.h"

int empty_line(int line, char **board)
{
	for (int i = 1; board[line][i] != '|'; i++)
		if (board[line][i] == '*') {
			write(1, "Error: not enough matches on this line\n",
			      39);
			return (1);
		}
	return (0);
}

int error_line(char *command, int nb_line, char **board)
{
	int line = 0;

	if (command[0] == '-') {
		write(1, "Error: this line is out of range\n", 33);
		return (1);
	}
	for (int i = 0; command[i] != '\0'; i++)
		if (command[i] < '0' || command[i] > '9' ||
		    command[0] == '\n') {
			write(1, "Error: invalid input (positive number expected)\n", 49);
			return (1);
		}
	line = my_getnbr(command);
	if (line > nb_line) {
		write(1, "Error: this line is out of range\n", 33);
		return (1);
	}
	return (empty_line(line, board));
}

int error_matches_two(int matches, char **board, int max, int line)
{
	int check = 0;
	if (matches > max) {
		write(1, "Error: you cannot remove more than ", 35);
		my_putnbr(max);
		write(1, " matches per turn\n", 18);
		return (1);
	}
	for (int i = 1; board[line][i] != '*'; i++)
		if (board[line][i] == '|')
			check++;
	if (check < matches) {
		write(1, "Error: not enough matches on this line\n", 39);
		return (1);
	}
	return (0);
}

int error_matches(char *command, char **board, int max, int line)
{
	int matches = 0;

	if (command[0] == '-') {
		write(1, "Error: you have to remove at least one match\n", 45);
		return (1);
	}
	for (int i = 0; command[i] != '\0'; i++)
		if (command[i] < '0' || command[i] > '9') {
			write(1,"Error: invalid input (positive number expected)\n", 49);
			return (1);
		}
	matches = my_getnbr(command);
	if (matches == 0) {
		write(1, "Error: you have to remove at least one match\n", 45);
		return (1);
	}
	return (error_matches_two(matches, board, max, line));
}
