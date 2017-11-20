/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:53:03 by amazurie          #+#    #+#             */
/*   Updated: 2017/11/20 15:04:18 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

typedef struct		s_data
{
	char			*line;
	char			**map;
	int				map_x;
	int				map_y;
	char			**piece;
	char			p_car;
	char			e_car;
	int				piece_x;
	int				piece_y;
	int				place_x;
	int				place_y;
	int				test_y;
	int				test_x;
	int				p_count;
	int				e_count;
}					t_data;

void				read_map_size(t_data *d);
void				read_map(t_data *d);
void				read_piece(t_data *d);
int					strat(t_data *d);
int					place_piece(t_data *d, int y, int x);
void				parse(t_data *d, char **av, int ac);
int					put_coord(t_data *d);
void				free_tabl(char **tabl);

#endif
