# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 13:55:33 by pjaguin           #+#    #+#              #
#    Updated: 2024/11/06 17:09:46 by pjaguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_DIR = ./srcs/
INC_DIR = ./includes/

CC = cc
AR = ar

FILES = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
SRC = $(addprefix $(SRC_DIR), $(FILES))
OBJ = $(FILES:.c=.o)
CFLAGS = -Wall -Werror -Wextra -I $(INC_DIR)


all: $(NAME)

$(NAME) : $(OBJ)
	$(AR) -rcs $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	# $< Get all the sources files one by one
	# $^ Get all the dest one by one 
	# $@ Get all the sources
	$(CC) $(CFLAGS) -c $< $^
	
clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

# Specify that these arenot files to compile (just for safety)
.PHONY: all clean fclean re
