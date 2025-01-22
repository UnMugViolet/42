# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by pjaguin           #+#    #+#              #
#    Updated: 2025/01/22 10:21:13 by unmugviolet      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
ARGS = 5 6 7 8 9 11 10 0 1 2 3 4 
CC = cc

LIBFT_DIR = ./libft
SRC_DIR = ./ps_srcs/push_swap/
BONUS_SRC_DIR = ./ps_srcs/checker/
OBJ_DIR = ./ps_objects/
INC_DIR = ./ps_includes/

FILES = main.c input_check.c utils.c parsing.c stack_utils.c stack_utils_find.c move_counter_ab.c \
		move_counter_ba.c swap.c push.c rotate.c reverse_rotate.c sort.c sort_three.c sort_big.c \
		rotate_and_push_ba.c rotate_and_push_ab.c cheapest_move.c

BONUS_FILES = checker.c

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_DIR), $(BONUS_FILES:.c=.o))

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

$(BONUS) : $(BONUS_OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)$(NAME) bonuses compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(INC_H) $(BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $(BONUS)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean: 
	@rm -rf $(OBJ)
	@rm -rf $(BONUS_OBJ)
	@echo "$(GREEN)$(NAME) object files cleaned!$(DEFAULT)"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@echo "$(CYAN)$(NAME) executables and objects removed succesfully!$(DEFAULT)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)libft executables and objects removed succesfully!$(DEFAULT)"
	
re: fclean all

bonus: all $(BONUS)

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
.PHONY: all clean fclean re bonus go debug gov
	