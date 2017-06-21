/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:10:55 by efedorov          #+#    #+#             */
/*   Updated: 2017/01/19 13:05:30 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_readfile(char *file)
{
	char	buff[547];
	char	tmp[1];
	int		fd;
	int		size;
	int		i;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	if (ft_validate(fd) == 0)
		ft_error();
	close(fd);
	fd = open(file, O_RDONLY);
	while ((size = read(fd, tmp, 1)))
	{
		buff[i++] = tmp[0];
		if (i > 547)
			ft_error();
	}
	buff[i] = '\0';
	if (close(fd) == -1)
		ft_error();
	return (ft_strdup(buff));
}

t_block	*ft_str(char *arr)
{
	int		numb;
	int		j;
	char	s;
	t_block	*block;
	t_block	*tmp;

	j = 0;
	s = 64;
	numb = (ft_strlen(arr) + 1) / 21;
	if (!(block = (t_block*)malloc(sizeof(t_block))))
		return (NULL);
	tmp = block;
	while (numb-- > 0)
	{
		tmp->src = ft_strndup(&arr[j], 20);
		tmp->s = ++s;
		j += 21;
		if (!(tmp->next = (t_block*)malloc(sizeof(t_block))))
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (block);
}
