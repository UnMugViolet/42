# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by pjaguin           #+#    #+#              #
#    Updated: 2025/04/17 17:54:14 by pjaguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_DIR = 		./srcs/
OBJ_DIR = 		./objects/
INC_DIR = 		./includes/

# Directories for categorized source files
DIRS = 			utils parsing libft

# Source files for each directory
FILES = 		philo.c init.c threads.c actions.c monitor.c

LIBFT_FILES = 	ft_putstr_fd.c ft_atoi.c ft_isdigit.c ft_strlen.c ft_is_whitespace.c 

UTILS_FILES = 	utils.c print_message.c

PARSING_FILES = parsing.c

SRC_FILES = 	$(FILES) \
				$(addprefix libft/, $(LIBFT_FILES)) \
				$(addprefix utils/, $(UTILS_FILES)) \
				$(addprefix parsing/, $(PARSING_FILES)) \

OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

CC = cc
MAKE = make
CFLAGS = -Wall -Werror -Wextra -g 
INC_H = -I $(INC_DIR)

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(INC_H) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
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

debug: all
	@lldb $(NAME)
	@rm -rf $(NAME)

norm:
	@norm -d srcs
	@norm -d srcs/utils
	@norm -d includes
	@norminette
	

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re go gov debug
