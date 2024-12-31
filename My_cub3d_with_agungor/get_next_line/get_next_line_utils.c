/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:23:50 by haslan            #+#    #+#             */
/*   Updated: 2024/09/04 20:27:11 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../safe_allocation/s_malloc.h"

void	*ft_free(void *src)
{
	which_directions_search(src, TAIL_TO_HEAD);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_have_newline(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_before_nevline(char *line)
{
	char	*beforen;
	int		i;

	i = 0;
	if (!line[0])
		return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i = i + 2;
	else
	{
		i = i + 1;
	}
	beforen = (char *)s_malloc(sizeof(char) * i);
	beforen[--i] = '\0';
	while (--i >= 0)
		beforen[i] = line[i];
	return (beforen);
}

char	*ft_after_newline(char *line)
{
	char			*aftern;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (ft_free(line));
	aftern = (char *)s_malloc(((ft_strlen(line) - i) + 1));
	i++;
	while (line[i] != '\0')
		aftern[j++] = line[i++];
	aftern[j] = '\0';
	ft_free(line);
	return (aftern);
}
