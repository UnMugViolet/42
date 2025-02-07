# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by pjaguin           #+#    #+#              #
#    Updated: 2025/02/07 11:18:14 by pjaguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT_DIR = ./libft
SRC_DIR = ./srcs/
OBJ_DIR = ./objects/
INC_DIR = ./includes/

FILES = fract-ol.c

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

CC = cc
MAKE = make
CFLAGS = -Wall -Werror -Wextra -g
OS = $(shell uname -s)

# handle the different OS
ifeq ($(OS), Linux)
	MLX_DIR = ./minilibx_linux/
	LDLIBS = -lmlx -lm -lz -lXext -lX11 -lft
else
	MLX_DIR = ./minilibx_opengl/
	LDFLAGS = -lft -lmlx -lm -framework OpenGl -framework AppKit
endif

LDFLAGS = -L$(MLX_DIR) -L$(LIBFT_DIR)
INC_H = -I $(INC_DIR) -I $(LIBFT_DIR)/includes -I $(MLX_DIR)

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all: $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR) >> /dev/null
	@cp $(MLX_DIR)/libmlx.a .
	@echo "$(GREEN)minilibx compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(INC_H) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@
	

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean: 
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(NAME) object files cleaned!$(DEFAULT)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(CYAN)$(NAME) executables and objects removed succesfully!$(DEFAULT)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)libft executables and objects removed succesfully!$(DEFAULT)"
	@$(MAKE) clean -C $(MLX_DIR)
	@echo "$(CYAN)minilibx executables and objects removed succesfully!$(DEFAULT)"
	
re: fclean all 

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re 
	