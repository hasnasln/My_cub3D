/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:31:56 by haslan            #+#    #+#             */
/*   Updated: 2024/11/20 21:54:43 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../errors/error_message.h"
#include "../../get_next_line/get_next_line.h"
#include "../../libft/libft.h"
#include "../../safe_allocation/s_malloc.h"
#include "../cub3d.h"

void	read_map_features(t_cub3d *cub3d);
void	map_features_correct(t_cub3d *cub3d);
void	check_features(t_cub3d *cub3d, char *line);
void	revize_features(t_cub3d *cub3d);

void	map_center(t_cub3d *cub3d)
{
	read_map_features(cub3d);
	revize_features(cub3d);
	map_features_correct(cub3d);
	read_game_map(cub3d);
	check_map(cub3d);
	set_player(cub3d);
	set_player_direction(cub3d);
}

void	read_map_features(t_cub3d *cub3d)
{
	char	*line;

	line = NULL;
	while (42)
	{
		line = get_next_line(cub3d->fd);
		if (line)
		{
			if (!ft_strrchr(line, '\n'))
			{
				check_features(cub3d, line);
				which_directions_search(line, TAIL_TO_HEAD);
				break ;
			}
		}
		if (line[0] == '\n' && line[1] == '\0')
			continue ;
		check_features(cub3d, line);
		which_directions_search(line, TAIL_TO_HEAD);
		if (cub3d->map->so && cub3d->map->no && cub3d->map->we && cub3d->map->ea
			&& cub3d->map->f && cub3d->map->c)
			break ;
	}
}

void	check_features(t_cub3d *cub3d, char *line)
{
	if (!cub3d->map->so && line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		cub3d->map->so = ft_split(line, ' ');
	else if (!cub3d->map->no && line[0] == 'N' && line[1] == 'O'
		&& line[2] == ' ')
		cub3d->map->no = ft_split(line, ' ');
	else if (!cub3d->map->we && line[0] == 'W' && line[1] == 'E'
		&& line[2] == ' ')
		cub3d->map->we = ft_split(line, ' ');
	else if (!cub3d->map->ea && line[0] == 'E' && line[1] == 'A'
		&& line[2] == ' ')
		cub3d->map->ea = ft_split(line, ' ');
	else if (!cub3d->map->f && line[0] == 'F' && line[1] == ' '
		&& line[1] == ' ')
		cub3d->map->f = ft_split(line, ' ');
	else if (!cub3d->map->c && line[0] == 'C' && line[1] == ' '
		&& line[1] == ' ')
		cub3d->map->c = ft_split(line, ' ');
	else
		program_exit(_INVALIED_ELEMENT);
}

void	map_features_correct(t_cub3d *cub3d)
{
	char	*extecion_str;

	if (cub3d->map->so[2] || cub3d->map->no[2] || cub3d->map->we[2]
		|| cub3d->map->ea[2] || cub3d->map->f[2] || cub3d->map->c[2])
		program_exit(-1);
	extecion_str = ft_strrchr(cub3d->map->so[1], '.');
	if (!extecion_str || ft_strlen(extecion_str) != 4
		|| ft_strncmp(extecion_str, ".xpm", 4))
		program_exit(_XPM_SO_ERROR);
	extecion_str = ft_strrchr(cub3d->map->no[1], '.');
	if (!extecion_str || ft_strlen(extecion_str) != 4
		|| ft_strncmp(extecion_str, ".xpm", 4))
		program_exit(_XPM_NO_ERROR);
	extecion_str = ft_strrchr(cub3d->map->we[1], '.');
	if (!extecion_str || ft_strlen(extecion_str) != 4
		|| ft_strncmp(extecion_str, ".xpm", 4))
		program_exit(_XPM_WE_ERROR);
	extecion_str = ft_strrchr(cub3d->map->ea[1], '.');
	if (!extecion_str || ft_strlen(extecion_str) != 4
		|| ft_strncmp(extecion_str, ".xpm", 4))
		program_exit(_XPM_EA_ERROR);
	if (open(cub3d->map->so[1], O_RDONLY) == -1 || open(cub3d->map->no[1],
			O_RDONLY) == -1 || open(cub3d->map->we[1], O_RDONLY) == -1
		|| open(cub3d->map->ea[1], O_RDONLY) == -1)
		program_exit(_NOT_OPEN);
}

void	revize_features(t_cub3d *cub3d)
{
	char	**tmp;

	cub3d->map->so[1][ft_strlen(cub3d->map->so[1]) - 1] = '\0';
	cub3d->map->no[1][ft_strlen(cub3d->map->no[1]) - 1] = '\0';
	cub3d->map->we[1][ft_strlen(cub3d->map->we[1]) - 1] = '\0';
	cub3d->map->ea[1][ft_strlen(cub3d->map->ea[1]) - 1] = '\0';
	cub3d->map->f[1][ft_strlen(cub3d->map->f[1]) - 1] = '\0';
	cub3d->map->c[1][ft_strlen(cub3d->map->c[1]) - 1] = '\0';
	if (!check_rgb(cub3d->map->f[1]) || !check_rgb(cub3d->map->c[1]))
		program_exit(_INVALIED_ELEMENT);
	tmp = ft_split(cub3d->map->f[1], ',');
	if (!check_rgb_value(tmp))
		program_exit(_INVALIED_ELEMENT);
	cub3d->map->floor_color = (ft_atoi(tmp[0]) << 16) \
	| (ft_atoi(tmp[1]) << 8) | ft_atoi(tmp[2]);
	which_directions_search(tmp, TAIL_TO_HEAD);
	tmp = ft_split(cub3d->map->c[1], ',');
	if (!check_rgb_value(tmp))
		program_exit(_INVALIED_ELEMENT);
	cub3d->map->ceiling_color = (ft_atoi(tmp[0]) << 16) \
	| (ft_atoi(tmp[1]) << 8) | ft_atoi(tmp[2]);
	which_directions_search(tmp, TAIL_TO_HEAD);
}
