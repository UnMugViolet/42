# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by pjaguin           #+#    #+#              #
#    Updated: 2024/11/12 10:06:04 by pjaguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PROGRAM_NAME=main

CC = cc
AR = ar

FILES = main.c ft_isalpha.c ft_isalnum.c ft_tolower.c ft_strlen.c ft_isprint.c ft_isdigit.c ft_isascii.c ft_toupper.c ft_bzero.c
SRC = $(FILES)
OBJ = $(FILES:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJ)
	$(AR) -rcs $(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(PROGRAM_NAME)

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

go: 
	./$(PROGRAM_NAME)

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re go
	