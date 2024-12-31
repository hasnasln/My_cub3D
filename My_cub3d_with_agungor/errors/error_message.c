/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:27:23 by agungor           #+#    #+#             */
/*   Updated: 2024/09/03 17:19:54 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_message.h"
#include "../libft/libft.h"

static t_colour	rgb_change(int error_effect)
{
	t_colour	new_rgb;

	new_rgb.red = 100;
	new_rgb.green = 100;
	new_rgb.blue = 100;
	new_rgb.red += (error_effect * 2);
	new_rgb.green += (error_effect * 3);
	new_rgb.blue += (error_effect * 5);
	return (new_rgb);
}

static void	string_check1(int error_num, t_colour rgb)
{
	if (error_num == -1)
		string_check(ft_strdup(CUB_ERROR), 53, 30000, rgb);
	else if (error_num == -2)
		string_check(ft_strdup(NOT_OPEN), 68, 30000, rgb);
	else if (error_num == -3)
		string_check(ft_strdup(ARGUMAN_ERROR), 68, 30000, rgb);
	else if (error_num == -4)
		string_check(ft_strdup(XPM_SO_ERROR), 93, 30000, rgb);
	else if (error_num == -5)
		string_check(ft_strdup(XPM_NO_ERROR), 92, 30000, rgb);
	else if (error_num == -6)
		string_check(ft_strdup(XPM_EA_ERROR), 91, 30000, rgb);
	else if (error_num == -7)
		string_check(ft_strdup(XPM_WE_ERROR), 87, 30000, rgb);
	else if (error_num == -10)
		string_check(ft_strdup(ENCIRCLING_WALLS_ERROR), 58, 30000, rgb);
	else if (error_num == -11)
		string_check(ft_strdup(MALLOC_ERROR), 79, 30000, rgb);
	else if (error_num == -12)
		string_check(ft_strdup(INVALIED_ELEMENT), 51, 30000, rgb);
}

static void	string_check2(int error_num, t_colour rgb)
{
	if (error_num == -15)
		string_check(ft_strdup(MLX_INIT_ERROR), 115, 30000, rgb);
	else if (error_num == -16)
		string_check(ft_strdup(MLX_WINDOW_ERROR), 96, 30000, rgb);
	if (error_num == -17)
		string_check(ft_strdup(MLX_SO_ERROR), 160, 30000, rgb);
	else if (error_num == -18)
		string_check(ft_strdup(MLX_NO_ERROR), 159, 30000, rgb);
	else if (error_num == -19)
		string_check(ft_strdup(MLX_WE_ERROR), 154, 30000, rgb);
	else if (error_num == -20)
		string_check(ft_strdup(MLX_EA_ERROR), 158, 30000, rgb);
	else if (error_num == -21)
		string_check(ft_strdup(MLX_ADDR_ERROR), 85, 30000, rgb);
	else if (error_num == -22)
		string_check(ft_strdup(MLX_MAIN_IMG_ERROR), 81, 30000, rgb);
}

int	error_center(int error_num)
{
	t_colour	rgb;

	rgb = rgb_change(error_num * -1);
	if (!error_num)
		;
	else
	{
		if (0 > error_num && error_num > -13)
			string_check1(error_num, rgb);
		else if (-12 > error_num && error_num > -26)
			string_check2(error_num, rgb);
	}
	return (error_num);
}
