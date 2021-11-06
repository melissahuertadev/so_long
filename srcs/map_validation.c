/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:11:42 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/05 08:55:24 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
void	map_components(t_game *game, char *buf)
{
}

void	map_walls(t_game *game, char *buf)
{
}
*/

void	map_rectangle(t_game *game, char *buf)
{
	int	c;

	c = ft_strlen(buf);
	if (c != game->map.c)
		error_message("Not a valid rectangle.");
	else
		printf("its a rectangle map\n");
}
