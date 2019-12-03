/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:52:24 by gboucett          #+#    #+#             */
/*   Updated: 2019/12/02 20:11:48 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static t_buffer		*buffer;

	(void)fd;
	(void)line;
	ft_init_buffer(&buffer);
	printf("pos = %d\n", buffer->pos);
	buffer->pos += 5;
	return (0);
}
