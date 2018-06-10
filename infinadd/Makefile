##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

SRCS	=	src/addinf.c		\
		src/main.c		\
		src/my_nstrcmp.c	\
		src/sub_op.c		\
		src/remove_zero.c	\
		src/check_base.c	\
		src/add_op.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	infin_add

INC 	=	-I../include

LIB	=	-L../lib/my -lmy

CC	=	gcc

CFLAGS	=	$(INC) -W -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
		make -C ../lib/my/
		$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
