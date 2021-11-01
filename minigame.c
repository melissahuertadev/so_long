/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minigame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 01:05:33 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/01 03:06:06 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minigame.h"

int	ft_close()
{
	exit(0);
}

t_scene		ft_new_scene(void *mlx, int w, int h, char *title)
{
	t_scene	scene;

	scene.ref = mlx_new_window(mlx, w, h, title);
	scene.vector.x = w;
	scene.vector.y = h;

	mlx_hook(scene.ref, 17, 0, ft_close, 0);

	return(scene);
}

int main()
{
       t_game	game;
       
       game.mlx = mlx_init();
       game.scene = ft_new_scene(game.mlx, 600, 400, "minigame");
       

       mlx_loop(game.mlx);

       return 0;
}
