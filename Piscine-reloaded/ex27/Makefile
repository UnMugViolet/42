# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 13:55:33 by pjaguin           #+#    #+#              #
#    Updated: 2024/11/08 11:27:07 by pjaguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRC_DIR = ./srcs/
INC_DIR = ./includes/

CC = cc

FILES = main.c ft_putstr.c
SRC = $(addprefix $(SRC_DIR), $(FILES))
OBJ = $(FILES:.c=.o)
CFLAGS = -Wall -Werror -Wextra -I $(INC_DIR)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

# Specify that these arenot files to compile (just for safety)
.PHONY: all clean fclean re
	