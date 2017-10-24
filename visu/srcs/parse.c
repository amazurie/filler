/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:04:44 by amazurie          #+#    #+#             */
/*   Updated: 2017/08/22 12:02:13 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int	check_opt(t_mdata *d, char av)
{
	if (av == '-')
		return (1);
	else if (av == 's')
		d->slow = 1;
	else if (av == 'x')
		d->is_win = 0;
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

void		parse(t_mdata *d, char **av, int ac)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (av[i][0] == '-')
		{
			while (av[i][j] && check_opt(d, av[i][j]))
				j++;
		}
	}
}
