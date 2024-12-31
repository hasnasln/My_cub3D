/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:23:48 by haslan            #+#    #+#             */
/*   Updated: 2023/10/22 15:31:31 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (src[0] == '\0')
		return ((char *)dest);
	while (dest[++i] != '\0' && i < n)
	{
		if (dest[i] == src[0])
		{
			j = 0;
			while (dest[i + j] == src[j] && i + j < n)
			{
				if (src[j + 1] == '\0')
					return ((char *)dest + i);
				j++;
			}
		}
	}
	return ((void *)0);
}
