# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 11:48:08 by mhuerta           #+#    #+#              #
#    Updated: 2021/11/06 01:22:00 by mhuerta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re libft minilibx

NAME = so_long

SRCS_FILES = so_long.c scene_init.c map_validation.c checker.c
SRCS_DIR = srcs

HEADER_FILE = includes/so_long.h

MLX_DIR = libraries/mlx
LIB_DIR = libraries/libft
MINILIBX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIB_DIR)/libft.a

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)
	
CC = clang -g3 -fsanitize=address
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -L -lmlx -lXext -lX11

# Colors
RESET='\033[0m'
GREEN='\033[32m'
PURPLE='\033[35m'

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS) $(HEADER_FILE)
	@echo $(PURPLE) "Compiling $(NAME)..." $(RESET)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
	@echo $(GREEN) "so_long has been compiled" $(RESET)
	@rm $(OBJS)

$(LIBFT):
	make -C $(LIB_DIR)

$(MINILIBX):
	make -C $(MLX_DIR)
	
run: all
	@echo "Running game... $(NAME)"
	@./$(NAME)

clean:
	@echo $(PURPLE) "Removing object files..." $(RESET)
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	@echo $(PURPLE) "Removing $(NAME)..." $(RESET)
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re: fclean all
