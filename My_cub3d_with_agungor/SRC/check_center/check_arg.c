/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:51:34 by agungor           #+#    #+#             */
/*   Updated: 2024/11/20 21:51:39 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../cub3d.h"
#include <fcntl.h>

int	check_path(char *path)
{
	int		fd;
	char	*extecion_str;

	extecion_str = ft_strrchr(path, '.');
	if (!extecion_str || ft_strlen(extecion_str) != 4
		|| ft_strncmp(extecion_str, ".cub", 4))
		program_exit(_CUB_ERROR);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		program_exit(_NOT_OPEN);
	return (fd);
}

void	arg_check(int argc, char **argv)
{
	if (argc != 2)
		program_exit(_ARGUMAN_ERROR);
	(*get_cub3d())->fd = check_path(argv[1]);
}
