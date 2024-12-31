/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub3d_allocation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:21:04 by haslan            #+#    #+#             */
/*   Updated: 2024/11/20 21:51:12 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../safe_allocation/s_malloc.h"
#include "../cub3d.h"

t_cub3d	**get_cub3d(void)
{
	static t_cub3d	*cub3d = NULL;

	return (&cub3d);
}

void	allocate_cub3d(t_cub3d ***cub3d)
{
	*cub3d = get_cub3d();
	(**cub3d) = (t_cub3d *)s_malloc(sizeof(t_cub3d));
	(**cub3d)->map = (t_map *)s_malloc(sizeof(t_map));
	(**cub3d)->player = (t_player *)s_malloc(sizeof(t_player));
	(**cub3d)->fd = -1;
}

t_ray	*init_ray(t_cub3d *cub3d)
{
	t_ray	*ray;

	(void)cub3d;
	ray = s_malloc(sizeof(t_ray));
	return (ray);
}
