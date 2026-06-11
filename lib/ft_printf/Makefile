SHELL		= /bin/sh

# ─── Output ──────────────────────────────────────────────────────────────────

NAME		= libftprintf.a

# ─── Compiler ────────────────────────────────────────────────────────────────

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# ─── Directories ─────────────────────────────────────────────────────────────

SRC_DIR		= src
INC_DIR		= inc
OBJ_DIR		= obj
TEST_DIR	= test

# ─── Sources ─────────────────────────────────────────────────────────────────

SRC_FILES	=	ft_printf.c \
				ft_printf_ascii.c \
				ft_printf_num.c

HEADERS		=	$(INC_DIR)/ft_printf.h \
				$(SRC_DIR)/ft_printf_private.h
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# ─── Build ────────────────────────────────────────────────────────────────────

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
