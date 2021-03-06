/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:06:58 by amazurie          #+#    #+#             */
/*   Updated: 2017/08/24 11:19:56 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			put_coord(t_data *d)
{
	if (strat(d) == 0)
	{
		ft_putstr("0 0\n");
		exit(1);
		return (0);
	}
	ft_putnbr(d->place_y);
	ft_putchar(' ');
	ft_putnbr(d->place_x);
	ft_putchar('\n');
	free(d->piece);
	return (1);
}

static int	test_pos(t_data *d, int y, int x, int *over)
{
	if (d->map[y][x] != '.'
			&& d->map[y][x] != d->p_car
			&& d->map[y][x] != d->p_car + 32)
		return (0);
	if (d->map[y][x] == d->p_car
			|| d->map[y][x] == d->p_car + 32)
	{
		(*over)++;
		if (*over > 1)
			return (0);
	}
	return (1);
}

int			place_piece(t_data *d, int y, int x)
{
	int	over;
	int	i;
	int	j;

	i = -1;
	over = 0;
	while (++i < d->piece_y)
	{
		j = -1;
		while (++j < d->piece_x)
		{
			if (y + i >= 0 && x + j >= 0 && y + i < d->map_y
					&& x + j < d->map_x && d->piece[i][j] == '*')
			{
				if (!test_pos(d, y + i, x + j, &over))
					return (0);
			}
			else if (d->piece[i][j] == '*')
				return (0);
		}
	}
	if (over == 0)
		return (0);
	return (1);
}
