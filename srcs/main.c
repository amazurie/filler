/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:10:18 by amazurie          #+#    #+#             */
/*   Updated: 2017/11/06 02:46:27 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_tabl(char **tab)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
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

int			main(void)
{
	t_data	d;

	d.map_x = -1;
	d.p_count = 0;
	d.place_x = -1;
	d.place_y = -1;
	set_player(&d);
	while (get_next_line(0, &(d.line)) > 0)
	{
		read_map(&d);
		if (!put_coord(&d))
			return (0);
		d.p_count++;
	}
	return (0);
}
