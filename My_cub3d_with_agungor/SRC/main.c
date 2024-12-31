/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:50:11 by agungor           #+#    #+#             */
/*   Updated: 2024/11/20 21:50:12 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../safe_allocation/s_malloc.h"
#include "./cub3d.h"

void	mlx_init_center(t_cub3d *cub3d)
{
	cub3d->mlx = (t_mlx *)s_malloc(sizeof(t_mlx));
	cub3d->mlx->mlx = mlx_init();
	if (!cub3d->mlx->mlx)
		program_exit(_MLX_INIT_ERROR);
	cub3d->mlx->mlx_w = mlx_new_window(cub3d->mlx->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Hasan-Arif");
	if (!cub3d->mlx->mlx_w)
		program_exit(_MLX_WINDOW_ERROR);
	cub3d->mlx->img_data = (t_img_data *)s_malloc(sizeof(t_img_data));
	cub3d->mlx->img_data->img = mlx_new_image(cub3d->mlx->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	if (!cub3d->mlx->img_data->img)
		program_exit(_MLX_MAIN_IMG_ERROR);
	cub3d->mlx->img_data->data = mlx_get_data_addr(cub3d->mlx->img_data->img,
			&cub3d->mlx->img_data->bits_per_pixel,
			&cub3d->mlx->img_data->size_line, &cub3d->mlx->img_data->endian);
	if (!cub3d->mlx->img_data->data)
		program_exit(_MLX_ADDR_ERROR);
}

int	main(int argc, char **argv)
{
	t_cub3d	**cub3d;

	cub3d = NULL;
	allocate_cub3d(&cub3d);
	arg_check(argc, argv);
	map_center(*cub3d);
	mlx_init_center(*cub3d);
	xpm_to_imgae(*cub3d);
	ray_casting(*cub3d);
	mlx_put_image_to_window((*cub3d)->mlx->mlx, (*cub3d)->mlx->mlx_w,
		(*cub3d)->mlx->img_data->img, 0, 0);
	mlx_hook((*cub3d)->mlx->mlx_w, 2, 1L << 0, key_press, NULL);
	mlx_hook((*cub3d)->mlx->mlx_w, 17, 1L << 0, click_exit, NULL);
	mlx_loop((*cub3d)->mlx->mlx);
}
