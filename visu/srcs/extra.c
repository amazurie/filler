/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:10:12 by amazurie          #+#    #+#             */
/*   Updated: 2017/08/22 15:17:48 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

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

//#include <stdio.h>
int		keyhook(int key, t_mdata *d)
{
	if (key == 53)
	{
		mlx_destroy_image(d->mlx, d->imgf.img);
		mlx_destroy_image(d->mlx, d->imgb.img);
		mlx_destroy_window(d->mlx, d->win);
		if (!d->ended)
			ft_putstr("prematurely quitted\n");
		exit(0);
	}
	else if (key == 40)
		d->keep = d->keep == 1 ? 0 : 1;
	else if (key == 1)
		d->slow = d->slow == 1 ? 0 : 1;
	else if (!d->ended && key == 3)
		d->fast_quit = d->fast_quit == 1 ? 0 : 1;
/*	int	i = -1;
	while (++i < 999)
		if (i == key)
			printf("%d\n", i);
	exit(0);
*/	return (0);
}

int		get_color(t_mdata *d, int y, int x)
{
	if (d->map[y][x] == '.')
		return (0x9F9898);
	else if (d->map[y][x] == 'O' || d->map[y][x] == 'o')
		return (0x0033A1);
	else if (d->map[y][x] == 'X' || d->map[y][x] == 'x')
		return (0xD02020);
	return (0xF000FF);
}

int		destroy(t_mdata *d)
{
	mlx_destroy_image(d->mlx, d->imgf.img);
	mlx_destroy_image(d->mlx, d->imgb.img);
	mlx_destroy_window(d->mlx, d->win);
	exit(0);
	return (0);
}

void	slow_sleep(int ns)
{
	struct timespec	req;
	struct timespec	rem;

	req.tv_sec = 0;
	req.tv_nsec = ns;
	nanosleep(&req, &rem);
}
