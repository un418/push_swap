NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c \
			  disorder.c \
			  free_function.c \
			  indexator.c \
			  list_creation.c \
			  list_utils.c \
			  push.c \
			  reverse.c \
			  swap.c \
			  rotate.c \
			  sort_3.c \
			  sort_5.c \
			  int_parse.c \
			  str_utils.c \
			  wich_one.c \
			  simple_algo.c \
			  medium_algo.c	\
			  input.c 
			  

OBJS		= $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all