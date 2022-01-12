##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## yo
##

SRCS	=	src/my_printf_utils.c \
			src/my_printf_hub.c	\
			src/my_printf_utils.c	\
			src/my_printf_main.c \
			src/my_printf_convertor.c	\
			src/my_printf_integers.c	\
			src/my_printf_parsing.c	\
			src/my_printf_chars.c	\

OBJS = ${SRCS:.c=.o}

RM = rm -f

CRITERION_F = --coverage -lcriterion -I include

NAME = libmy.a

all : ${NAME}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

test_criterion_fclean:
	rm -f *gcno
	rm -f *gcda
	rm -f unit_tests

test_criterion: test_criterion_fclean
	${CC} -o unit_tests src/*.c tests/*.c ${CRITERION_F}

tests_run: test_criterion
	./unit_tests

.PHONY: all clean fclean re
