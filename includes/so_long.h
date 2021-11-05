/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:05:56 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/05 03:01:44 by melissa          ###   ########.fr       */
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
# define NRM "\033[0m"
# define RED "\033[31m"

typedef struct s_vector {
	int		x;
	int		y;
}			t_vector;

typedef struct s_sprite {
	void		*ref;
	t_vector	vector;
	char		*pixels;
	int			bpp;
	int			line_size;
	int			endian;
}			t_sprite;

typedef struct s_scene {
	void		*ref;
	t_vector	vector;
}			t_scene;

typedef struct s_game {
	void		*mlx;
	t_scene		scene;
	t_sprite	sprite;
	t_vector	spr_pos;
}			t_game;

void			error_message(char *message);
void			ext_checker(char *map, char *ext);
void			map_init(t_game	*game, char *map);

int			ft_input_key(int key, void *game);
int			ft_game_loop(void *param);
t_sprite	ft_new_sprite(void *mlx, char *fname);
t_scene		ft_new_scene(void *mlx, int w, int h, char *title);

#endif
