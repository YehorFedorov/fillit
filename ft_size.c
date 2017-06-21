/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:35:15 by efedorov          #+#    #+#             */
/*   Updated: 2017/01/16 14:21:12 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_max(int numb)
{
	int		max;

	max = 15;
	while (max * max >= numb * 4)
		max--;
	return (max);
}

char	**ft_max_str(char **str, int max)
{
	int		x;
	int		y;

	y = 0;
	if (!(str = (char**)malloc(sizeof(char*) * (max + 1))))
		return (NULL);
	while (y < max)
	{
		str[y] = ft_strnew(max);
		x = 0;
		while (x < max)
		{
			str[y][x] = '.';
			x++;
		}
		str[y][x] = 0;
		y++;
	}
	str[y] = 0;
	return (str);
}
