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
		j = -1;
		while (av[i][++j])
		{
			if (!check_opt(d, av[i][j]))
				j = ft_strlen(av[i]);
		}
	}
}
