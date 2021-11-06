/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:05:56 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/06 00:57:07 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/mlx/mlx.h"
# include "../libraries/libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef FRAMES
#  define FRAMES 10
# endif

# define EXT ".ber"
# define EXT_LEN 4
# define BUF_LEN 10000
# define NRM "\033[0m"
# define RED "\033[31m"

typedef struct s_game {
	int		fd;
	char	*mapline;
	int		ret;
	int		row;	
	int		col;
	int		pct;
	int		cct;
	int		ect;
}			t_game;

void			error_message(char *message);
void			ext_checker(char *map, char *ext);
void			vertical_walls(t_game *game, char *l);
void			horizontal_walls(char	*line);
void			map_components(t_game *game);
void			map_valid(t_game *game);
void			map_init(t_game *game, char *mapfile);
void			scene_malloc(t_game *game, char *mapfile);
void			scene_init(t_game *game, char *mapfile);

#endif
