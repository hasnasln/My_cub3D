/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:02:32 by agungor           #+#    #+#             */
/*   Updated: 2024/11/20 22:02:34 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"
#include "../../safe_allocation/s_malloc.h"
#include "../cub3d.h"

void	xmp_to_image2(t_cub3d *cub3d, t_img *img)
{
	img = (t_img *)s_malloc(sizeof(t_img));
	img->img = mlx_xpm_file_to_image(cub3d->mlx->mlx, cub3d->map->we[1],
			&img->width, &img->height);
	if (!img->img)
		program_exit(_MLX_WE_ERROR);
	img->data = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	if (!img->data)
		program_exit(_MLX_ADDR_ERROR);
	cub3d->map->img_we = img;
	img = (t_img *)s_malloc(sizeof(t_img));
	img->img = mlx_xpm_file_to_image(cub3d->mlx->mlx, cub3d->map->ea[1],
			&img->width, &img->height);
	if (!img->img)
		program_exit(_MLX_EA_ERROR);
	img->data = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	if (!img->data)
		program_exit(_MLX_ADDR_ERROR);
	cub3d->map->img_ea = img;
}

void	xpm_to_imgae(t_cub3d *cub3d)
{
	t_img	*img;

	img = (t_img *)s_malloc(sizeof(t_img));
	img->img = mlx_xpm_file_to_image(cub3d->mlx->mlx, cub3d->map->no[1],
			&img->width, &img->height);
	if (!img->img)
		program_exit(_MLX_NO_ERROR);
	img->data = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	if (!img->data)
		program_exit(_MLX_ADDR_ERROR);
	cub3d->map->img_no = img;
	img = (t_img *)s_malloc(sizeof(t_img));
	img->img = mlx_xpm_file_to_image(cub3d->mlx->mlx, cub3d->map->so[1],
			&img->width, &img->height);
	if (!img->img)
		program_exit(_MLX_SO_ERROR);
	img->data = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	if (!img->data)
		program_exit(_MLX_ADDR_ERROR);
	cub3d->map->img_so = img;
	xmp_to_image2(cub3d, img);
}
