/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:04:34 by mhuerta           #+#    #+#             */
/*   Updated: 2021/11/05 08:53:04 by melissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_all(char **sb)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!sb)
		return (NULL);
	while ((*sb)[i] != '\0' && (*sb)[i] != '\n')
		i++;
	if ((*sb)[i] == '\0')
	{
		free(*sb);
		return (NULL);
	}
	tmp = ft_strsub(*sb, i + 1, ft_strlen(*sb) - i);
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	free(*sb);
	return (tmp);
}

static int	is_line_end(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++ ;
	if (s[i] == '\n')
		return (1);
	return (0);
}

static	char	*get_each(char **sb)
{
	char	*l;
	int		i;

	i = 0;
	if (!sb)
		return (NULL);
	while ((*sb)[i] != '\0' && (*sb)[i] != '\n')
		i++;
	l = ft_strsub(*sb, 0, i + is_line_end(*sb));
	if (!l)
	{
		free(l);
		return (NULL);
	}
	return (l);
}

static int	read_all_lines(int fd, char **b, char **sb, char **line)
{
	int		bytes;
	char	*tmp;

	bytes = 1;
	while (is_line_end(*sb) != 1 && bytes > 0)
	{
		bytes = read(fd, *b, BUFFER_SIZE);
		(*b)[bytes] = '\0';
		tmp = *sb;
		*sb = ft_strjoin(tmp, *b);
		free(tmp);
	}
	free(*b);
	*line = get_each(sb);
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
	*sb = get_all(sb);
	return (bytes);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*superbuff;
	char		*line;
	int			bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, buff, 0) < 0)
	{
		free(buff);
		return (NULL);
	}
	if (!superbuff)
		superbuff = ft_strdup("");
	bytes = read_all_lines(fd, &buff, &superbuff, &line);
	if (bytes == 0 && !line)
		return (NULL);
	return (line);
}
