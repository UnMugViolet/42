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

NAME = libftprintf.a
PROGRAM = prog

CC = cc
AR = ar -rcs

LIBFT_DIR = ./libft
SRC_DIR = ./pf_srcs/
OBJ_DIR = ./pf_objects/
INC_DIR = ./pf_includes/

FILES = ft_printf.c ft_printf_utils.c

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

MAKE = make
CFLAGS = -Wall -Werror -Wextra -g3

DEF_COLOR = \033[0;90m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all: $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp ./libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"
	# @$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -I $(INC_DIR) -o $(PROGRAM)


$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean: 
	@rm -rf $(OBJ)
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(CYAN)ft_printf executables and objects removed succesfully!$(DEF_COLOR)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)libft executables and objects removed succesfully!$(DEF_COLOR)"
	
re: fclean all

go: all
	./$(PROGRAM)

debug: all
	lldb ./$(PROGRAM)

gov: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROGRAM)

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re go debug
	