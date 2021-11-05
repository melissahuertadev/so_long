/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:06:36 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/05 07:42:31 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((s1) + ft_strlen(s2) + 1);
	ns = (char *)malloc(sizeof(char) * len);
	if (!ns)
		return (NULL);
	ft_strcpy(ns, (char *)s1);
	ft_strcat(ns, s2);
	return (ns);
}
