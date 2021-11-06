/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:10:02 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/06 01:23:30 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	vertical_walls(t_game *game, char *line)
{
	int	len;

	while (game->ret > 0)
	{
		game->row++;
		len = ft_strlen(line) - 1;
		if (line[0] != '1' || line[len] != '1')
		{
			printf("%sWrong vertical wall :(%s\n", RED, NRM);
			free(game->mapline);
		}
		ft_strcat(game->mapline, line);
		free(line);
		line = 0;
		game->ret = get_next_line(game->fd, &line);
		if ((game->ret != 0) && (ft_strlen(line)
			!= (long unsigned int)game->col))
		{
			free(game->mapline);
			error_message("Check maps shape.");
		}
		if (game->ret == 0)
		{
			game->row++;
			horizontal_walls(line);
			ft_strcat(game->mapline, line);
			free(line);
			line = 0;
		}
	}
}

void	horizontal_walls(char *line)
{
	int	c;

	c = 0;
	while (line[c]) 
	{
		if (line[c] != '1')
		{
			printf("Wrong horizontal wall :(\n");
			free(line);
			exit(1);
		}
		c++;
	}

}

void	scene_malloc(t_game *game, char *mapfile)
{
	char	*line;

	game->fd = open(mapfile, O_RDONLY);
	if(game->fd == -1)
	{
		error_message("Error while opening the file");
		free(game->mapline);
	}
	line = 0;
	game->row = 0;
	game->ret = get_next_line(game->fd, &line);
	horizontal_walls(line);
	game->col = ft_strlen(line);
	vertical_walls(game, line);
	map_valid(game);
	map_components(game);
}

void	scene_init(t_game *game, char *mapfile)
{
	ext_checker(mapfile, EXT);
	game->mapline = malloc(sizeof(char) * BUF_LEN);
	*game->mapline = 0;
	scene_malloc(game, mapfile);
	free(game->mapline);
}
