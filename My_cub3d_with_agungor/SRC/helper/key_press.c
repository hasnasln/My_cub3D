/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:56:47 by agungor           #+#    #+#             */
/*   Updated: 2024/11/20 22:05:13 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"
#include "../cub3d.h"
#include <math.h>

void	rotate_x(t_cub3d *cub3d, float angle)
{
	float	temp;

	temp = cub3d->player->dir_x;
	cub3d->player->dir_x = cub3d->player->dir_x * cos(angle)
		- cub3d->player->dir_y * sin(angle);
	cub3d->player->dir_y = temp * sin(angle) + cub3d->player->dir_y
		* cos(angle);
	temp = cub3d->player->plane_x;
	cub3d->player->plane_x = cub3d->player->plane_x * cos(angle)
		- cub3d->player->plane_y * sin(angle);
	cub3d->player->plane_y = temp * sin(angle) + cub3d->player->plane_y
		* cos(angle);
}

void	move_x_and_y(t_cub3d *cub3d, int sing, int flag)
{
	if (flag == 1)
	{
		if (cub3d->map->map2[(int)(cub3d->player->x + (cub3d->player->dir_x
					* 0.03) * sing)][(int)(cub3d->player->y)] == '0')
			cub3d->player->x += cub3d->player->dir_x * 0.03 * sing;
		if (cub3d->map->map2[(int)(cub3d->player->x)][(int)(cub3d->player->y
				+ (cub3d->player->dir_y * 0.03) * sing)] == '0')
			cub3d->player->y += cub3d->player->dir_y * 0.03 * sing;
	}
	else
	{
		if (cub3d->map->map2[(int)(cub3d->player->x + (cub3d->player->plane_x
					* 0.03) * sing)][(int)(cub3d->player->y)] == '0')
			cub3d->player->x += cub3d->player->plane_x * 0.03 * sing;
		if (cub3d->map->map2[(int)(cub3d->player->x)][(int)(cub3d->player->y
				+ (cub3d->player->plane_y * 0.03) * sing)] == '0')
			cub3d->player->y += cub3d->player->plane_y * 0.03 * sing;
	}
}

int	key_press(int keycode)
{
	t_cub3d	*cub3d;

	cub3d = *get_cub3d();
	if (keycode == ESC)
		program_exit(END);
	else if (keycode == W)
		move_x_and_y(cub3d, 1, 1);
	else if (keycode == S)
		move_x_and_y(cub3d, -1, 1);
	else if (keycode == A)
		move_x_and_y(cub3d, -1, 0);
	else if (keycode == D)
		move_x_and_y(cub3d, 1, 0);
	else if (keycode == LEFT_ARROW)
		rotate_x(cub3d, -0.05001);
	else if (keycode == RIGHT_ARROW)
		rotate_x(cub3d, 0.05001);
	ray_casting(cub3d);
	mlx_put_image_to_window((cub3d)->mlx->mlx, (cub3d)->mlx->mlx_w,
		(cub3d)->mlx->img_data->img, 0, 0);
	return (0);
}

int	click_exit(void)
{
	program_exit(END);
	return (0);
}
