
NAME = libasm.a
PROG_NAME = libasm

NASM = nasm
CC = cc
CFLAGS = -Wall -Werror -Wextra -g 

SRCS = ft_strlen.s ft_strcpy.s
BONUS_SRCS =
PROG_SRC = main.c

OBJS_DIR = ./objs/
SRCS_DIR = ./srcs/
INC_DIR = ./includes/

# COLORS
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
BOLD = \033[1m
RESET = \033[0m

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.s=.o))
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(BONUS_SRCS:.s=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)$(BOLD)Compiling $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.s | $(OBJS_DIR)
	@$(NASM) -f elf64 -o $@ $<

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

prog: all
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(PROG_SRC) -o $(PROG_NAME) $(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
	@echo "$(YELLOW)$(BOLD)Compiling bonuses $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	@echo "$(RED)$(BOLD)Cleaning object files...$(RESET)"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "$(RED)$(BOLD)Cleaning $(NAME)...$(RESET)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean bonus 
