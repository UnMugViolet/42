# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 11:06:17 by unmugviolet       #+#    #+#              #
#    Updated: 2025/05/14 12:04:47 by pjaguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			account

SRC_FILES = 	tests.cpp Account.cpp

OBJ_DIR =		./objects/

OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

CC = c++
MAKE = make
CFLAGS = -Wall -Werror -Wextra -g3 -std=c++98


DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all: $(NAME)

$(NAME): $(OBJ) | $(OBJ_DIR)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean: 
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(NAME) object directory cleaned!$(DEFAULT)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(CYAN)$(NAME) executables and objects removed successfully!$(DEFAULT)"
    
re: fclean all

go: all
	@./$(NAME)
	@rm -rf $(NAME)

gov: all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
	@rm -rf $(NAME)

.PHONY: all clean fclean re
	