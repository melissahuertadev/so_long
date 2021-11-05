/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 06:10:35 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/05 03:19:25 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game        game;
	if(ac != 2)
		error_message("Please, enter a map and only ONE map.");
	map_init(&game, av[1]);
	 
	return (0);
}
