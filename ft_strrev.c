/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:35:50 by efedorov          #+#    #+#             */
/*   Updated: 2017/01/11 14:04:30 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strrev(char *str)
{
	int		size;
	char	*dst;
	int		i;

	i = 0;
	dst = (char*)malloc(sizeof(*dst) * ft_strlen(str) + 1);
	size = ft_strlen(str);
	while (size > 0)
	{
		dst[i] = str[size - 1];
		i++;
		size--;
	}
	dst[i] = '\0';
	return (dst);
}
