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

NAME = libft.a

CC = cc
AR = ar -rcs

FILES = 
BONUS_FILES = 
OBJ = $(FILES:.c=.o)
OBJ_BONUS = $(BONUS_FILES:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ) : $(FILES)
	# $< Get all the sources files one by one
	# $^ Get all the dest one by one 
	# $@ Get all the sources
	$(CC) $(CFLAGS) -c $< $^
	
$(OBJ_BONUS) : $(BONUS_FILES)
	$(CC) $(CFLAGS) -c $< $^
	
clean: 
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

bonus: all $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re go
	