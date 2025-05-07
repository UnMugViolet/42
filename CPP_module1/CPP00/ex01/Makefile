# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 11:06:17 by unmugviolet       #+#    #+#              #
#    Updated: 2025/05/06 09:25:12 by pjaguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC_DIR = 		./srcs/
OBJ_DIR = 		./objects/
INC_DIR = 		./includes/

DIRS = utils

SRC_FILES = $(shell find -type f -name "*.cpp")
OBJ = $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC_FILES))

CC = c++
MAKE = make
CFLAGS = -Wall -Werror -Wextra -g3 -std=c++98
INC_H = -I $(INC_DIR) -I $(addprefix $(INC_DIR), $(DIRS))

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all: $(NAME)

$(NAME) : $(OBJ) 
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJ) $(INC_H) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) $(addprefix $(OBJ_DIR), $(DIRS))

clean: 
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(NAME) object files cleaned!$(DEFAULT)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(CYAN)$(NAME) executables and objects removed succesfully!$(DEFAULT)"
	
re: fclean all

go: all
	@./$(NAME)
	@rm -rf $(NAME)

gov: all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
	@rm -rf $(NAME)

.PHONY: all clean fclean re go gov
	