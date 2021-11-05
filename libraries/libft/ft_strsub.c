/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:06:26 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/05 05:01:41 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	int		i;

	i = 0;
	ns = (char *)malloc(sizeof(char) * len);
	if (!ns)
		return (NULL);
	while (i < (int)len)
		ns[i++] = s[start++];
	return (ns);
}
