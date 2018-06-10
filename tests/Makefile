SRC_DIR		=	$(realpath ../src)

SRC_DIR_INFINADD=	$(realpath ../infinadd/src)

SRC		=	$(SRC_DIR)/check_before_start.c	\
			$(SRC_DIR)/check_multi.c	\
			$(SRC_DIR)/div_it.c		\
			$(SRC_DIR)/factors.c		\
			$(SRC_DIR)/multi.c		\
			$(SRC_DIR)/my_strtol.c		\
			$(SRC_DIR)/my_forcat.c		\
			$(SRC_DIR)/summands.c		\
			$(SRC_DIR_INFINADD)/addinf.c	\
			$(SRC_DIR_INFINADD)/add_op.c	\
			$(SRC_DIR_INFINADD)/check_base.c	\
			$(SRC_DIR_INFINADD)/my_nstrcmp.c	\
			$(SRC_DIR_INFINADD)/remove_zero.c	\
			$(SRC_DIR_INFINADD)/sub_op.c	\
			./main.c

SRC_UT_DIR	=	$(realpath .)

SRC_UT		=	$(SRC_UT_DIR)/tests_add_it.c	\
			$(SRC_UT_DIR)/tests_sub_it.c	\
			$(SRC_UT_DIR)/tests_mod_it.c	\
			$(SRC_UT_DIR)/tests_mul_it.c	\
			$(SRC_UT_DIR)/tests_div_it.c	\
			$(SRC_UT_DIR)/tests_strtol.c

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra --coverage -fprofile-arcs -ftest-coverage

CFLAGS		+=	-I ../include

LDFLAGS		=	-L ../lib/my/ -lmy -lcriterion -lgcov

NAME		=	units

CC		=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C ../lib/my/
		cc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
		$(MAKE) clean -C ../lib/my/
		rm -f $(OBJ)
		rm -f $(SRC_DIR)/*.g*
		rm -f $(SRC_UT_DIR)/*g*

fclean:		clean
		$(MAKE) fclean -C ../lib/my/
		rm -f $(NAME)

re:		fclean all
