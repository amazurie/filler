/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:53:03 by amazurie          #+#    #+#             */
/*   Updated: 2017/08/24 11:52:36 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <time.h>

typedef struct		s_img
{
	void			*img;
	char			*ptr;
	int				bpp;
	int				stride;
	int				endian;
}					t_img;

typedef struct		s_mdata
{
	void			*mlx;
	void			*win;
	struct s_img	imgb;
	struct s_img	imgf;
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
	int				is_win;
	int				slow;
	int				keep;
	int				win_multi;
	int				img_back;
	int				p_count;
	int				e_count;
	int				e_count_save;
	int				fast_quit;
}					t_mdata;

void				read_map_size(t_mdata *d);
void				read_map(t_mdata *d);
void				read_piece(t_mdata *d);
int					strat(t_mdata *d);
int					place_piece(t_mdata *d, int y, int x);
void				free_tabl(char **tabl);
void				render(t_mdata *d);
int					up_win(t_mdata *d);
void				parse(t_mdata *d, char **av, int ac);
int					keyhook(int	key, t_mdata *d);
int					get_color(t_mdata *d, int y, int x);
void				render_back(t_mdata *d);
void				render_score(t_mdata *d);
int					destroy(t_mdata *d);
int					put_coord(t_mdata *d);
void				slow_sleep(void);
void				calc_score(t_mdata *d);
void				fast_exit(t_mdata *d);

#endif
