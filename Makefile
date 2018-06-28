##
## EPITECH PROJECT, 2017
## makefile cat
## File description:
## build the cat
##

CC	=	gcc

OBJ	=	src/my_getnbr.c		\
		src/my_putchar.c	\
		src/my_putstr.c		\
		src/my_putnbr.c		\
		src/my_strcat.c		\
		src/wol_check.c		\
		src/ai.c		\
		src/input.c		\
		src/error_command.c	\
		src/player_command.c	\
		src/gameloop.c		\
		src/board.c		\
		src/main.c

RM	=	rm -f

NAME	=	matchstick

LIB	=	-Iinclude

COM	=	$(OBJ:.c=.o)

FLAG	=	-Iinclude

TEST	=	tests/unittest.c

TESTNAM	=	test

TESTFLA	=	-lcriterion -coverage

TESTCOM	=	$(TEST:.c=.o)

all:	$(COM)
	$(CC) -o $(NAME) $(COM) $(FLAG)
	make clean

clean:
	$(RM) $(COM)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

test_clean:
		$(RM) $(TESTCOM)

tests_run:	$(TESTCOM)
		$(CC) -o $(TESTNAM) $(TESTCOM) $(TESTFLA)
		make test_clean
		./$(TESTNAM)

##bonus_bin:
##		cd bonus/; make re
##		mv bonus/my_sokoban bonus_bin
