# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 11:48:08 by mhuerta           #+#    #+#              #
#    Updated: 2021/11/01 03:04:09 by melissa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = minigame

SRC = minigame.c
OBJ = $(SRC:.c=.o)
	
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -L /mlx -lmlx -lXext -lX11

INCS_DIR = includes/
MLX_DIR = mlx/ 

# Colors
RESET='\033[0m'
GREEN='\033[32m'
PURPLE='\033[35m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(PURPLE) "Compiling $(NAME)..." $(RESET)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)
	@echo $(GREEN) "minigame has been compiled" $(RESET)
	@rm $(OBJ)

$(OBJ): $(SRC)
	@echo $(PURPLE) "Making object files..." $(RESET)
	@$(CC) $(CFLAGS) -c $(SRC)

run: all
	@echo "Running game... $(NAME)"
	@./$(NAME)

clean:
	@echo $(PURPLE) "Removing object files..." $(RESET)
	rm -rf $(OBJ)

fclean: clean
	@echo $(PURPLE) "Removing $(NAME)..." $(RESET)
	rm -rf $(NAME)

re: fclean all
