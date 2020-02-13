CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes
TARGET = rush-02
SRC = ./srcs/ft_make_dic.c \
	./srcs/ft_str.c \
	./srcs/ft_trans.c \
	./srcs/ft_trans_sub.c \
	./srcs/input_check.c \
	./srcs/main.c
OBJ = $(SRC:.c=.o)

.PHONY:all clean fclean re
all: $(TARGET)

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I $(HEADER)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all
