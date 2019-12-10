/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:52:31 by gboucett          #+#    #+#             */
/*   Updated: 2019/12/10 12:25:20 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*ft_strdup(const char *s1);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strchr(char *buffer, char chr);
int		get_next_line(int fd, char **line);

#endif
