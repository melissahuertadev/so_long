/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minigame.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:05:56 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/01 02:33:46 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINIGAME_H
# define MINIGAME_H

# include "../mlx/mlx.h"
# include <stdlib.h>

typedef struct		s_vector {
	int		x;
	int		y;
}			t_vector;

typedef struct		s_image {
	void		*reference;
	t_vector	vector;
	char		*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_image;

typedef struct		s_scene {
	void		*ref;
	t_vector	vector;
}			t_scene;


typedef	struct		s_game {
	void		*mlx;
	t_scene		scene;
	t_image		image;
	t_vector	sprite_position;
}			t_game;

t_scene	ft_new_scene(void *mlx, int w, int h, char *title);

#endif

