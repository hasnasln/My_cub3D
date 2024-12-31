/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:02:50 by agungor           #+#    #+#             */
/*   Updated: 2024/11/20 22:02:55 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	paint_wall(t_cub3d *cub3d, int x, t_ray *ray)
{
	int				i;
	int				text_y;
	int				pixel;
	unsigned int	color;

	i = ray->draw_start - 1;
	cub3d->mlx->img_data->y_start = ray->draw_start;
	cub3d->mlx->img_data->y_end = ray->draw_end;
	while (++i < ray->draw_end)
	{
		text_y = (int)ray->tex_pos;
		ray->tex_pos += ray->step;
		color = get_pixel_colour(ray->img, ray->tex_x, text_y);
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		pixel = (x * (cub3d->mlx->img_data->bits_per_pixel / 8) + i
				* cub3d->mlx->img_data->size_line);
		*(unsigned int *)(cub3d->mlx->img_data->data + pixel) = color;
	}
}

void	draw(t_cub3d *cub3d, int x, t_ray *ray)
{
	cub3d->mlx->img_data->x = x;
	cub3d->mlx->img_data->y_start = 0;
	cub3d->mlx->img_data->y_end = ray->draw_start;
	cub3d->mlx->img_data->color = cub3d->map->ceiling_color;
	my_mlx_vertical_line_put(cub3d->mlx->img_data);
	paint_wall(cub3d, x, ray);
	cub3d->mlx->img_data->y_start = ray->draw_end;
	cub3d->mlx->img_data->y_end = SCREEN_HEIGHT;
	cub3d->mlx->img_data->color = cub3d->map->floor_color;
	my_mlx_vertical_line_put(cub3d->mlx->img_data);
}
