/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:10:02 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/05 03:17:34 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ext_checker(char *map, char *ext)
{
	int	len;
	int	i;

	len = ft_strlen((char *)map) - EXT_LEN;
	i = 0;

	if(len <= 0)
		error_message("Please, check the filename/extension.");
	while(map[len] != '\0' && ext[i] != '\0')
	{
		if(map[len] == ext[i]) 
		{
			len++;
			i++;
		}
		else
			break;
	}
	if(!(map[len] == '\0' && ext[i] =='\0'))
		error_message("File extension must be `.ber`");
}

void	map_init(t_game *game, char *map)
{
	ext_checker(map, EXT);
}
