/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:52:24 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/20 15:49:35 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, int len)
{
	size_t	size;
	char	*result;
	char	*s;
	int		i;

	size = len;
	i = 0;
	if (s2)
		while (s2[i])
			i++;
	size += i;
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	s = result;
	i = 0;
	while (i < len)
		*s++ = s1[i++];
	if (s2)
		while (*s2)
			*s++ = *s2++;
	*s = 0;
	return (result);
}

int		get_next_line(int fd, char **line)
{
	static char		buffer[BUFFER_SIZE];
	int				chr_read;
	char			*tmp;

	*line = ft_strjoin(buffer, NULL, 0);
	chr_read = read(fd, buffer, BUFFER_SIZE);
	tmp = ft_strjoin(buffer, *line, chr_read);
	free(*line);
	*line = tmp;

	return (chr_read > 0 ? 1 : chr_read);
}
