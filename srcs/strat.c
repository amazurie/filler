/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:07:12 by amazurie          #+#    #+#             */
/*   Updated: 2017/07/25 15:30:49 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_close(t_data *d, int y, int x, int top)
{
	int		xy[2];
	int		dist;
	int		test;
	int		tmp;

	xy[0] = -1;
	dist = -1;
	test = 0;
	while (++xy[0] < d->piece_y && (xy[1] = -1) == -1)
	{
		while (++xy[1] < d->piece_x)
		{
			if (d->piece[xy[0]][xy[1]] == '*')
			{
				tmp = y - (d->test_y + xy[0]);
				test = (tmp < 0) ? -tmp : tmp;
				tmp = x - (d->test_x + xy[1]);
				test += (tmp < 0) ? -tmp : tmp;
				(test < dist || dist == -1) ? dist = test : (0);
				if (dist > top)
					return (dist);
			}
		}
	}
	return (dist);
}

static int	check_espot(t_data *d, int y, int x)
{
	if (d->p_count < 15 && (d->map_x * d->map_y > 5000
			|| d->map_x * d->map_y < 400))
		return (1);
	if ((d->map[y][x] == d->e_car || d->map[y][x] == d->e_car + 32)
		&& ((y < d->map_y || (d->map[y + 1] &&
		(d->map[y + 1][x] != d->e_car && d->map[y + 1][x] != d->e_car + 32)))
		|| (y > 0 || (d->map[y - 1] &&
		(d->map[y - 1][x] != d->e_car && d->map[y - 1][x] != d->e_car + 32)))
		|| (x < d->map_x || (d->map[y][x + 1] &&
		(d->map[y][x + 1] != d->e_car && d->map[y][x + 1] != d->e_car + 32)))
		|| (x > 0 || (d->map[y][x - 1] &&
		(d->map[y][x - 1] != d->e_car && d->map[y][x - 1] != d->e_car + 32)))))
		return (1);
	return (0);
}

static int	test_best(t_data *d)
{
	int		xy[2];
	int		test;
	int		top;

	top = d->map_x + d->map_y;
	xy[0] = -1;
	while (++xy[0] < d->map_y)
	{
		xy[1] = -1;
		while (++xy[1] < d->map_x)
		{
			if (check_espot(d, xy[0], xy[1])
				&& ((test = check_close(d, xy[0], xy[1], top)) < top))
				top = test;
			if (d->p_count < 15 && d->map_x * d->map_y > 5000
					&& xy[0] == d->map_y / 2 + d->map_y / 4)
				return (test);
			if (d->p_count < 15 && d->map_x * d->map_y < 400
					&& xy[1] == d->map_x / 2 + d->map_x / 4)
				return (test);
		}
	}
	return (top);
}

int			strat(t_data *d)
{
	int		test;
	int		top;

	d->place_y = -100;
	d->place_y = -100;
	top = d->map_x + d->map_y;
	d->test_y = -d->piece_y - 1;
	while (++d->test_y < d->map_y)
	{
		d->test_x = -d->piece_x - 1;
		while (++d->test_x < d->map_x)
		{
			if (place_piece(d, d->test_y, d->test_x)
				&& (test = test_best(d)) < top)
			{
				top = test;
				d->place_y = d->test_y;
				d->place_x = d->test_x;
			}
		}
	}
	if (d->place_y == -100 || d->place_x == -100)
		return (0);
	return (1);
}
