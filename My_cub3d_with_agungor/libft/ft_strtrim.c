/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:23:53 by haslan            #+#    #+#             */
/*   Updated: 2024/09/04 20:16:19 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "../safe_allocation/s_malloc.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*result;

	while (*s1 && (ft_strchr(set, *s1) != 0))
		s1++;
	len = ft_strlen(s1);
	while (len && s1[len - 1] && (ft_strchr(set, s1[len - 1]) != 0))
		len--;
	result = (char *)s_malloc(sizeof(char) * (len + 1));
	ft_memcpy(result, s1, len);
	result[len] = '\0';
	return (result);
}
