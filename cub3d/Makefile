# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by pjaguin           #+#    #+#              #
#    Updated: 2025/07/01 10:19:31 by pjaguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			cub3D

ARGS = 			./maps/surprisesurpise.cub

LIBFT_DIR = 	./libft
MLX_DIR =		./minilibx-linux/

SRC_DIR = 		./srcs/
OBJ_DIR = 		./objects/
INC_DIR = 		./includes/

# Directories for categorized source files
DIRS = 			utils init parsing check display raycast

# Source files for each directory
FILES = 		main.c events.c movements.c
INIT_FILES = 	init.c
UTILS_FILES = 	utils.c map_utils.c utils_2.c utils_3.c set_struct.c getters.c
PARSE_FILES = 	parsing.c
CHECK_FILES = 	check_map_file.c check_textures.c map_borders.c check_map.c
DISPLAY_FILES = display_utils.c colors_utils.c player.c render.c wall.c display_all.c
RAYCAST_FILES = raycast.c raycast_utils.c 

SRC_FILES = 	$(FILES) \
                $(addprefix utils/, $(UTILS_FILES)) \
                $(addprefix init/, $(INIT_FILES)) \
                $(addprefix parsing/, $(PARSE_FILES)) \
				$(addprefix check/, $(CHECK_FILES)) \
				$(addprefix display/, $(DISPLAY_FILES)) \
				$(addprefix raycast/, $(RAYCAST_FILES)) 
				
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
UNDERLINE = \033[4m

## —— Compiling ——————————————————————————————————————————————————————————————
all: $(NAME) ## Launch the project

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

## —— Cleaning ——————————————————————————————————————————————————————————————
clean: ## Delete the objects files only for cub3d
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(NAME) object files cleaned!$(DEFAULT)"

fclean: clean ## Delete all the objects and libraries 
	@rm -rf $(NAME)
	@echo "$(CYAN)$(NAME) executables and objects removed succesfully!$(DEFAULT)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)libft executables and objects removed succesfully!$(DEFAULT)"
	@$(MAKE) clean -C $(MLX_DIR)
	@echo "$(CYAN)mlx executables and objects removed succesfully!$(DEFAULT)"
	
re: fclean all

rego : re go

## —— Production ——————————————————————————————————————————————————————————————
go: all ## Launch the projects
	@./$(NAME) $(ARGS)
	@rm -rf $(NAME)

gov: all ## Launch the projects with valgrind 
	@valgrind --leak-check=full --track-fds=yes --show-leak-kinds=all ./$(NAME) $(ARGS)
	@rm -rf $(NAME)

debug: all ## Launch the projects with lldb
	@lldb $(NAME) $(ARGS)
	@rm -rf $(NAME)

help: ## Outputs this help screen
	@grep -E '(^[a-zA-Z0-9_-]+:.*?##.*$$)|(^##)' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}{printf "\033[32m%-30s\033[0m %s\n", $$1, $$2}' | sed -e 's/\[32m##/[33m/'

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re go gov debug help

