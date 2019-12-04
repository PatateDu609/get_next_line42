/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:52:24 by gboucett          #+#    #+#             */
/*   Updated: 2019/12/04 15:43:44 by gboucett         ###   ########.fr       */
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

int				get_next_line(int fd, char **line)
{
	static char		buffer[BUFFER_SIZE + 1];
	int				chr_read;
	int				pos;

	*line = "";
	while ((chr_read = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[chr_read] = 0;
		*line = ft_strjoin(*line, buffer);
		if ((pos = ft_new_line(buffer)) != -1)
		{
			ft_memmove(buffer, buffer + pos, );
			break;
		}
	}
	return (0);
}
