/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:23:59 by haslan            #+#    #+#             */
/*   Updated: 2023/11/27 13:24:00 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

size_t	ft_have_newline(char *str);

void	*ft_free(void *src);

char	*ft_before_nevline(char *line);

char	*ft_after_newline(char *line);

#endif