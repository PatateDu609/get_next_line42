/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:52:24 by gboucett          #+#    #+#             */
/*   Updated: 2019/12/05 17:46:35 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_new_line(char *buffer)
{
	int		pos;

	pos = 0;
	while (*buffer)
	{
		pos++;
		if (*buffer++ == '\n')
			return (pos);
	}
	return (-1);
}

static char		*ft_init_line(char *buffer)
{
	if (!*buffer)
		return (ft_strdup(""));
	return (ft_strdup(buffer));
}

static void		ft_clear(char *buffer)
{
	int		i;

	i = 0;
	while (i < BUFFER_SIZE)
		buffer[i++] = 0;
}

int				get_next_line(int fd, char **line)
{
	static char		buffer[1000][BUFFER_SIZE + 1];
	int				chr_read;
	int				pos;
	char			*tmp;

	buffer[fd][0] = (buffer[fd][0] != 0) ? buffer[fd][0] : 0;
	if (!(*line = ft_init_line(buffer[fd])))
		return (-1);
	while ((chr_read = read(fd, buffer[fd], BUFFER_SIZE)))
	{
		buffer[fd][chr_read] = 0;
		tmp = ft_strjoin(*line, buffer[fd]);
		free(*line);
		if (tmp == NULL)
			return (-1);
		*line = tmp;
		if ((pos = ft_new_line(buffer[fd])) != -1)
		{
			pos += (!buffer[fd][pos] || buffer[fd][pos] != '\n') ? 0 : 1;
			ft_memmove(buffer[fd], buffer[fd] + pos, BUFFER_SIZE - pos);
			break;
		}
	}
	if (!chr_read)
		ft_clear(buffer[fd]);
	return (chr_read ? 1 : 0);
}
