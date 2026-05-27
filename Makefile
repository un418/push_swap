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
SRC_FILES	=	parser.c		\
				parser_utils.c	\
				atoi.c

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

unit_test: fclean build_unit_test
	./$(TEST_DIR)/unit_test

integration_test: fclean $(NAME)
	@echo ###### PUSH SWAP -- PARSER TESTER ######

	@echo -- TEST INVALID INPUT 01 : letter input --
	bash $(TEST_DIR)/test_parser.sh 1 2 a
	@echo -- TEST INVALID INPUT 02 : int underflow --
	bash $(TEST_DIR)/test_parser.sh 1 2 -2147483649
	@echo -- TEST INVALID INPUT 03 : int overflow --
	bash $(TEST_DIR)/test_parser.sh 1 2 2147483648
	@echo -- TEST INVALID INPUT 04 : unvalid number --
	bash $(TEST_DIR)/test_parser.sh 1 2 --43
	@echo -- TEST INVALID INPUT 05 : unvalid number --
	bash $(TEST_DIR)/test_parser.sh 1 2 ++43

	@echo -- TEST INVALID FLAG 01: unvalid optional param --
	bash $(TEST_DIR)/test_parser.sh --unvalid 1 2 3
	@echo -- TEST INVALID FLAG 02: unvalid flag combination --
	bash $(TEST_DIR)/test_parser.sh --simple --complex 1 2 3
	@echo -- TEST INVALID FLAG 03: unvalid flag combination --
	bash $(TEST_DIR)/test_parser.sh --bench --bench 1 2 3
	@echo -- TEST INVALID FLAG 04: unvalid flag combination --
	bash $(TEST_DIR)/test_parser.sh --medium --medium 1 2 3

# 	@echo -- TEST INVALID INPUT (DUP) 01: duplicate number in input --
# 	bash $(TEST_DIR)/test_parser.sh 1 2 2
# 	@echo -- TEST INVALID INPUT (DUP) 01: duplicate number in input --
# 	bash $(TEST_DIR)/test_parser.sh 1 -2 -2

############  Cleaning  ############

clean:
	rm -f $(OBJS)

fclean: clean tclean

re: fclean all

tclean:
	rm -f $(TEST_PROG)
	rm -f $(TEST_DIR)/test_input
	rm -f $(TEST_DIR)/args.txt
	rm -f $(TEST_DIR)/unit_test
	rm -f $(TEST_DIR)/test_out.txt
	rm -f $(TEST_DIR)/expected_out.txt


.PHONY: all clean fclean re tclean build_unit_test unit_test integration_test
