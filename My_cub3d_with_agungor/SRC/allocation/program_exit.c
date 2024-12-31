/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:50:41 by agungor           #+#    #+#             */
/*   Updated: 2024/11/20 21:50:42 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../errors/error_message.h"
#include "../../minilibx-linux/mlx.h"
#include "../../safe_allocation/s_malloc.h"
#include "../cub3d.h"

static void	destroy_center(void)
{
	t_cub3d	*cub3d;

	cub3d = *(get_cub3d());
	if (cub3d->map->img_ea->img)
		mlx_destroy_image(cub3d->mlx->mlx, cub3d->map->img_ea->img);
	if (cub3d->map->img_so->img)
		mlx_destroy_image(cub3d->mlx->mlx, cub3d->map->img_so->img);
	if (cub3d->map->img_we->img)
		mlx_destroy_image(cub3d->mlx->mlx, cub3d->map->img_we->img);
	if (cub3d->map->img_no->img)
		mlx_destroy_image(cub3d->mlx->mlx, cub3d->map->img_no->img);
	if (cub3d->mlx->img_data->img)
		mlx_destroy_image(cub3d->mlx->mlx, cub3d->mlx->img_data->img);
	if (cub3d->mlx->mlx_w)
		mlx_destroy_window(cub3d->mlx->mlx, cub3d->mlx->mlx_w);
	if (cub3d->mlx->mlx)
		mlx_destroy_display(cub3d->mlx->mlx);
	if (cub3d->mlx->mlx)
		free(cub3d->mlx->mlx);
}

void	program_exit(int error_code)
{
	if ((error_code < -14 && error_code > -23) || error_code == END)
		destroy_center();
	error_center(error_code);
	safe_free_data();
	exit(error_code);
}
