/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:10:18 by amazurie          #+#    #+#             */
/*   Updated: 2017/08/24 11:52:13 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		get_multi(t_mdata *d)
{
	if (d->win_multi == -1)
		d->win_multi = 10;
	else if (d->map_x * d->win_multi < 600 && d->map_y * d->win_multi < 800)
		d->win_multi = 14;
	else if (d->map_x * d->win_multi > 1920 || d->map_y * d->win_multi > 1080)
		d->win_multi = 6;
	else if (d->map_x * d->win_multi > 2560 || d->map_y * d->win_multi > 1600)
		d->win_multi = 4;
	while (d->map_y * d->win_multi < 206 * 2 - 103)
		d->win_multi++;
	if (d->win_multi % 2 != 0)
		d->win_multi++;
}

static int	win_init(t_mdata *d)
{
	if (d->is_win == 1)
		return (1);
	d->is_win = 1;
	get_multi(d);
	if (!(d->win = mlx_new_window(d->mlx, d->map_x * d->win_multi + 206,
					d->map_y * d->win_multi + 6, "amazurie.filler")))
		return (0);
	if (!(d->imgb.img = mlx_new_image(d->mlx,
					d->map_x * d->win_multi + 206, d->map_y * d->win_multi + 6))
			|| !(d->imgb.ptr = mlx_get_data_addr(d->imgb.img, &(d->imgb.bpp),
					&(d->imgb.stride), &(d->imgb.endian))))
		return (0);
	if (!(d->imgf.img = mlx_new_image(d->mlx,
					d->map_x * d->win_multi, d->map_y * d->win_multi))
			|| !(d->imgf.ptr = mlx_get_data_addr(d->imgf.img, &(d->imgf.bpp),
					&(d->imgf.stride), &(d->imgf.endian))))
		return (0);
	mlx_expose_hook(d->win, up_win, d);
	mlx_key_hook(d->win, keyhook, d);
	mlx_hook(d->win, 17, (1L << 17), destroy, d);
	return (1);
}

int			game(t_mdata *d)
{
	if (!d->ended && read_map(d) == 0)
		(win_init(d) > 0) ? render(d) : 0;
	else if (!d->keep || (d->keep && d->fast_quit))
	{
		d->ended = 1;
		slow_sleep(500000000);
		up_win(d);
		(--d->cdown == 0) ? destroy(d) : 0;
		cdown(d);
	}
	else if (d->fast_quit == 1 && (d->one_count > d->two_count + 1
				|| d->two_count > d->one_count))
	{
		ft_putstr("winner determined\n");
		while (get_next_line(0, &(d->line))) ;
		destroy(d);
	}
	else if (d->keep)
		d->ended = 1;
	else
		destroy(d);
	if (!d->ended && d->slow)
		slow_sleep(100000000);
	return (0);
}

int			main(int ac, char **av)
{
	t_mdata	d;

	d.cdown = 10;
	d.ended = 0;
	d.fast_quit = 0;
	d.win_multi = 10;
	d.map_x = -1;
	d.slow = 0;
	d.one_count = -1;
	d.two_count = -1;
	d.keep = 0;
	d.is_win = 0;
	parse(&d, av, ac);
	if (!get_next_line(0, &(d.line)))
		return (1);
	while (ft_strncmp("$$$ exec", d.line, 8))
		if (!get_next_line(0, &(d.line)))
			return (1);
	if (read_map_size(&d))
		return (1);
	if (!(d.mlx = mlx_init()))
		return (0);
	mlx_loop_hook(d.mlx, game, &d);
	mlx_loop(d.mlx);
	return (0);
}
