/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minigame.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:05:56 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/02 01:48:31 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIGAME_H
# define MINIGAME_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>

# ifndef FRAMES
#  define FRAMES 10
# endif

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

int			ft_input_key(int key, void *game);
int			ft_game_loop(void *param);
t_sprite	ft_new_sprite(void *mlx, char *fname);
t_scene		ft_new_scene(void *mlx, int w, int h, char *title);

#endif
