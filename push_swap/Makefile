# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by pjaguin           #+#    #+#              #
#    Updated: 2025/01/16 10:50:11 by pjaguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARGS = 20 86 50 96 7 19 85 67 53 52 76 83 99 42 59 70 25 37 74 4 43 55 58 39 47 46 60 13 32 8 57 69 48 14 9 80 30 26 82 54 16 81 63 79 36 12 61 10 72 45 64 3 44 94 87 65 22 68 84 29 77 1 66 91 15 88 18 38 23 56 34 33 73 97 24 40 89 78 2 92 75 71 5 93 90 41 95 51 100 17 35 98 28 49 11 31 27 6 62 21 

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
	