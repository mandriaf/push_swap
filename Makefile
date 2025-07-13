SRC = push_swap.c big_sort.c calculate_cost_push_a.c calculate_cost_push_b.c calculate_cost_utils.c \
		check_arg.c choice_target.c create_sort_tab.c find_function.c free_stack.c ft_atoi.c ft_split.c \
		ft_strdup.c ft_strjoin.c ft_strlen.c init_stack.c is_sorted.c lstadd_back.c move.c new_stack.c \
		push.c reverse_rotate.c rotate.c sort_five.c sort_three.c sort.c stack_size.c swap.c util_sort.c

NAME = push_swap

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
