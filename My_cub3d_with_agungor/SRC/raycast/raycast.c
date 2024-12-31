/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:03:23 by agungor           #+#    #+#             */
/*   Updated: 2024/11/20 22:03:51 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

void	set_delta_x_y(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1000000;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1000000;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	set_sidedis_x_y(t_ray *ray, t_cub3d *cub3d)
{
	ray->map_x = (int)cub3d->player->x;
	ray->map_y = (int)cub3d->player->y;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cub3d->player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - cub3d->player->x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub3d->player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - cub3d->player->y)
			* ray->delta_dist_y;
	}
}

void	calculate_wal_picture_pixel(t_ray *ray, t_cub3d *cub3d)
{
	ray->wall_x -= floor(ray->wall_x);
	if (ray->code == 0)
		ray->img = cub3d->map->img_ea;
	else if (ray->code == 1)
		ray->img = cub3d->map->img_we;
	else if (ray->code == 2)
		ray->img = cub3d->map->img_so;
	else if (ray->code == 3)
		ray->img = cub3d->map->img_no;
	ray->tex_x = (int)(ray->wall_x * (double)ray->img->width);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		ray->tex_x = ray->img->width - ray->tex_x - 1;
	else if (ray->side == 1 && ray->ray_dir_y > 0)
		ray->tex_x = ray->img->width - ray->tex_x - 1;
	ray->step = 1.0 * ray->img->height / ray->line_height;
	ray->tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2 + ray->line_height / 2)
		* ray->step;
}

void	calculate_wall_height(t_ray *ray, t_cub3d *cub3d)
{
	ray->line_height = (int)((SCREEN_HEIGHT / 2) / (ray->perp_wall_dist));
	ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT;
	if (ray->side == 0)
	{
		ray->wall_x = cub3d->player->y + ray->perp_wall_dist * ray->ray_dir_y;
	}
	else
	{
		ray->wall_x = cub3d->player->x + ray->perp_wall_dist * ray->ray_dir_x;
	}
}

void	ray_casting(t_cub3d *cub3d)
{
	t_ray	*ray;
	int		x;

	ray = init_ray(cub3d);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		ray->ray_dir_x = cub3d->player->dir_x + (cub3d->player->plane_x
				* ray->camera_x);
		ray->ray_dir_y = cub3d->player->dir_y + (cub3d->player->plane_y
				* ray->camera_x);
		set_delta_x_y(ray);
		set_sidedis_x_y(ray, cub3d);
		find_wall(ray, cub3d);
		calculate_wall_height(ray, cub3d);
		calculate_wal_picture_pixel(ray, cub3d);
		draw(cub3d, x, ray);
		x++;
	}
}
