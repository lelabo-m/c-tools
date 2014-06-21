##
## Makefile for  in /home/maigna_j/rendu/rushkong
##
## Made by Jeremy Maignan
## Login   <maigna_j@epitech.net>
##
## Started on  sam. mars  08 14:28:57 2014 Jeremy Maignan
## Last update Thu Jun 19 11:54:48 2014 Marc Le Labourier
##

NAME	=	libtimecounter.a

INC	=	-I header

CFLAGS  =	$(INC) -Wall -Wextra

LDFLAGS	=	

CC	=	gcc

AR	=	ar rc

RM	=	rm -f

DIR_SRC	=	src/

SRC	=	$(DIR_SRC)timecounter.c \

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
