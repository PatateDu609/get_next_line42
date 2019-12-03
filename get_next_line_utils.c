/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:52:29 by gboucett          #+#    #+#             */
/*   Updated: 2019/12/02 20:11:40 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_init_buffer(t_buffer **buffer)
{
	if (*buffer)
	{
		write(1, "bite\n", 5);
		return ;
	}
	*buffer = (t_buffer *)malloc(sizeof(t_buffer));
	(*buffer)->pos = 0;
	(*buffer)->buf[0] = 0;
}
