/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:27:40 by efedorov          #+#    #+#             */
/*   Updated: 2017/01/19 10:34:34 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(0);
}

int		ft_lstlen(t_block *fig)
{
	t_block	*tmp;
	int		i;

	i = 0;
	tmp = fig;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	char	*read;
	t_block	*fig;
	char	**res;
	int		i;

	if (argc != 2)
		ft_error();
	read = ft_readfile(argv[1]);
	fig = ft_str(read);
	i = ft_lstlen(fig);
	fig = ft_basic_coords(fig);
	res = ft_final(fig, ft_max(i));
	free(fig);
	while (*res)
		ft_putendl(*res++);
	return (0);
}
