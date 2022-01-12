##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## yo
##

SRCS = 	src/my_ls_arg_lk_ls.c \
		src/my_ls_folder_lk_ls.c \
		src/my_ls_get_all_infos.c \
		src/my_ls_get_flags.c \
		src/my_ls_main_func.c \
		src/my_ls_sort_folder.c \
		src/my_ls_utils.c \
		src/my_ls_sort_arg.c \
		src/my_ls_printors.c \
		src/my_ls_printors_tricky.c \
		my_ls_main.c \

OBJS = ${SRCS:.c=.o}

NAME = my_ls

CC = gcc

RM = rm -f

CRIT_F = --coverage -lcriterion -I include

${NAME}:	${OBJS}
			cd include/lib_printf && make
			${CC} -o ${NAME} ${OBJS} -L include/lib_printf -lmy

all :	${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		cd include/lib_printf && make fclean
		${RM} ${NAME}

re: fclean all

test_criterion_fclean:
	rm -f *gcno
	rm -f *gcda
	rm -f unit_tests

test_criterion: test_criterion_fclean
	cd include/lib_printf && make
	${CC} -o unit_tests src/*.c tests/*.c -L include/lib_printf -lmy ${CRIT_F}

tests_run: test_criterion
	./unit_tests

.PHONY: all clean fclean re
