/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:04:34 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/06 01:07:51 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_superbuff(char *s)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	line = malloc(sizeof(char) * ((ft_strlen(s) - i) + 1));
	if (!line)
		return (0);
	i++;
	while (s[i])
		line[j++] = s[i++];
	line[j] = '\0';
	free(s);
	return (line);
}

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*superbuff;
	int			ret;

	ret = 1;
	if (fd < 0 || !line)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!is_newline(superbuff) && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (-1);
		}
		buff[ret] = '\0';
		superbuff = ft_strjoin(superbuff, buff);
	}
	free(buff);
	*line = get_line(superbuff);
	superbuff = get_superbuff(superbuff);
	if (ret == 0)
		return (0);
	return (1);
}
