############  PUSH SWAP  ############

SHELL		= /bin/bash
NAME		= push_swap

############  Compiler Config  ############

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I$(INC_DIR) -I$(FT_PRINTF_DIR)/inc

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

############  Library Config  ############

FT_PRINTF_DIR	= lib/ft_printf
FT_PRINTF		= $(FT_PRINTF_DIR)/libftprintf.a

############  Files Config  ############

HEADER		= $(INC_DIR)/push_swap.h
MAIN_FILE	= $(SRC_DIR)/$(NAME).c

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
SRC_FILES	=	input.c		\
				str_utils.c	\
				int_parse.c \
				indexator.c \
				list_creation.c \
				list_utils.c \
				check_size_input.c \
				bench_mode.c \
				op_output.c \
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

$(NAME): $(OBJS) $(MAIN_FILE) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_FILE) $(FT_PRINTF) $(INCS) -o $@

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# unit test are use to debug via gdb
build_unit_test: CFLAGS += -g3 -fsanitize=address
build_unit_test: fclean $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(TEST_DIR)/unit_test.c $(INCS) $(FT_PRINTF) -o $(TEST_DIR)/unit_test
	rm -f $(OBJS)

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
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean tclean
	rm -f push_swap
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

tclean:
	rm -f $(TEST_DIR)/unit_test


.PHONY: all clean fclean re tclean build_unit_test unit_test integration_test leaks
