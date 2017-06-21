/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:28:43 by efedorov          #+#    #+#             */
/*   Updated: 2017/06/21 11:12:10 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_symb(char *str)
{
	while (*str)
	{
		if (*str == '.' || *str == '#' || *str == '\n')
			str++;
		else
			return (0);
	}
	return (1);
}

int		ft_check_len(int len)
{
	if (len > 547)
		return (0);
	if (((len + 1) % 21) != 0)
		return (0);
	return (1);
}

int		ft_check_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i - 1] == '\n' && str[i] == '\n' && str[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_size(char *str)
{
	int	i;
	int	n;
	int	empty;

	i = 0;
	n = 0;
	empty = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			empty++;
		else
			n++;
		if (n == 5 && empty != 16)
			return (0);
		if (n == 4 && empty == 12)
			return (0);
		if (n == 5 && empty == 16)
		{
			n = 0;
			empty = 0;
		}
		i++;
	}
	return (1);
}

int		ft_check(const char *str)
{
	if (str[0] == '\n')
		return (0);
	if (!(ft_check_n((char*)str)))
		return (0);
	if (!(ft_check_symb((char*)str)))
		return (0);
	if (!(ft_check_len(ft_strlen(str))))
		return (0);
	if (!(ft_check_size((char*)str)))
		return (0);
	return (1);
}
