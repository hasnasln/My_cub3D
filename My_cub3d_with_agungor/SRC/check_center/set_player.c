/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:56:28 by agungor           #+#    #+#             */
/*   Updated: 2024/11/20 21:56:30 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = -1;
	while (cub3d->map->map2[++i])
	{
		j = -1;
		while (cub3d->map->map2[i][++j])
		{
			if (cub3d->map->map2[i][j] == 'N' || cub3d->map->map2[i][j] == 'S'
				|| cub3d->map->map2[i][j] == 'W'
				|| cub3d->map->map2[i][j] == 'E')
			{
				cub3d->player->x = i + 0.3;
				cub3d->player->y = j + 0.3;
				cub3d->player->direction = cub3d->map->map2[i][j];
				cub3d->map->map2[i][j] = '0';
				return ;
			}
		}
	}
}

void	set_player_direction(t_cub3d *cub3d)
{
	if (cub3d->player->direction == 'N')
	{
		cub3d->player->dir_y = -1;
		cub3d->player->plane_x = 0.66;
	}
	else if (cub3d->player->direction == 'S')
	{
		cub3d->player->dir_y = 1;
		cub3d->player->plane_x = -0.66;
	}
	else if (cub3d->player->direction == 'E')
	{
		cub3d->player->dir_x = 1;
		cub3d->player->plane_y = 0.66;
	}
	else if (cub3d->player->direction == 'W')
	{
		cub3d->player->dir_x = -1;
		cub3d->player->plane_y = -0.66;
	}
}
