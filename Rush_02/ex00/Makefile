# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/13 12:14:12 by pjaguin           #+#    #+#              #
#    Updated: 2024/07/14 18:22:45 by rxue             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

rush-02: rush-02.o utils.o utils2.o utils.h ft_dict.o ft_print.o
	cc $(CFLAGS) -o rush-02 rush-02.o utils.o utils2.o ft_dict.o ft_print.o

rush-02.o: rush-02.c
	cc $(CFLAGS) -c rush-02.c

ft_dict.o: ft_dict.c
	cc $(CFLAGS) -c ft_dict.c

ft_print.o: ft_print.c
	cc $(CFLAGS) -c ft_print.c

utils.o: utils.c
	cc $(CFLAGS) -c utils.c

utils2.o: utils2.c
	cc $(CFLAGS) -c utils2.c

fclean: 
	rm utils.o utils2.o rush-02.o ft_dict.o ft_print.o rush-02 
