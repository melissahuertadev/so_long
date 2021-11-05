/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:04:34 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/05 08:49:18 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(sizeof(char) * size);
	if (!s)
		return (NULL);
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
