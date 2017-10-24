/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:05:09 by amazurie          #+#    #+#             */
/*   Updated: 2017/07/25 11:05:55 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	pixel_put(t_data *d, int y, int x, int color)
{
	int	size;
	int	pos;

	size = (d->map_y * d->win_multi - 1) * d->imgf.stride
		+ d->map_x * d->win_multi * d->imgf.bpp / 8;
	pos = y * d->imgf.stride + x * d->imgf.bpp / 8;
	if (pos <= 0 || pos + 2 >= size || x < 0
			|| (x * d->imgf.bpp / 8) >= d->imgf.stride)
		return ;
	if (d->imgf.endian)
	{
		d->imgf.ptr[++pos] = (color >> 16) & 0xFF;
		d->imgf.ptr[++pos] = (color >> 8) & 0xFF;
		d->imgf.ptr[pos] = (color) & 0xFF;
		return ;
	}
	d->imgf.ptr[pos] = (color) & 0xFF;
	d->imgf.ptr[++pos] = (color >> 8) & 0xFF;
	d->imgf.ptr[++pos] = (color >> 16) & 0xFF;
}

static void	set_square(t_data *d, int y, int x)
{
	int		starty;
	int		startx;
	int		endy;
	int		endx;

	starty = y * d->win_multi - 1;
	endx = x * d->win_multi + d->win_multi;
	endy = starty + d->win_multi;
	while (++starty < endy)
	{
		startx = endx - d->win_multi - 1;
		while (++startx < endx)
			pixel_put(d, starty, startx, get_color(d, y, x));
	}
}

void		reset_img(t_data *d)
{
	int		pos;
	int		y;
	int		x;

	y = -1;
	while (++y < d->map_y)
	{
		x = -1;
		while (++x < d->map_x)
		{
			pos = y * d->imgf.stride + x * d->imgf.bpp / 8;
			d->imgf.ptr[pos] = 0;
			d->imgf.ptr[++pos] = 0;
			d->imgf.ptr[++pos] = 0;
		}
	}
}

void		render(t_data *d)
{
	int		x;
	int		y;

	reset_img(d);
	render_back(d);
	y = -1;
	while (++y < d->map_y)
	{
		x = -1;
		while (++x < d->map_x)
			set_square(d, y, x);
	}
	mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, d->imgb.img, 0, 0);
	mlx_put_image_to_window(d->mlx, d->win, d->imgf.img, 3, 3);
	render_score(d);
}

int			up_win(t_data *d)
{
	mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, d->imgb.img, 0, 0);
	mlx_put_image_to_window(d->mlx, d->win, d->imgf.img, 3, 3);
	render_score(d);
	return (1);
}
