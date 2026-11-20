

NAME = undo_stack

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       ft_strlen.c \
       ft_stack_push.c \
       ft_stack_pop.c \
       ft_stack_size.c \
       ft_stack_clear.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c stack.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
