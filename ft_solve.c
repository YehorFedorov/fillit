/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:40:50 by efedorov          #+#    #+#             */
/*   Updated: 2017/01/16 14:22:51 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_reset(char **tab, t_block *fig, int max)
{
	int		x;
	int		y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tab[y][x] == fig->s)
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tab);
}

static char	**ft_save(char **tab, t_block *fig, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (fig->x[i] == x && fig->y[i] == y)
			{
				tab[y][x] = fig->s;
				i++;
			}
			x++;
		}
		tab[y][x] = 0;
		y++;
	}
	tab[y] = 0;
	return (tab);
}

static int	ft_checker(char **tab, t_block *fig, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (fig->x[i] == x && fig->y[i] == y && tab[y][x] != '.')
				return (0);
			else if (fig->x[i] == x && fig->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

static char	**ft_solve(char **tab, t_block *fig, int max)
{
	int		x;
	int		y;
	char	**str;

	if (!fig->next)
		return (tab);
	str = NULL;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			ft_new_coords(fig, x, y);
			if (ft_checker(tab, fig, max))
				str = ft_solve(ft_save(tab, fig, max), fig->next, max);
			if (str)
				return (str);
			tab = ft_reset(tab, fig, max);
			x++;
		}
		y++;
	}
	return (0);
}

char		**ft_final(t_block *fig, int max)
{
	char	**tab;

	tab = NULL;
	while (!tab)
	{
		tab = ft_max_str(tab, max);
		tab = ft_solve(tab, fig, max);
		max++;
	}
	return (tab);
}
