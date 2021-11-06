/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:06:26 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/06 01:03:56 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ns;
	unsigned int	i;
	unsigned int	sl;

	ns = (char *)malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	i = 0;
	if (((sl - start) > len) && (start < sl))
		ns = malloc((len * sizeof(char) + 1));
	else if (start > sl)
		ns = malloc(sizeof(char));
	else
		ns = malloc(((sl - start) * sizeof(char) + 1));
	if (!ns)
		return (NULL);
	if ((start < sl))
	{
		while ((i < len) && s[start])
			ns[i++] = s[start++];
	}
	ns[i] = '\0';
	return (ns);
}
