/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:35:04 by agungor           #+#    #+#             */
/*   Updated: 2024/09/02 18:21:24 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error_message.h"
#include "../libft/libft.h"
#include "../safe_allocation/s_malloc.h"

static int	basic_pow(int base, unsigned int exponential)
{
	int	result;

	result = 1;
	if (!exponential && base)
		return (result);
	while (exponential--)
		result *= base;
	return (result);
}

static void	colour_settings(int red, int green, int blue)
{
	char	*colour_text;
	int		i;

	colour_text = ft_strdup(COLOUR_STR);
	if (!colour_text)
		return ;
	i = 2;
	while (i > -1)
	{
		colour_text[9 - i] = ((red / basic_pow(10, i)) % 10) + 48;
		colour_text[13 - i] = ((green / basic_pow(10, i)) % 10) + 48;
		colour_text[17 - i] = ((blue / basic_pow(10, i)) % 10) + 48;
		i--;
	}
	write(1, colour_text, 19);
	which_directions_search(colour_text, TAIL_TO_HEAD);
}

static void	terminal_message(char *s, int loop_count, int sleep_time,
		t_colour rgb)
{
	int	i;
	int	j;

	i = -1;
	while (++i < loop_count)
	{
		write(1, "\033[2J\033[H", 7);
		j = 0;
		while (j++ < i)
			write(1, "*", 1);
		write(1, "\n|", 2);
		colour_settings(rgb.red, rgb.green, rgb.blue);
		if (i + 1 != loop_count)
			write(1, s, i);
		else
			write(1, s, i - 1);
		write(1, "\033[0m", 4);
		write(1, "|\n", 2);
		j = 0;
		while (j++ < i)
			write(1, "*", 1);
		write(1, "\n", 1);
		usleep(sleep_time);
	}
	which_directions_search(s, TAIL_TO_HEAD);
}

void	string_check(char *s, int loop_count, int sleep_time, t_colour rgb)
{
	int	i;

	i = 1;
	if (!s)
	{
		loop_count = 79;
		while (i <= loop_count)
		{
			write(1, "\033[2J\033[H", 7);
			write(1, MALLOC_ERROR, i++);
			usleep(sleep_time);
		}
		write(1, "\n", 1);
	}
	else
		terminal_message(s, loop_count, sleep_time, rgb);
}
