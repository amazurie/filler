/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:10:44 by amazurie          #+#    #+#             */
/*   Updated: 2017/11/21 13:17:04 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			read_map_size(t_mdata *d)
{
	char	**tmp;
	int		i;

	while (ft_strncmp(d->line, "Plateau", 7) != 0)
		if (get_next_line(0, &(d->line)) <= 0)
			return (1);
	tmp = ft_strsplit(d->line, ' ');
	d->map_y = ft_atoi(tmp[1]);
	d->map_x = ft_atoi(tmp[2]);
	d->map = (char **)ft_memalloc(sizeof(char *) * (d->map_y + 1));
	i = 0;
	while (i < d->map_y)
		d->map[i++] = (char *)ft_memalloc(d->map_x + 1);
	d->map[i] = NULL;
	free_tabl(tmp);
	return (0);
}

int			skip_piece(t_mdata *d)
{
	char	**tmp;
	int		i;
	int		j;

	while (ft_strncmp("Piece", d->line, 5) != 0)
		if (get_next_line(0, &(d->line)) <= 0)
			return (1);
	tmp = ft_strsplit(d->line, ' ');
	j = ft_atoi(tmp[1]);
	free_tabl(tmp);
	i = 0;
	while (i++ < j)
		if (get_next_line(0, &(d->line)) <= 0)
			return (1);
	return (0);
}

int			read_map(t_mdata *d)
{
	int		i;
	int		j;
	int		k;

	while (ft_strncmp(d->line, "Plateau", 7))
		if (get_next_line(0, &(d->line)) <= 0)
			return (1);
	if (get_next_line(0, &(d->line)) <= 0)
		return (1);
	i = -1;
	while (++i < d->map_y)
	{
		if (get_next_line(0, &(d->line)) <= 0)
			return (1);
		k = ft_strlen_chr(d->line, ' ') + 1;
		j = -1;
		while (++j < d->map_x)
			d->map[i][j] = d->line[j + k];
	}
	return (skip_piece(d));
}
