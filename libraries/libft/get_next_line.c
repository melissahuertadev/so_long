/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:40:44 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/05 05:11:09 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_read_frkg_line(char **sb, int fd, char **l, int ret)
{
	char	*t;
	int		num;

	num = 0;
	while (sb[0][num] == '\n' && sb[0][num] == '\0')
		num++;
	if (sb[0][num] == '\n')
	{
		*l = ft_strsub(sb[0], 0, num);
		t = ft_strdup(sb[0] + num + 1);
		ft_strdel(&sb[0]);
		sb[0] = t;
		if (sb[0][0] == '\0')
			ft_strdel(&sb[0]);
	}
	else if (sb[0][num] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, l));
		*l = ft_strdup(sb[0]);
		ft_strdel(&sb[0]);
	}
	return (1);
}

int	get_next_line(const	int fd, char **line)
{
	char		buff[BUFF_SIZE];
	int		ret;
	static char	*superbuff[255];
	char		*tmpstr;

	ret = read(fd, buff, BUFF_SIZE);
	while (ret > 0 && fd >= 0)
	{
		buff[ret] = '\0';
		if (superbuff[0] == NULL)
			superbuff[0] = ft_strnew(1);
		tmpstr = ft_strjoin(superbuff[0], buff);
		ft_strdel(&superbuff[0]);
		superbuff[0] = tmpstr;
		if (ft_strchr(superbuff[0], '\n'))
			break ;
	}
	if (fd < 0 || line == NULL || ret < 0)
		return (-1);
	else if (ret == 0 && (superbuff[0] == NULL || superbuff[0][0] == '\0'))
		return (0);
	return (ft_read_frkg_line(superbuff, fd, line, ret));
}
