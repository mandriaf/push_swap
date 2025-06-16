SRC = $(wildcard *.c)
NAME = push_swap
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
all: $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all