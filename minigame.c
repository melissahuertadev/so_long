/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minigame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 01:05:33 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/02 02:18:28 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minigame.h"

int	ft_close(void)
{
	exit(0);
}

t_sprite ft_new_sprite(void *mlx, char *fname)
{
	t_sprite spr;
	
	spr.ref = mlx_xpm_file_to_image(mlx, fname, &spr.vector.x, &spr.vector.y);
	spr.pixels = mlx_get_data_addr(spr.ref, &spr.bpp, &spr.line_size, &spr.endian);

	return(spr);
}

t_scene	ft_new_scene(void *mlx, int w, int h, char *title)

{
	t_scene	scene;

	scene.ref = mlx_new_window(mlx, w, h, title);
	scene.vector.x = w;
	scene.vector.y = h;
	mlx_hook(scene.ref, 17, 0, ft_close, 0);
	return (scene);
}

int	ft_input_key(int key, void *p)
{
	t_game		*game = (t_game *)p;
	
	mlx_clear_window(game->mlx, game->scene.ref);
	
	if (key == 100)
		game->spr_pos.x += game->sprite.vector.x;
	else if (key == 97)
		game->spr_pos.x -= game->sprite.vector.x;
	else if (key == 115)
		game->spr_pos.y += game->sprite.vector.y;
	else if (key == 119)
		game->spr_pos.y -= game->sprite.vector.y;
	
	mlx_put_image_to_window(game->mlx, game->scene.ref, game->sprite.ref, game->spr_pos.x, game->spr_pos.y);
	printf("You pressed %d\n", key);
	return(0);
}

int	ft_game_loop(void *p)
{
	t_game		*game = (t_game *)p;
	static int	frame;

	frame++;
	if(frame == FRAMES)
	{
		game->spr_pos.y +=1;
	}
	else if (frame >= FRAMES *2)
	{
		game->spr_pos.y -=1;
		frame = 0;
	}
	
	mlx_put_image_to_window(game->mlx, game->scene.ref, game->sprite.ref, game->spr_pos.x, game->spr_pos.y);
	return (0);
}

int	main(void)
{
	t_game	game;

	//Initialize the scene and sprite
	game.mlx = mlx_init();
	game.scene = ft_new_scene(game.mlx, 600, 400, "minigame");
	game.sprite = ft_new_sprite(game.mlx, "cat.xpm");
	game.spr_pos.x = 0;
	game.spr_pos.y = 0;

	//Set the sprite
	mlx_put_image_to_window(game.mlx, game.scene.ref, game.sprite.ref,
			game.spr_pos.x, game.spr_pos.y);

	//Read events
	mlx_key_hook(game.scene.ref, *ft_input_key, &game);
	mlx_loop_hook(game.mlx, *ft_game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
