/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:08:16 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/06 01:01:28 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t l)
{
	char	*dst;
	char	*src;

	dst = (char *)d;
	src = (char *)s;
	if (d == s)
		return (d);
	if (src < dst)
	{
		while (l--)
			*(dst + l) = *(src + l);
		return (d);
	}
	while (l--)
		*dst++ = *src++;
	return (d);
}
