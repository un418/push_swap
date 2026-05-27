############  PUSH SWAP  ############

SHELL		= /bin/bash

NAME		= push_swap

############  Compiler Config  ############

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I$(INC_DIR)

############  Folders Config  ############

INC_DIR		= inc
SRC_DIR		= src
OBJ_DIR		= obj
TEST_DIR	= test

############  Files Config  ############

HEADER		= $(INC_DIR)/push_swap.h
MAIN_FILE	= $(SRC_DIR)/$(NAME).c

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
SRC_FILES	=	input.c		\
				str_utils.c	\
				int_parse.c

############  Targets  ############

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_FILE) $(INCS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

build_unit_test: CFLAGS += -g3 -fsanitize=address
build_unit_test: fclean $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(TEST_DIR)/unit_test.c $(INCS) -o $(TEST_DIR)/unit_test

UT_ARGS		?= --test-all

unit_test: fclean build_unit_test
	@echo "usage: make unit_test UT_ARGS=\"--ft_atol | --in_int_limits | --is_valid_number | --test-all\""
	./$(TEST_DIR)/unit_test $(UT_ARGS)

integration_test: fclean $(NAME)
	bash $(TEST_DIR)/integration_test.sh

############  Cleaning  ############

clean:
	rm -f $(OBJS)

fclean: clean tclean

re: fclean all

tclean:
	rm -f $(TEST_DIR)/unit_test


.PHONY: all clean fclean re tclean build_unit_test unit_test integration_test
