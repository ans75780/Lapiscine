SRC			= main.c ft_io.c ft_math.c ft_valid.c ft_setting.c ft_print.c ft_utils.c

SRCDIR		= ./srcs/
INCDIR		= includes
SRCS		= ${addprefix ${SRCDIR}, ${SRC}}
OBJS		= ${SRCS:.c=.o}

NAME		= bsq
GCC			= gcc
CTAGS		= -Wall -Werror -Wextra
RM			= rm -f

.c.o:
			${GCC} ${CTAGS} -c $< -o ${<:.c=.o} -I${INCDIR}

${NAME}:	${OBJS}
			${GCC} ${CTAGS} -o ${NAME} ${OBJS}

all:		${NAME}
clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		.c.o  clean fclean re
