/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:52:31 by gboucett          #+#    #+#             */
/*   Updated: 2019/12/02 20:11:24 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct			s_buffer
{
	char				buf[BUFFER_SIZE];
	int					pos;
	// int					fd;
	// struct s_buffer		*next;
}						t_buffer;

void	ft_init_buffer(t_buffer **buffer);
int		get_next_line(int fd, char **line);

#endif
