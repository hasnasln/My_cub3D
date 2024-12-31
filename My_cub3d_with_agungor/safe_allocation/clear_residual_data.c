/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_residual_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:47:39 by agungor           #+#    #+#             */
/*   Updated: 2024/11/20 16:48:09 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	clear_residual_data(void *ptr, size_t __size)
{
	size_t	i;

	i = -1;
	while (++i < __size)
		((char *)ptr)[i] = 0;
}
