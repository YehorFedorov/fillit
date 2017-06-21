/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:35:34 by efedorov          #+#    #+#             */
/*   Updated: 2017/01/11 14:35:55 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (s)
	{
		new = malloc(len + 1);
		if (!new)
			return (NULL);
		i = 0;
		while (len)
		{
			new[i] = s[start + i];
			i++;
			len--;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}
