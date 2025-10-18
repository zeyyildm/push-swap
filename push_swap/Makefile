NAME = push_swap

SRCS = push_swap_utils.c push_swap.c push_swap_parse.c push_swap_errors.c turk_algo.c


OBJS = $(SRCS:.c=.o)

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g
LIBFT = ../libft/libft.a
all:$(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $^ -o $@

$(LIBFT):
	make -C ../libft

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re