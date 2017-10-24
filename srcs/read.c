/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:10:44 by amazurie          #+#    #+#             */
/*   Updated: 2017/07/25 11:52:45 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		read_map_size(t_data *d)
{
	char	**tmp;
	int		i;

	while (ft_strncmp(d->line, "Plateau", 7) != 0)
		get_next_line(0, &(d->line));
	tmp = ft_strsplit(d->line, ' ');
	d->map_y = ft_atoi(tmp[1]);
	d->map_x = ft_atoi(tmp[2]);
	d->map = (char **)ft_memalloc(sizeof(char *) * (d->map_y + 1));
	i = 0;
	while (i < d->map_y)
		d->map[i++] = (char *)ft_memalloc(d->map_x + 1);
	d->map[i] = NULL;
	free_tabl(tmp);
}

void		read_piece(t_data *d)
{
	char	**tmp;
	int		i;

	while (ft_strncmp("Piece", d->line, 5) != 0)
		get_next_line(0, &(d->line));
	tmp = ft_strsplit(d->line, ' ');
	d->piece_y = ft_atoi(tmp[1]);
	d->piece_x = ft_atoi(tmp[2]);
	free_tabl(tmp);
	d->piece = (char **)ft_memalloc(sizeof(char *) * (d->piece_y + 1));
	i = 0;
	while (i < d->piece_y)
	{
		get_next_line(0, &(d->line));
		d->piece[i] = ft_strdup(d->line);
		i++;
	}
}

void		read_map(t_data *d)
{
	int		i;
	int		j;
	int		k;

	if (ft_strncmp(d->line, "Plateau", 7) == 0)
		get_next_line(0, &(d->line));
	i = -1;
	while (++i < d->map_y)
	{
		get_next_line(0, &(d->line));
		k = ft_strlen_chr(d->line, ' ') + 1;
		j = -1;
		while (++j < d->map_x)
			d->map[i][j] = d->line[j + k];
	}
	read_piece(d);
}
