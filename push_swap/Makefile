# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by pjaguin           #+#    #+#              #
#    Updated: 2025/01/20 17:18:08 by unmugviolet      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARGS = 136 145 458 257 90 138 419 65 76 193 306 206 379 327 103 436 309 427 322 477 317 13 125 39 177 381 215 34 218 389 122 349 298 478 248 152 253 282 441 300 333 382 247 237 266 87 30 452 140 276 118 264 1 71 330 314 108 476 361 387 219 292 383 236 401 296 133 281 249 297 421 459 56 270 457 483 198 166 107 384 256 365 84 310 465 398 190 408 439 179 437 209 345 473 240 259 301 18 72 205 405 313 23 364 467 124 9 423 497 43 498 204 222 160 418 83 14 47 54 121 199 213 8 167 225 96 283 91 348 158 311 95 37 200 104 312 153 7 239 431 214 228 227 242 223 180 64 31 141 397 284 92 129 376 99 74 58 231 324 241 268 244 101 151 355 113 192 93 224 170 178 94 69 442 48 358 485 354 185 432 210 394 262 146 143 22 344 318 353 411 315 182 425 299 321 150 343 238 258 3 495 480 159 494 127 181 132 188 20 456 60 481 350 496 291 86 386 106 487 36 154 332 288 374 176 447 304 470 455 491 157 112 201 275 440 329 120 128 369 59 409 212 174 110 187 53 434 290 195 407 168 422 220 277 80 246 175 163 55 10 326 393 186 375 245 294 191 85 412 62 19 119 388 147 70 293 41 466 464 433 216 235 57 378 78 295 169 46 260 251 278 347 252 385 274 33 32 302 400 449 6 42 380 97 320 75 489 173 229 484 285 189 337 370 27 269 462 51 165 29 197 261 109 117 469 16 372 11 448 289 392 116 196 482 161 451 316 402 89 81 137 250 359 415 114 45 416 362 371 444 131 88 363 373 68 331 272 21 35 184 334 357 368 390 142 12 17 488 342 490 135 15 479 280 126 351 156 319 435 144 171 148 263 202 438 493 194 155 139 404 255 426 500 403 172 98 486 335 336 492 49 413 472 377 286 164 463 461 2 38 130 352 265 305 308 454 230 395 233 115 346 273 356 279 338 429 221 450 445 66 211 474 271 341 340 499 102 414 4 339 5 471 420 428 149 396 453 203 162 406 63 410 67 50 443 79 207 82 328 475 123 40 24 25 44 28 52 446 77 100 26 208 366 234 232 254 267 468 325 323 367 217 61 287 226 424 105 399 134 73 460 183 430 391 111 303 417 307 243 360 

CC = cc

LIBFT_DIR = ./libft
SRC_DIR = ./ps_srcs/
OBJ_DIR = ./ps_objects/
INC_DIR = ./ps_includes/

FILES = main.c input_check.c utils.c parsing.c stack_utils.c stack_utils_find.c move_counter_ab.c \
		move_counter_ba.c swap.c push.c rotate.c reverse_rotate.c sort.c sort_three.c sort_big.c \
		rotate_and_push_ba.c rotate_and_push_ab.c cheapest_move.c

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

MAKE = make
CFLAGS = -Wall -Werror -Wextra -g
INC_H = -I $(INC_DIR) -I $(LIBFT_DIR)/includes

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all: $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(INC_H) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean: 
	@rm -rf $(OBJ)
	@echo "$(GREEN)$(NAME) object files cleaned!$(DEFAULT)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(CYAN)$(NAME) executables and objects removed succesfully!$(DEFAULT)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)libft executables and objects removed succesfully!$(DEFAULT)"
	
re: fclean all

go: all
	@echo "$(CYAN) ./$(NAME) $(WHITE)"
	@./$(NAME) $(ARGS)

debug: all
	@echo "$(CYAN) lldb ./$(NAME) $(WHITE)"
	@ lldb ./$(NAME) $(ARGS)

gov: all
	@echo "$(CYAN) valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)$(WHITE)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re go debug gov
	