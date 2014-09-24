##
## Makefile for  in /home/maigna_j/rendu/rushkong
##
## Made by Jeremy Maignan
## Login   <maigna_j@epitech.net>
##
## Started on  sam. mars  08 14:28:57 2014 Jeremy Maignan
## Last update Tue Sep 23 19:42:40 2014 Marc Le Labourier
##

NAME	=	liblist.a

INC	=	-I header/

CFLAGS  =     $(INC) -Wall -Wextra -g

CC	=	gcc

AR	=	ar rc

RM	=	rm -f

DIR_SRC	=	src/

SRC	=	${DIR_SRC}list.c \
		${DIR_SRC}node.c \
		${DIR_SRC}push.c \
		${DIR_SRC}pop.c \
		${DIR_SRC}size.c \
		${DIR_SRC}iter.c \
		${DIR_SRC}iter2.c \
		${DIR_SRC}access.c \
		${DIR_SRC}insert.c \
		${DIR_SRC}insert2.c \
		${DIR_SRC}extract.c \
		${DIR_SRC}transform.c \
		${DIR_SRC}algo.c \
		${DIR_SRC}algo2.c \
		${DIR_SRC}func_parameter.c \


OBJ	=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
		$(AR) $(NAME) ${OBJ}
		ranlib ${NAME}

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
