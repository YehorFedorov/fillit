/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:36:11 by efedorov          #+#    #+#             */
/*   Updated: 2017/01/11 14:04:43 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strncpy(char *dest, const char *src, size_t i)
{
	char	*s;

	s = dest;
	while (i > 0 && *src != '\0')
	{
		*s = *src;
		s++;
		src++;
		i--;
	}
	while (i > 0)
	{
		*s = '\0';
		s++;
		i--;
	}
	return (dest);
}
