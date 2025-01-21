# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by pjaguin           #+#    #+#              #
#    Updated: 2025/01/21 16:08:29 by unmugviolet      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARGS = 65 35 26 71 56 84 93 63 8 95 27 79 28 41 12 5 67 29 98 31 91 55 53 14 90 73 24 18 97 20 40 94 0 46 33 66 99 42 51 6 38 87 80 30 82 89 70 43 4 83 34 49 92 61 39 75 58 1 59 7 10 22 11 77 23 78 15 52 16 68 72 19 25 3 47 50 74 54 62 45 2 76 88 13 57 86 17 81 96 44 21 64 37 60 32 36 48 9 85 69

CC = cc

LIBFT_DIR = ./libft
SRC_DIR = ./ps_srcs/
OBJ_DIR = ./ps_objects/
INC_DIR = ./ps_includes/

FILES = main.c input_check.c utils.c parsing.c stack_utils.c stack_utils_find.c move_counter_ab.c \
		move_counter_ba.c swap.c push.c rotate.c reverse_rotate.c sort.c sort_three.c sort_big.c \
		rotate_and_push_ba.c rotate_and_push_ab.c cheapest_move.c

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

MAKE = make
CFLAGS = -Wall -Werror -Wextra -g
INC_H = -I $(INC_DIR) -I $(LIBFT_DIR)/includes

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all: $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(INC_H) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean: 
	@rm -rf $(OBJ)
	@echo "$(GREEN)$(NAME) object files cleaned!$(DEFAULT)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(CYAN)$(NAME) executables and objects removed succesfully!$(DEFAULT)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)libft executables and objects removed succesfully!$(DEFAULT)"
	
re: fclean all

go: all
	@echo "$(CYAN) ./$(NAME) $(WHITE)"
	@./$(NAME) $(ARGS)

debug: all
	@echo "$(CYAN) lldb ./$(NAME) $(WHITE)"
	@ lldb ./$(NAME) $(ARGS)

gov: all
	@echo "$(CYAN) valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)$(WHITE)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re go debug gov
	