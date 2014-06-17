##
## Makefile for  in /home/maigna_j/rendu/rushkong
##
## Made by Jeremy Maignan
## Login   <maigna_j@epitech.net>
##
## Started on  sam. mars  08 14:28:57 2014 Jeremy Maignan
## Last update Tue May 20 19:04:34 2014 Marc Le Labourier
##

NAME	=	libopt.a

INC	=	-I header/ -I ../liblist/header/

CFLAGS  =	$(INC) -Wall -Wextra

LDFLAGS	=	-L ../liblist -llist

CC	=	gcc

AR	=	ar rc

RM	=	rm -f

DIR_SRC	=	src/

SRC	=	$(DIR_SRC)opt.c \
		$(DIR_SRC)opt_free.c \
		$(DIR_SRC)opt_verbose.c \

OBJ	=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
		$(AR) $(NAME) $(OBJ)
		ranlib $(NAME)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
