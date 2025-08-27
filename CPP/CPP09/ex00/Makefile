# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 11:06:17 by unmugviolet       #+#    #+#              #
#    Updated: 2025/08/27 09:38:30 by pjaguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			btc

ARGS =			input.txt

SRC_FILES = 	main.cpp

INPUT_FILE =	input.txt

SRC_DIR =		./srcs/
OBJ_DIR =		./objects/
DATA_DIR =		./data/
INC_DIR =		./includes/

OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

CC = c++
MAKE = make
CFLAGS = -Wall -Werror -Wextra -g3 -std=c++98

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all: setup $(NAME)

$(NAME) : $(OBJ)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean: 
	@rm -rf $(OBJ)
	@echo "$(GREEN)$(NAME) object directory cleaned!$(DEFAULT)"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(DATA_DIR)
	@echo "$(CYAN)$(NAME) executables and objects removed succesfully!$(DEFAULT)"

go: all
	@./$(NAME) $(ARGS)
	@rm -rf $(NAME)

gov: all
	@ valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)
	@rm -rf $(NAME)

setup:
	@mkdir -p $(DATA_DIR)
	@echo 'date | value' > $(DATA_DIR)$(INPUT_FILE)
	@echo 'test | notworking' >> $(DATA_DIR)$(INPUT_FILE)
	@echo 'tralala | trululu' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '1 | 2 | 3' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2023-10-26-9 | heyy' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 | 3' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2023-10-26 | 100' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2022-05-10 | yep' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2222-65-10 | yep' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2222-5-010 | yep' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2022-01-12 | 2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2022-03-18 | 1' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2008-03-18 | 1' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2008-01-01 | 1' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 | 3' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 | 1.5' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 | -1' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 | 1001' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 | abc' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 value' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 |' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '| 2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 || 2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011 -01-03 | 2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01- 03 | 2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-13-01 | 2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-00-01 | 2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-02-30 | 2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2012-02-29 | 2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-04-31 | 2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-04-30 | 2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 | 1.2  # comment' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 |	1.2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 | 3' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 | 2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 | 1' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-03 | 1.2' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2011-01-09 | 1' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2012-01-11 | -1' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2001-42-42' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2012-01-11 | 1' >> $(DATA_DIR)$(INPUT_FILE)
	@echo '2012-01-11 | 2147483648' >> $(DATA_DIR)$(INPUT_FILE)
	
	
re: fclean all

.PHONY: all clean fclean re go gov setup
