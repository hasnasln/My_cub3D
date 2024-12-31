/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:54:54 by agungor           #+#    #+#             */
/*   Updated: 2024/11/20 21:55:40 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	check_rgb(char *tmp)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (tmp[++i])
	{
		if (!ft_isdigit(tmp[i]))
		{
			if (tmp[i] == ',')
				count++;
			else
				return (0);
		}
	}
	if (count == 2)
		return (1);
	return (0);
}

int	check_rgb_value(char **tmp)
{
	if (tmp[0] && tmp[0][0] != '\0' && !(atoi(tmp[0]) <= 255
			&& atoi(tmp[0]) >= 0))
		return (0);
	if (tmp[1] && tmp[1][0] != '\0' && !(atoi(tmp[1]) <= 255
			&& atoi(tmp[1]) >= 0))
		return (0);
	if (tmp[2] && tmp[2][0] != '\0' && !(atoi(tmp[2]) <= 255
			&& atoi(tmp[2]) >= 0))
		return (0);
	return (1);
}
