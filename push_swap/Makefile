 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by pjaguin           #+#    #+#              #
#    Updated: 2024/11/18 10:54:54 by pjaguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARGS = 1 "test" 2

CC = cc

LIBFT_DIR = ./libft
SRC_DIR = ./ps_srcs/
OBJ_DIR = ./ps_objects/
INC_DIR = ./ps_includes/

FILES = main.c input_check.c

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

MAKE = make
CFLAGS = -Wall -Werror -Wextra -g

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all: $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp ./libft/libft.a .
	@mv libft.a $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -I $(INC_DIR) -o $(NAME)


$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean: 
	@rm -rf $(OBJ)
	@echo "$(BLUE)$(NAME) object files cleaned!$(DEFAULT)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(CYAN)$(NAME) executables and objects removed succesfully!$(DEFAULT)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)libft executables and objects removed succesfully!$(DEFAULT)"
	
re: fclean all

go: all
	./$(NAME) $(ARGS)

debug: all
	lldb ./$(NAME)

gov: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re go debug gov
	