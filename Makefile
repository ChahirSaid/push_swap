NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC			= push_swap.c parse_input.c stack_utils.c sort_small.c sort_large.c cost_calculation.c execute_moves.c \
			operations/push.c operations/rev_rotate.c operations/rotate.c operations/swap.c
BONUS_SRC	=  checker.c operations/push.c operations/rev_rotate.c operations/rotate.c operations/swap.c \
			parse_input.c stack_utils.c sort_small.c sort_large.c cost_calculation.c execute_moves.c

OBJ			= $(SRC:.c=.o)
BONUS_OBJ	= $(BONUS_SRC:.c=.o)

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

all: $(NAME)
bonus: $(BONUS_NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

%.o: %.c push_swap.h checker.h
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus

.SECONDARY: $(OBJ) $(BONUS_OBJ)