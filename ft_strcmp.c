/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:50:45 by efedorov          #+#    #+#             */
/*   Updated: 2017/01/11 14:03:08 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_strcmp(char *s1, char *s2)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char*)s1;
	src = (unsigned char*)s2;
	while (*dest == *src && *dest != '\0' && *src != '\0')
	{
		dest++;
		src++;
	}
	return (*dest - *src);
}
