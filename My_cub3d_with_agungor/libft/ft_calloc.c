/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:21:43 by haslan            #+#    #+#             */
/*   Updated: 2024/09/04 20:29:14 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "../safe_allocation/s_malloc.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = s_malloc(count * size);
	return (ptr);
}
