/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick header
*/

int get_nb_matches(char **board, int line);
char **update(int line, int matches, char **board);
int found_line(char **board, int nb_line, int max);
char **ai_turn_two(char **board, int nb_line, int max);
char **ai_turn(char **board, int player_line, int nb_line, int max);
char *star_line_vs_force_of_evil(int last_line);
char **create_game_board(int nb_line);
char **update_game_board(int line, int nb_matches, char **board);
int empty_line(int line, char **board);
int error_line(char *command, int nb_line, char **board);
int error_matches_two(int matches, char **board, int max, int line);
int error_matches(char *command, char **board, int max, int line);
void display_command(char *name, int line, int matches);
void display_board(char **board, int nb_line);
int gameloop(char **board, int nb_line, int max);
int check_line_jump(char *str);
char *my_strdup(char *src);
char *my_strncat(char *dest, char const *src, int nb);
char *get_line(char *str, int fd);
char *get_next_line(int fd);
void help(int output);
void error_with_help(int ac);
int ask_line(int nb_line, char **board);
int ask_matches(char **board, int max, int line);
int check_emptyness(char **board, int nb_line, int player_turn);
int my_getnbr(char const *str);
void my_putchar(char c);
int my_putnbr(int nb);
void my_putstr(char *str);
char *my_strcat(char *dest, char *src);
char *input(void);
