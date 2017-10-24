/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:05:26 by amazurie          #+#    #+#             */
/*   Updated: 2017/08/24 11:59:46 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		fast_exit(t_mdata *d)
{
	if (d)
		;
/*	if (d->is_win != -1 && d->fast_quit == 1 && d->p_count > d->e_count + 1)
	{
		mlx_destroy_image(d->mlx, d->imgf.img);
		mlx_destroy_image(d->mlx, d->imgb.img);
		mlx_destroy_window(d->mlx, d->win);
		ft_putstr("winner determined\n");
		exit(1);
	}
	else if (d->is_win == -1)
		calc_score(d);
	if (d->is_win == -1 && d->fast_quit == 1 && d->p_count > d->one_count + 1)
		ft_putstr("winner determined\n");
	if (d->is_win == -1 && d->fast_quit == 1 && d->p_count > d->e_count + 1)
		exit(1);
*/}

void		calc_score(t_mdata *d)
{
	int		y;
	int		x;

	d->one_count = 0;
	y = -1;
	while (++y < d->map_y)
	{
		x = -1;
		while (++x < d->map_x)
			if (d->map[y][x] == 'O' || d->map[y][x] == 'o')
				d->one_count++;
	}
	d->two_count = 0;
	y = -1;
	while (++y < d->map_y)
	{
		x = -1;
		while (++x < d->map_x)
			if (d->map[y][x] == 'X' || d->map[y][x] == 'x')
				d->two_count++;
	}
}

static void	avantage(t_mdata *d)
{
	if (d->one_count > d->two_count)
	{
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 70,
			((d->map_y * d->win_multi + 6) / 2 +
			(d->map_y * d->win_multi + 6) / 4 / 2), 0x000287, "VICTORY");
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 66,
			((d->map_y * d->win_multi + 6) / 2 +
			(d->map_y * d->win_multi + 6) / 4 / 2) + 20, 0x000287, "JOUEUR 1");
	}
	else if (d->two_count < d->one_count)
	{
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 70,
			((d->map_y * d->win_multi + 6) / 2 +
			(d->map_y * d->win_multi + 6) / 4 / 2), 0x870000, "VICTORY");
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 66,
			((d->map_y * d->win_multi + 6) / 2 +
			(d->map_y * d->win_multi + 6) / 4 / 2) + 20, 0x870000, "JOUEUR 2");
	}
}


void		render_score(t_mdata *d)
{
	char	*tmp;

	calc_score(d);
	mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 16,
			(d->map_y * d->win_multi + 6) / 2 / 4 - 13, 0x000287, "JOUEUR 1:");
	if ((tmp = ft_itoa(d->one_count)) != NULL)
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 16,
			(d->map_y * d->win_multi + 6) / 2 / 4 + 7, 0x0002B8, tmp);
	free(tmp);
	mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 16,
			(d->map_y * d->win_multi + 6) / 2 / 2 + 7, 0x870000, "JOUEUR 2:");
	if ((tmp = ft_itoa(d->two_count)) != NULL)
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 16,
			(d->map_y * d->win_multi + 6) / 2 / 2 + 27, 0xb80000, tmp);
	free(tmp);
	if (d->one_count != d->two_count)
		avantage(d);
	if (d->one_count != d->two_count)
		return ;
}
