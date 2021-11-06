/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 06:10:35 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/06 01:23:13 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_message(char *m)
{
	printf("%sError detail: %s%s\n", RED, m, NRM);
	exit(1);
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

void	map_components(t_game	*game)
{
	int	i;
	
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