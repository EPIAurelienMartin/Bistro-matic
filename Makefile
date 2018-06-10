##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

SRCS	=	src/main.c			\
		src/my_strtol.c			\
		src/div_it.c			\
		src/summands.c			\
		src/factors.c			\
		infinadd/src/addinf.c		\
		infinadd/src/my_nstrcmp.c	\
		infinadd/src/sub_op.c		\
		infinadd/src/add_op.c		\
		infinadd/src/check_base.c	\
		infinadd/src/remove_zero.c	\
		src/check_multi.c		\
		src/multi.c			\
		src/check_before_start.c	\
		src/check_base_op.c		\
		src/my_forcat.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	calc

RM	=	rm -f

INC 	=	-Iinclude

LIB	=	-Llib/my -lmy

CC	=	gcc

CFLAGS	=	$(INC) -W -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
		make -C lib/my/
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIB)

clean:
		make clean -C ./lib/my/
		$(RM) $(OBJS)

fclean:		clean
		make fclean -C ./lib/my/
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
