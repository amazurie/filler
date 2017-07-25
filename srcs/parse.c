/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:04:44 by amazurie          #+#    #+#             */
/*   Updated: 2017/07/25 13:41:06 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_opt(t_data *d, char av)
{
	if (av == '-')
		return (1);
	else if (av == 's')
		d->slow = 1;
	else if (av == 'x')
		d->is_win = -1;
	else if (av == 'k')
		d->keep = -1;
	else if (av == 'd')
		d->win_multi = -1;
	else if (av == 'f')
		d->fast_quit = 1;
	else
		return (0);
	return (1);
}

void		parse(t_data *d, char **av, int ac)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][++j] && check_opt(d, av[i][j]))
			j++;
	}
}
