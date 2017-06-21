/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:14:44 by efedorov          #+#    #+#             */
/*   Updated: 2017/01/16 14:21:49 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_new_coords(t_block *fig, int x, int y)
{
	int			xmin;
	int			ymin;
	int			i;

	xmin = 600;
	ymin = 600;
	i = 0;
	while (i != 4)
	{
		if (fig->x[i] < xmin)
			xmin = fig->x[i];
		if (fig->y[i] < ymin)
			ymin = fig->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		fig->x[i] = fig->x[i] - xmin + x;
		fig->y[i] = fig->y[i] - ymin + y;
		i++;
	}
}

void		ft_fig_coords(t_block *fig, char **src)
{
	int			x;
	int			y;
	int			i;

	y = 0;
	i = 0;
	while (src[y])
	{
		x = 0;
		while (src[y][x])
		{
			if (src[y][x] == '#')
			{
				fig->x[i] = x;
				fig->y[i] = y;
				i++;
			}
			if (i == 4)
				return ;
			x++;
		}
		y++;
	}
}

t_block		*ft_basic_coords(t_block *fig)
{
	t_block		*tmp;
	char		**str;

	tmp = fig;
	str = NULL;
	while (tmp->next)
	{
		str = ft_strsplit(tmp->src, '\n');
		ft_fig_coords(tmp, str);
		free(str);
		tmp = tmp->next;
	}
	return (fig);
}
