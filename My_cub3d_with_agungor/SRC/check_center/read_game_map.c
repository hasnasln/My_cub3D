/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_game_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:03:55 by agungor           #+#    #+#             */
/*   Updated: 2024/11/20 21:56:20 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line/get_next_line.h"
#include "../../libft/libft.h"
#include "../../safe_allocation/s_malloc.h"
#include "../cub3d.h"

void	read_game_map(t_cub3d *cub3d)
{
	char	*line;
	char	*map_str;

	map_str = ft_strdup("");
	while (42)
	{
		line = get_next_line(cub3d->fd);
		if (line == NULL && !(map_str[ft_strlen(map_str) - 1] == '\n'
				|| map_str[ft_strlen(map_str) - 1] == '1'))
			program_exit(_INVALIED_ELEMENT);
		if (line == NULL)
			break ;
		if (map_str[0] == '\0' && line[0] == '\n' && line[1] == '\0')
			continue ;
		else if (line[0] == '\n' && line[1] == '\0')
			program_exit(_INVALIED_ELEMENT);
		map_str = ft_strjoin(map_str, line);
	}
	cub3d->map->str = map_str;
}

static void	clone_map2(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = -1;
	while (cub3d->map->map2[++i])
	{
		j = -1;
		while (++j < cub3d->map->width + 2)
		{
			if (i == 0 || j == 0 || i == cub3d->map->height + 1
				|| j == cub3d->map->width + 1)
				cub3d->map->map2[i][j] = '2';
			else
			{
				if (cub3d->map->map[i - 1][j - 1] == ' ')
					cub3d->map->map2[i][j] = '2';
				else
					cub3d->map->map2[i][j] = cub3d->map->map[i - 1][j - 1];
			}
		}
	}
}

void	clone_map(t_cub3d *cub3d)
{
	int	i;

	cub3d->map->map2 = (char **)s_malloc(sizeof(char *) * (cub3d->map->height
				+ 3));
	cub3d->map->map2[cub3d->map->height + 2] = NULL;
	i = -1;
	while (++i < cub3d->map->height + 2)
	{
		cub3d->map->map2[i] = s_malloc(sizeof(char) * (cub3d->map->width + 3));
		cub3d->map->map2[i][cub3d->map->width + 2] = '\0';
	}
	clone_map2(cub3d);
}
