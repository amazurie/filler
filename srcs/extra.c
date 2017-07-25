/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:10:12 by amazurie          #+#    #+#             */
/*   Updated: 2017/07/25 11:24:57 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_tabl(char **tab)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		keyhook(int key, t_data *d)
{
	if (key == 53)
	{
		mlx_destroy_image(d->mlx, d->imgf.img);
		mlx_destroy_image(d->mlx, d->imgb.img);
		mlx_destroy_window(d->mlx, d->win);
		ft_putstr("prematurely quitted\n");
		exit(1);
	}
	return (1);
}

int		get_color(t_data *d, int y, int x)
{
	if (d->map[y][x] == '.')
		return (0x9F9898);
	else if (d->p_car == 'X' && (d->map[y][x] == 'X' || d->map[y][x] == 'x'))
		return (0x0033A1);
	else if (d->p_car == 'O' && (d->map[y][x] == 'O' || d->map[y][x] == 'o'))
		return (0x0033A1);
	else if (d->p_car != 'X' && (d->map[y][x] == 'X' || d->map[y][x] == 'x'))
		return (0xD02020);
	else if (d->p_car != 'O' && (d->map[y][x] == 'O' || d->map[y][x] == 'o'))
		return (0xD02020);
	return (0xF000FF);
}

int		destroy(t_data *d)
{
	mlx_destroy_image(d->mlx, d->imgf.img);
	mlx_destroy_image(d->mlx, d->imgb.img);
	mlx_destroy_window(d->mlx, d->win);
	ft_putstr("quitted unexpectedly\n");
	exit(1);
	return (1);
}

int		put_coord(t_data *d)
{
	if (strat(d) == 0)
	{
		ft_putstr("0, 0\n");
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
	return (1);
}
