############   PUSH SWAP  ############

SHELL		= /bin/bash

NAME		= push_swap
TEST_PROG	= push_swap_test

############  Compiler Config  ############

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I$(INC_DIR)

############  Folders Config  ############

INC_DIR     = inc
SRC_DIR     = src
OBJ_DIR     = obj

############  Files Config  ############

TEST_FILE	= test.c
TEST_DIR	= test

HEADER		= $(INC_DIR)/push_swap.h

SRC_FILES	=	push_swap.c \
				parser.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

############  Targets  ############

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(TEST_PROG): $(OBJS) $(TEST_FILE)
	$(CC) $(CFLAGS) $(OBJS) $(TEST_FILE) $(INCS) -o $@

test: CFLAGS += -g3 -fsanitize=address
test: fclean $(TEST_PROG)
	./$(TEST_PROG) | cat -e

debug: CFLAGS += -g3 
debug: fclean $(OBJS) $(TEST_FILE)
	$(CC) $(CFLAGS) $(OBJS) $(TEST_FILE) $(INCS) -o test_suite_debug

test_parser: $(NAME)
	@echo -- TEST INVALID INPUT 01 : letter in input --
	@bash $(TEST_DIR)/test_parser.sh 1 2 a
	@echo -- TEST INVALID INPUT 02: duplicate number in input --
	@bash $(TEST_DIR)/test_parser.sh 1 2 2
	@echo -- TEST INVALID INPUT 02: unvalid optional param --
	@bash $(TEST_DIR)/test_parser.sh --unvalid 1 2 3

############  Cleaning  ############
clean:
	rm -f $(OBJS)

fclean: clean tclean

re: fclean all

tclean:
	rm -f $(TEST_DIR)/$(TEST_PROG)
	rm -f $(TEST_DIR)/$(TEST_PROG)_debug
	rm -f $(TEST_DIR)/args.txt
	rm -f $(TEST_DIR)/test_input


.PHONY: all clean fclean re test debug tclean 
