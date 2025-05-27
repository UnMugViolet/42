# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by pjaguin           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2025/05/27 12:10:18 by pjaguin          ###   ########.fr        #
=======
#    Updated: 2025/05/27 11:59:48 by pjaguin          ###   ########.fr        #
>>>>>>> refs/remotes/origin/main
#                                                                              #
# **************************************************************************** #

NAME = 			cube3d

ARGS = 			map_test.cub

LIBFT_DIR = 	./libft
MLX_DIR =		./minilibx-linux/

SRC_DIR = 		./srcs/
OBJ_DIR = 		./objects/
INC_DIR = 		./includes/

# Directories for categorized source files
DIRS = 			utils init parsing

# Source files for each directory
FILES = 		main.c events.c
INIT_FILES = 	init.c
UTILS_FILES = 	utils.c
PARSE_FILES = 	parsing.c

SRC_FILES = 	$(FILES) \
                $(addprefix utils/, $(UTILS_FILES)) \
                $(addprefix init/, $(INIT_FILES)) \
                $(addprefix parsing/, $(PARSE_FILES)) \
				

OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

CC = cc
MAKE = make
LDFLAGS = -L$(MLX_DIR) -L$(LIBFT_DIR)

CFLAGS = -Wall -Werror -Wextra -g
LDLIBS = -lmlx -lm -lz -lXext -lX11 -lft
INC_H = -I $(INC_DIR) -I $(LIBFT_DIR)/includes -I $(MLX_DIR)

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR) >> /dev/null
	@cp $(MLX_DIR)/libmlx.a .
	@echo "$(GREEN)minilibx compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(INC_H) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"

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
	@$(MAKE) clean -C $(MLX_DIR)
	@echo "$(CYAN)mlx executables and objects removed succesfully!$(DEFAULT)"
	
re: fclean all

go: all
	@./$(NAME) $(ARGS)
	@rm -rf $(NAME)

gov: all
	@valgrind --suppressions=valgrind-readline.supp --leak-check=full --track-fds=yes --show-leak-kinds=all ./$(NAME) $(ARGS)
	@rm -rf $(NAME)

debug: all
	@lldb $(NAME) $(ARGS)
	@rm -rf $(NAME)
	
test: all
	@cd ./minishell_tester && ./tester $(args)
	@rm -rf $(NAME)

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re go gov debug
