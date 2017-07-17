#include "filler.h"

static void	calc_score(t_data *d)
{
	int		e_count;
	int		y;
	int		x;

	e_count = 0;
	y = -1;
	while (++y < d->map_y)
	{
		x = -1;
		while (++x < d->map_x)
		{
			if (d->map[y][x] == d->e_car || d->map[y][x] == d->e_car + 32)
				e_count++;
		}
	}
	if (e_count > d->e_count_save)
		d->e_count++;
	d->e_count_save = e_count;
}

static void	avantage(t_data *d)
{
	if (d->p_count > d->e_count)
	{
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 66,
			((d->map_y * d->win_multi + 6) / 2 +
			(d->map_y * d->win_multi + 6) / 4 / 2), 0x000287, "AVANTAGE");
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 96,
			((d->map_y * d->win_multi + 6) / 2 +
			(d->map_y * d->win_multi + 6) / 4 / 2) + 20, 0x000287, "ME");
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 66,
			((d->map_y * d->win_multi + 6) / 2 +
			(d->map_y * d->win_multi + 6) / 4 / 2) + 50, 0x000287, "MEURT!!!");
	}
	else if (d->p_count < d->e_count)
	{
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 66,
			((d->map_y * d->win_multi + 6) / 2 +
			(d->map_y * d->win_multi + 6) / 4 / 2), 0x870000, "AVANTAGE");
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 76,
			((d->map_y * d->win_multi + 6) / 2 +
			(d->map_y * d->win_multi + 6) / 4 / 2) + 20, 0x870000, "ENNEMY");
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 56,
			((d->map_y * d->win_multi + 6) / 2 + (d->map_y * d->win_multi + 6)
			 / 4 / 2) + 50, 0x000287, "NOOOOOOON!");
	}
}

void		render_score(t_data *d)
{
	char	*tmp;

	calc_score(d);
	mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 16,
			(d->map_y * d->win_multi + 6) / 2 / 4 - 13, 0x000287, "ME:");
	if ((tmp = ft_itoa(d->p_count)) != NULL)
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 16,
				(d->map_y * d->win_multi + 6) / 2 / 4 + 7, 0x0002B8, tmp);
	free(tmp);
	mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 16,
			(d->map_y * d->win_multi + 6) / 2 / 2 + 7, 0x870000, "ENNEMY:");
	if ((tmp = ft_itoa(d->e_count)) != NULL)
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 16,
				(d->map_y * d->win_multi + 6) / 2 / 2 + 27, 0xb80000, tmp);
	free(tmp);
	if (d->p_count == d->e_count)
	{
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 71,
			((d->map_y * d->win_multi + 6) / 2 +
			(d->map_y * d->win_multi + 6) / 4 / 2), 0x870000, "EGALITE");
		mlx_string_put(d->mlx, d->win, d->map_x * d->win_multi + 31,
			((d->map_y * d->win_multi + 6) / 2 + (d->map_y * d->win_multi + 6)
			 / 4 / 2) + 50, 0x000287, "CA VA CHAUFFER!");
	}
	else
		avantage(d);
}
