SRC			= main.c ft_io.c ft_math.c

SRCDIR		= ./srcs/
INCDIR		= includes
SRCS		= ${addprefix ${SRCDIR}, ${SRC}}
OBJS		= ${SRCS:.c=.o}

NAME		= bsq
GCC			= gcc -Wall -Werror -Wextra
RM			= rm -f

.c.o:
			${GCC} -c $< -o ${<:.c=.o} -I${INCDIR}

${NAME}:	${OBJS}
			${GCC} -o ${NAME} ${OBJS}

all:		${NAME}
clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		.c.o all clean fclean re
