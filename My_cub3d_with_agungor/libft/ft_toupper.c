/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:24:05 by haslan            #+#    #+#             */
/*   Updated: 2024/11/20 16:55:49 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int a)
{
	if (a >= 97 && a <= 122)
		return (a - 32);
	return (a);
}
