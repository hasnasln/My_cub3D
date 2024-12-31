/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:23:35 by haslan            #+#    #+#             */
/*   Updated: 2024/11/20 16:55:59 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../safe_allocation/s_malloc.h"
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strj;
	char	*strj2;

	strj = (char *)s_malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	strj2 = strj;
	while (*s1)
	{
		*strj = *s1;
		strj++;
		s1++;
	}
	while (*s2)
	{
		*strj = *s2;
		strj++;
		s2++;
	}
	*strj = '\0';
	return (strj2);
}
