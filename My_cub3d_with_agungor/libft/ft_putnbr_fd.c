/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:23:19 by haslan            #+#    #+#             */
/*   Updated: 2023/10/22 15:02:58 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	nstep(unsigned int number)
{
	unsigned int	s;

	if (number >= 1000000000)
		return (1000000000);
	s = 1;
	while (s * 10 <= number)
		s = s * 10;
	return (s);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		pnbr;
	int		nbr_step;
	char	c;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			pnbr = n * (-1);
		}
		else
			pnbr = n;
		nbr_step = nstep(pnbr);
		while (nbr_step > 0)
		{
			c = (pnbr / nbr_step) + 48;
			ft_putchar_fd(c, fd);
			pnbr = pnbr - ((pnbr / nbr_step) * nbr_step);
			nbr_step = nbr_step / 10;
		}
	}
}
