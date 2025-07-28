SRC = ./mandatory/push_swap.c ./mandatory/big_sort.c ./mandatory/calculate_cost_push_a.c ./mandatory/calculate_cost_push_b.c \
		./mandatory/calculate_cost_utils.c	./mandatory/calculate_cost_utils2.c ./mandatory/check_arg.c ./mandatory/choice_target.c \
		./mandatory/create_sort_tab.c ./mandatory/find_function.c ./mandatory/free_stack.c ./mandatory/ft_atoi.c ./mandatory/ft_split.c \
		./mandatory/ft_strdup.c ./mandatory/ft_strjoin.c ./mandatory/ft_strlen.c ./mandatory/init_stack.c ./mandatory/is_sorted.c \
		./mandatory/lstadd_back.c ./mandatory/move.c ./mandatory/new_stack.c ./mandatory/push.c ./mandatory/reverse_rotate.c \
		./mandatory/rotate.c ./mandatory/sort_five.c ./mandatory/sort_three.c ./mandatory/sort.c ./mandatory/stack_size.c \
		./mandatory/swap.c ./mandatory/util_sort.c

BONUS = ./bonus/check_arg.c ./bonus/checker.c ./bonus/free_stack.c ./bonus/ft_atoi.c ./bonus/ft_split.c ./bonus/ft_strcmp.c ./bonus/ft_strdup.c \
		./bonus/ft_strjoin.c ./bonus/ft_strlen.c ./bonus/init_stack.c ./bonus/instructions.c ./bonus/is_sorted.c ./bonus/lstadd_back.c ./bonus/new_stack.c \
		./bonus/print_error.c ./bonus/push.c ./bonus/reverse_rotate.c ./bonus/rotate.c ./bonus/stack_size.c ./bonus/swap.c ./bonus/get_next_line/get_next_line.c \
		./bonus/get_next_line/get_next_line_utils.c

NAME = push_swap

BONUS_NAME = checker

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME) : $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJ)

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
