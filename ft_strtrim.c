/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:09:20 by efedorov          #+#    #+#             */
/*   Updated: 2017/01/11 14:47:10 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	if (s)
	{
		if (!*s)
			return (ft_strnew(1));
		i = 0;
		j = ft_strlen(s) - 1;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '.')
			&& i < j + 1)
			i++;
		while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == '.')
			&& &s[j] != s)
			j--;
		if (i >= j || i == ft_strlen(s))
			return (ft_strnew(1));
		if ((new = ft_strnew(j - i + 1)))
		{
			ft_strncpy(new, s + i, j - i + 1);
			return (new);
		}
	}
	return (NULL);
}
