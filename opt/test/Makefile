##
## Makefile for  in /home/lelabo/rendu/PSU_2013_zappy/opt
## 
## Made by lelabo_m
## Login   <lelabo@epitech.net>
## 
## Started on  Tue May 13 11:04:54 2014 lelabo_m
## Last update Tue May 13 16:08:17 2014 lelabo_m
##

CC	=	cc

RM	=	rm -rf

NAME	=	opt_parsing

CFLAGS	=	-Wextra -Wall

CFLAGS	+=	-I ../header -I ../../liblist/header

LDFLAGS	=	-llist -L ../../liblist

SRC	=	../src/opt.c \
		../src/opt_verbose.c \
		../src/opt_free.c \
		opt_test.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	@make -C ../../liblist
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
