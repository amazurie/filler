/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:06:58 by amazurie          #+#    #+#             */
/*   Updated: 2017/06/29 16:37:09 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
				if (d->map[y + i][x + j] != '.'
						&& d->map[y + i][x + j] != d->p_car
						&& d->map[y + i][x + j] != d->p_car + 32)
					return (0);
				if (d->map[y + i][x + j] == d->p_car
						|| d->map[y + i][x + j] == d->p_car + 32)
				{
					over++;
					if (over > 1)
						return (0);
				}
			}
			else if (y + i >= d->map_y || x + j >= d->map_x
					|| d->piece[i][j] == '*')
				return (0);
		}
	}
	if (over == 0)
		return (0);
	return (1);
}
