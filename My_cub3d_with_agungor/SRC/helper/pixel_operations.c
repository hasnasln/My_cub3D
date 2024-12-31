/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:01:53 by agungor           #+#    #+#             */
/*   Updated: 2024/11/20 22:01:55 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	get_pixel_colour(t_img *img, int x, int y)
{
	unsigned int	color;

	color = *(unsigned int *)(img->data + (x * (img->bits_per_pixel / 8) + y
				* img->size_line));
	return (color);
}

void	my_mlx_vertical_line_put(t_img_data *img)
{
	int	pixel;
	int	i;

	pixel = img->x * (img->bits_per_pixel / 8) + img->y_start * img->size_line;
	i = img->y_start - 1;
	while (++i < img->y_end)
	{
		*(unsigned int *)(img->data + pixel) = img->color;
		pixel += img->size_line;
	}
}
