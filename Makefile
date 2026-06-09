############  PUSH SWAP  ############

SHELL		= /bin/bash
NAME		= push_swap

############  Compiler Config  ############

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I$(INC_DIR)

############  Valgrind Config  ############

VALGRIND	= valgrind --leak-check=full \
					  --show-leak-kinds=all \
					  --track-origins=yes \
					  --error-exitcode=42
# Set exit code of valgring to 42, to be able to make difference between program and valgring error later.

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
				int_parse.c \
				indexator.c \
				list_creation.c \
				list_debug.c \
				list_utils.c \
				swap.c \
				push.c \
				rotate.c \
				reverse.c \
				disorder.c \
				wich_one.c \
				adaptive_mode.c \
				simple_algo.c \
				medium_algo.c \
				complex_algo.c \
				sort_3.c \
				sort_5.c
			

############  Targets  ############

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_FILE) $(INCS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# unit test are use to debug via gdb
build_unit_test: CFLAGS += -g3 -fsanitize=address
build_unit_test: fclean $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(TEST_DIR)/unit_test.c $(INCS) -o $(TEST_DIR)/unit_test

UT_ARGS		?= --test-all
unit_test: fclean build_unit_test
	@echo "usage: make unit_test UT_ARGS=\"<suite>\"  (e.g. --swap | --disorder | --test-all)"
	./$(TEST_DIR)/unit_test $(UT_ARGS)

integration_test: fclean $(NAME)
	bash $(TEST_DIR)/integration_test.sh

leaks: fclean $(NAME)
# all exit path of the program should have a line of test to validate leaks on error management
	$(VALGRIND) ./push_swap 3 1 2      # nominal
	$(VALGRIND) ./push_swap 3 1 ++2    # format error
	$(VALGRIND) ./push_swap 5 3 1 4 2  # fill_stack + indexator path

############  Cleaning  ############

clean:
	rm -f $(OBJS)

fclean: clean tclean

re: fclean all

tclean:
	rm -f $(TEST_DIR)/unit_test


.PHONY: all clean fclean re tclean build_unit_test unit_test integration_test leaks
