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
	if (d->fast_quit == 1 && d->one_count != d->two_count)
	{
		ft_putstr("winner determined\n");
		destroy(d);
	}
}

void		calc_score(t_mdata *d)
{
	int		count;
	int		y;
	int		x;

	count = 0;
	y = -1;
	while (++y < d->map_y && (x = -1))
		while (++x < d->map_x)
			if (d->map[y][x] == 'O' || d->map[y][x] == 'o')
				count++;
	if (count > d->one_count_save)
		d->one_count++;
	d->one_count_save = count;
	count = 0;
	y = -1;
	while (++y < d->map_y && (x = -1))
		while (++x < d->map_x)
			if (d->map[y][x] == 'X' || d->map[y][x] == 'x')
				count++;
	if (count > d->two_count_save)
		d->two_count++;
	d->two_count_save = count;
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
