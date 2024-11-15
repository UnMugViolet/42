# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by pjaguin           #+#    #+#              #
#    Updated: 2024/11/15 08:44:39 by pjaguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PROGRAM_NAME=main

CC = cc
AR = ar

FILES = main.c ft_isalpha.c ft_isalnum.c ft_tolower.c ft_strlen.c ft_isprint.c ft_isdigit.c ft_isascii.c ft_toupper.c \
		ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c
SRC = $(FILES)
OBJ = $(FILES:.c=.o)
CFLAGS = -Wall -Werror -Wextra -g3

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

go: all
	./$(PROGRAM_NAME)

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re go
	