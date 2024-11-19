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

CC = cc
AR = ar -rcs

LIBFT_DIR = ./libft

FILES = 
BONUS_FILES = 
OBJ = $(FILES:.c=.o)
MAKE = make
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ) : $(FILES)
	# $< Get all the sources files one by one
	# $^ Get all the dest one by one 
	# $@ Get all the sources
	$(CC) $(CFLAGS) -c $< $^
	
clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	
re: fclean all

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re
	