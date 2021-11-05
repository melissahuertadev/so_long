/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:10:02 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/05 05:38:28 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	tile_counter(t_game *game, int fd)
{
	char	tile;
	int	i;

	i = 0;
	game->map.c = 0;
	game->map.r = 0;
	while (read(fd, &tile, 1) > 0)
	{
		if (game->map.c < i)
			game->map.c = i;
		if (tile == '\n')
		{
			game->map.r++;
			i = 0;
		}
		else
			i++;
	}
}

/*
void	scene_set(t_game *game, char *file)
{

}*/

void	scene_malloc(t_game *game, char *file)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(file, O_RDONLY);
	tile_counter(game, fd);
	game->map.tiles = (char **)malloc(sizeof(char *) * (game->map.r));
	while (i < game->map.r)
	{
		game->map.tiles[i] = (char *)malloc(sizeof(char *) *(game->map.c));
		i++;
	}
	close(fd);
}

void	ext_checker(char *file, char *ext)
{
	int	len;
	int	i;

	len = ft_strlen((char *)file) - EXT_LEN;
	i = 0;

	if(len <= 0)
		error_message("Please, check the filename/extension.");
	while(file[len] != '\0' && ext[i] != '\0')
	{
		if(file[len] == ext[i]) 
		{
			len++;
			i++;
		}
		else
			break;
	}
	if(!(file[len] == '\0' && ext[i] =='\0'))
		error_message("File extension must be `.ber`");
}

void	scene_init(t_game *game, char *mapfile)
{
	ext_checker(mapfile, EXT);
	scene_malloc(game, mapfile);
	printf("col: %d, row: %d", game->map.c, game->map.r);
	//scene_set(game, mapfile);

	//game.map = set_map(map);
	//rectangle
	//border walls
	//amount of players. c , e
}
