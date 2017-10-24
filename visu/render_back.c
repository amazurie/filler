/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:05:15 by amazurie          #+#    #+#             */
/*   Updated: 2017/07/25 11:10:50 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	pixel_put(t_data *d, int y, int x, int color)
{
	int	size;
	int	pos;

	size = (d->map_y * d->win_multi + 6 - 1) * d->imgb.stride
		+ (d->map_x * d->win_multi + 206) * d->imgb.bpp / 8;
	pos = y * d->imgb.stride + x * d->imgb.bpp / 8;
	if (pos <= 0 || pos + 2 >= size || x < 0
			|| (x * d->imgb.bpp / 8) >= d->imgb.stride)
		return ;
	if (d->imgb.endian)
	{
		d->imgb.ptr[++pos] = (color >> 16) & 0xFF;
		d->imgb.ptr[++pos] = (color >> 8) & 0xFF;
		d->imgb.ptr[pos] = (color) & 0xFF;
		return ;
	}
	d->imgb.ptr[pos] = (color) & 0xFF;
	d->imgb.ptr[++pos] = (color >> 8) & 0xFF;
	d->imgb.ptr[++pos] = (color >> 16) & 0xFF;
}

void		render_back(t_data *d)
{
	int		y;
	int		x;

	y = -1;
	while (++y < d->map_y * d->win_multi + 6)
	{
		x = -1;
		while (++x < d->map_x * d->win_multi + 6)
			pixel_put(d, y, x, 0x404040);
	}
	y = -1;
	while (++y < d->map_y * d->win_multi + 6)
	{
		x = d->map_x * d->win_multi + 6 - 1;
		while (++x < d->map_x * d->win_multi + 206)
			pixel_put(d, y, x, 0x656565);
	}
	y = (d->map_y * d->win_multi + 6) / 2 - 2;
	while (++y < (d->map_y * d->win_multi + 6) / 2 + 2)
	{
		x = d->map_x * d->win_multi - 1;
		while (++x < d->map_x * d->win_multi + 206)
			pixel_put(d, y, x, 0x404040);
	}
}
