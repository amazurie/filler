/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:10:18 by amazurie          #+#    #+#             */
/*   Updated: 2017/06/29 16:53:30 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	destroy(t_data *d)
{
	mlx_destroy_image(d->mlx, d->imgf.img);
	mlx_destroy_image(d->mlx, d->imgb.img);
	mlx_destroy_window(d->mlx, d->win);
	ft_putstr("quitted unexpectedly\n");
	exit(1);
	return (1);
}

static void	set_player(t_data *d)
{
	get_next_line(0, &(d->line));
	while (ft_strncmp("$$$ exec", d->line, 8) != 0)
		get_next_line(0, &(d->line));
	if (ft_strncmp("$$$ exec p1 :", d->line, 13) == 0)
	{
		d->p_car = 'O';
		d->e_car = 'X';
	}
	else
	{
		d->p_car = 'X';
		d->e_car = 'O';
	}
	read_map_size(d);
}

void		get_multi(t_data *d)
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

static int	win_init(t_data *d)
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
	mlx_hook(d->win, 17, (1L<<17), destroy, d);
	return (1);
}

int			game(t_data *d)
{
	if (get_next_line(0, &(d->line)) > 0)
	{
		read_map(d);
		if (d->is_win != -1 && win_init(d) > 0)
			render(d);
		if (strat(d) == 0)
		{
			ft_putstr("0 0\n");
			if (d->keep == 0 && d->is_win != -1)
			{
				mlx_destroy_image(d->mlx, d->imgf.img);
				mlx_destroy_image(d->mlx, d->imgb.img);
				mlx_destroy_window(d->mlx, d->win);
			}
			(d->keep == 0) ? exit(1) : (0);
			d->e_count++;
			up_win(d);
			return (0);
		}
		ft_putnbr(d->place_y);
		ft_putchar(' ');
		ft_putnbr(d->place_x);
		ft_putchar('\n');
		d->p_count++;
		free(d->piece);
		if (d->slow == 1)
			sleep(1);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_data	d;
	char *tmp;

	d.win_multi = 10;
	d.is_win = 0;
	d.place_x = -1;
	d.place_y = -1;
	d.map_x = -1;
	d.slow = 0;
	d.keep = 0;
	d.e_count = -1;
	d.p_count = 0;
	d.e_count_save = 0;
	parse(&d, av, ac);
	if (d.is_win == -1 || !(d.mlx = mlx_init()))
		d.is_win = -1;
	set_player(&d);
	if (d.is_win == -1)
		while (1)
			game(&d);
	if (d.is_win != -1)
	{
		mlx_loop_hook(d.mlx, game, &d);
		mlx_loop(d.mlx);
	}
	return (1);
}
