/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:00:14 by agungor           #+#    #+#             */
/*   Updated: 2024/11/20 21:51:48 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../safe_allocation/s_malloc.h"
#include "../cub3d.h"

static void	game_map_correct(char *str);
static void	revize_game_map(t_cub3d *cub3d);
static char	*create_space_str(int width);
static void	check_enclosed_boundary(t_cub3d *cub3, int i, int j);

void	check_map(t_cub3d *cub3d)
{
	game_map_correct(cub3d->map->str);
	cub3d->map->map = ft_split(cub3d->map->str, '\n');
	revize_game_map(cub3d);
	clone_map(cub3d);
	check_enclosed_boundary(cub3d, 0, 0);
}

static void	check_enclosed_boundary(t_cub3d *cub3d, int i, int j)
{
	if (i < 0 || i >= cub3d->map->height + 2 || j < 0 || j >= cub3d->map->width
		+ 2 || cub3d->map->map2[i][j] == '1')
		return ;
	if (cub3d->map->map2[i][j] == '0' || cub3d->map->map2[i][j] == 'N'
		|| cub3d->map->map2[i][j] == 'S' || cub3d->map->map2[i][j] == 'E'
		|| cub3d->map->map2[i][j] == 'W')
		program_exit(_ENCIRCLING_WALLS_ERROR);
	cub3d->map->map2[i][j] = '1';
	check_enclosed_boundary(cub3d, i - 1, j);
	check_enclosed_boundary(cub3d, i, j - 1);
	check_enclosed_boundary(cub3d, i + 1, j);
	check_enclosed_boundary(cub3d, i, j + 1);
}

static void	game_map_correct(char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] && str[i] != '\0')
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
			j++;
		else if (str[i] == '1' || str[i] == '0' || str[i] == ' ')
			k++;
		else if (str[i] == '\n')
			i++;
		else
			program_exit(_INVALIED_ELEMENT);
		i++;
	}
	if (j != 1 || k < 1)
	{
		program_exit(_INVALIED_ELEMENT);
	}
}

static char	*create_space_str(int width)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s_malloc(sizeof(char) * (width + 1));
	while (i < width)
	{
		str[i] = '2';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	revize_game_map(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	while (cub3d->map->map[++i])
	{
		if (cub3d->map->width < (int)ft_strlen(cub3d->map->map[i]))
			cub3d->map->width = (int)ft_strlen(cub3d->map->map[i]);
	}
	cub3d->map->height = i;
	i = -1;
	while (cub3d->map->map[++i])
	{
		if ((int)ft_strlen(cub3d->map->map[i]) < cub3d->map->width)
			cub3d->map->map[i] = ft_strjoin(cub3d->map->map[i],
					create_space_str(cub3d->map->width
						- ft_strlen(cub3d->map->map[i])));
	}
}
