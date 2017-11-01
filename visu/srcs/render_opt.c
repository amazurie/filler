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

void		render_opt(t_mdata *d)
{
	mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 8,
			(d->map_y * d->win_multi + 6) / 2,
			(d->fast_quit ? 0x00CC00 : 0xFFFFFF), "WINQUIT");
	mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 8,
			(d->map_y * d->win_multi + 6) / 2 + 24,
			(d->slow ? 0x00CC00 : 0xFFFFFF), "SLOW");
	mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 8,
			(d->map_y * d->win_multi + 6) / 2 + 48,
			(d->keep ? 0x00CC00 : 0xFFFFFF), "KEEP");
}
