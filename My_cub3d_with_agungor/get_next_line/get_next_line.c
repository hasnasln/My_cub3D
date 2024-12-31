/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:10:43 by haslan            #+#    #+#             */
/*   Updated: 2024/09/04 20:28:24 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include "../safe_allocation/s_malloc.h"

static	char	*my_strjoin(char *first_part, char *last_part)
{
	char	*result;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!first_part)
	{
		first_part = (char *)s_malloc(1);
		first_part[0] = '\0';
	}
	result = (char *)s_malloc(ft_strlen(first_part) + ft_strlen(last_part) + 1);
	while (first_part[++i] != '\0')
		result[i] = first_part[i];
	while (last_part[++j] != '\0')
		result[i++] = last_part[j];
	result[i] = '\0';
	ft_free(first_part);
	return (result);
}

static	char	*read_line(int fd, char *ft_past)
{
	char	*read_buf;
	int		nobr;

	read_buf = (char *)s_malloc(BUFFER_SIZE + 1);
	read_buf[0] = '\0';
	while (!ft_have_newline(read_buf))
	{
		nobr = read(fd, read_buf, BUFFER_SIZE);
		if (nobr == -1 || nobr == 0)
			break ;
		read_buf[nobr] = '\0';
		ft_past = my_strjoin(ft_past, read_buf);
		if (!ft_past)
			break ;
	}
	ft_free(read_buf);
	if (nobr == -1)
		return (ft_free(ft_past));
	return (ft_past);
}

char	*get_next_line(int fd)
{
	char		*re_line;
	static char	*ft_past = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_have_newline (ft_past))
		ft_past = read_line (fd, ft_past);
	if (!ft_past)
		return (NULL);
	re_line = ft_before_nevline (ft_past);
	if (!re_line)
	{
		ft_free(ft_past);
		ft_past = NULL;
		return (NULL);
	}
	ft_past = ft_after_newline(ft_past);
	return (re_line);
}
