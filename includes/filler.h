/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:53:03 by amazurie          #+#    #+#             */
/*   Updated: 2017/07/25 11:09:46 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct		s_img
{
	void			*img;
	char			*ptr;
	int				bpp;
	int				stride;
	int				endian;
}					t_img;

typedef struct		s_data
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
}					t_data;

void				read_map_size(t_data *d);
void				read_map(t_data *d);
void				read_piece(t_data *d);
int					strat(t_data *d);
int					place_piece(t_data *d, int y, int x);
void				free_tabl(char **tabl);
void				render(t_data *d);
int					up_win(t_data *d);
void				parse(t_data *d, char **av, int ac);
int					keyhook(int	key, t_data *d);
int					get_color(t_data *d, int y, int x);
void				render_back(t_data *d);
void				render_score(t_data *d);
int					destroy(t_data *d);

#endif
