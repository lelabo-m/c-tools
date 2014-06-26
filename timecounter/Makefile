##
## Makefile for timecounter in /home/pailli_a/school/Tek2/rendu/PSU_2013_zappy/lib/timecounter
##
## Made by Jeremy Maignan
## Login   <maigna_j@epitech.net>
##
## Started on  sam. mars  08 14:28:57 2014 Jeremy Maignan
## Last update Thu Jun 26 16:05:33 2014 Alexandre Paillier
##

NAME	=	libtimecounter.a

INC	=	-I header

CFLAGS  =	$(INC) -Wall -Wextra

LDFLAGS	=

CC	=	gcc

AR	=	ar rcs

RM	=	rm -f

DIR_SRC	=	src/

SRC	=	$(DIR_SRC)timecounter.c \

OBJ	=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
		$(AR) $(NAME) $(OBJ) $(LDFLAGS)
#		ranlib $(NAME)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
