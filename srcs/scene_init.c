/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:10:02 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/06 01:15:40 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_valid(t_game	*game)
{
	int	i;

	i = 0;
	while (game->mapline[i] != '\0')
	{
		if (game->mapline[i] != 'P' && game->mapline[i] != 'C'
			&& game->mapline != 'E' && game->mapline[i] != '0'
			&& game->mapline != '1')
			error_message("Not valid map, make sure it has onlt PEC10");
	}
}

void	map_components(t_game	*game)
{
	game->pct = 0;
	game->cct = 0;
	game->ect = 0;
	i = 0;
	while (game->mapline[i] != '\0')
	{
		if (game->mapline[i] == 'P')
			game->pct++;
		else if (game->mapline[i] == 'C')
			game->cct++;
		else if (game->mapline[i] == 'E')
			game->ect++;
	}
	if (game->pct != 1 || game->cct == 0 || game->ect == 0)
		error_messager("Wrong components amount");
	if (game->col == game->row - 1)
		error_message("Map is not a square");
}

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
	game->lread = 0;
	game->ret = get_next_line(game->fd, &line);
	horizontal_walls(line);
	game->col = ft_strlen(line);
	vertical_walls(game, line);
	map_valid(game);
	map_components(game);
}

void	ext_checker(char *file, char *ext)
{
	int	len;
	int	i;

	len = ft_strlen((char *)file) - EXT_LEN;
	i = 0;

	if(len <= 0)
		error_message("Please, check the filename/extension.");
	while (file[len] != '\0' && ext[i] != '\0')
	{
		if (file[len] == ext[i]) 
		{
			len++;
			i++;
		}
		else
			break;
	}
	if (!(file[len] == '\0' && ext[i] == '\0'))
		error_message("File extension must be `.ber`");
}

void	scene_init(t_game *game, char *mapfile)
{
	ext_checker(mapfile, EXT);
	game->mapline = malloc(sizeof(char) * BUF_LEN);
	*game->mapline = 0;
	scene_malloc(game, mapfile);
	free(game->mapline);
}
