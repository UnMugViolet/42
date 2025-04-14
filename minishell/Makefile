# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by pjaguin           #+#    #+#              #
#    Updated: 2025/04/10 12:37:22 by pjaguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT_DIR = 	./libft
SRC_DIR = 		./srcs/
OBJ_DIR = 		./objects/
INC_DIR = 		./includes/

# Directories for categorized source files
DIRS = 			env utils init lexing parsing builtins exec

# Source files for each directory
FILES = 		minishell.c path.c signals.c exit.c
ENV_FILES = 	env_utils.c env_utils2.c ft_str_substitute.c ft_replace_env_variable.c ft_remove_quotes.c
UTILS_FILES =	boolean_checks.c boolean_checks2.c struct_exec_utils.c
INIT_FILES =	init_data.c init_exec.c
LEX_FILES = 	lexing.c lex_utils.c lex_utils2.c
PARSE_FILES = 	parsing.c parse_utils.c parse_utils2.c
BUILTIN_FILES = builtins.c cd.c echo.c ft_exit.c
EXEC_FILES = 	exec.c exec_utils.c exec_utils2.c


SRC_FILES = 	$(FILES) \
                $(addprefix env/, $(ENV_FILES)) \
                $(addprefix utils/, $(UTILS_FILES)) \
                $(addprefix init/, $(INIT_FILES)) \
                $(addprefix lexing/, $(LEX_FILES)) \
                $(addprefix parsing/, $(PARSE_FILES)) \
                $(addprefix builtins/, $(BUILTIN_FILES)) \
                $(addprefix exec/, $(EXEC_FILES))

OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

CC = cc
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

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(INC_H) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME) -l readline

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
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)libft executables and objects removed succesfully!$(DEFAULT)"
	
re: fclean all

go: all
	@./$(NAME)
	@rm -rf $(NAME)

gov: all
	@valgrind --suppressions=valgrind-readline.supp --leak-check=full --track-fds=yes --show-leak-kinds=all ./$(NAME)
	@rm -rf $(NAME)

debug: all
	@lldb $(NAME)
	@rm -rf $(NAME)
	
test: all
	@cd ./minishell_tester && ./tester $(args)
	@rm -rf $(NAME)

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re go gov debug
